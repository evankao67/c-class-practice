#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
int arr[205][205];
int dir[5] = {0, 1, 0, -1, 0};
int counter = 1,Max=0;
int n, m,ansi,ansj,desx,desy,finalx,finaly;
struct node{
    int x,y;
    int step;
};
typedef struct node Node;
struct recode{
    int x,y;
}pre[205][205];
queue<Node> q;
int bfs(int i,int j)
{
    while(!q.empty())
        q.pop();
    Node first;
    first.x=i;
    first.y=j;
    first.step=1;
    q.push(first);
    while(1)
    {
        for(int l=0;l<4;l++)
        {
            int X=q.front().x+dir[l],Y=q.front().y+dir[l+1];
            if(X<0||Y<0||X>=n||Y>=m)
                continue;
            Node to;
            if(arr[X][Y]>arr[q.front().x][q.front().y])
            {
                to.x=X;
                to.y=Y;
                to.step=q.front().step+1;
                q.push(to);
            }
        }
        if(q.size()==1)
        {
            desx=q.front().x;
            desy=q.front().y;
            return q.front().step;
        }
        else
            q.pop();
    }
}
void finalBFS(int i, int j)
{
    while(!q.empty())
        q.pop();
    Node first;
    first.x=i;
    first.y=j;
    first.step=1;
    q.push(first);
    pre[i][j].x=i;
    pre[i][j].y=j;
    while(1)
    {
        for(int l=0;l<4;l++)
        {
            int X=q.front().x+dir[l],Y=q.front().y+dir[l+1];
            if(X<0||Y<0||X>=n||Y>=m)
                continue;
            Node to;
            if(arr[X][Y]>arr[q.front().x][q.front().y])
            {
                to.x=X;
                to.y=Y;
                to.step=q.front().step+1;
                q.push(to);
                pre[to.x][to.y].x=q.front().x;
                pre[to.x][to.y].y=q.front().y;
            }
        }
        if(q.size()==1)
        {
            break;
        }
        else
            q.pop();
    }
}
void printpath(int x,int y)
{
    if(pre[x][y].x!=x||pre[x][y].y!=y)
    {
        printpath(pre[x][y].x,pre[x][y].y);
        cout<<pre[x][y].x<<' '<<pre[x][y].y<<endl;
    }
    
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int flag=1;
            for (int k = 0; k < 4; k++)
            {
                int x = i + dir[k], y = j + dir[k + 1];
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                if(arr[x][y]<arr[i][j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                int ans=bfs(i,j);
                if(ans>Max)
                {
                    Max=ans;
                    ansi=i;
                    ansj=j;
                    finalx=desx;
                    finaly=desy;
                }
            }
        }
    }
    finalBFS(ansi,ansj);
    cout<<Max<<endl;
    printpath(finalx,finaly);
    cout<<finalx<<' '<<finaly<<endl;
}
