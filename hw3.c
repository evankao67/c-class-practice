#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n%4==0)
    {
        n/=4;
    }
    if(n%8==7)
    {
        printf("4\n");
        return 0;
    }
    for(int a=0;a*a<=n;a++)
    {
        int b=sqrt(n-a*a);
        if(a*a+b*b==n)
        {
            if(a==0||b==0)
            {
                printf("1\n");
                return 0;
            }
            else
            {
                printf("2\n");
                return 0;
            }
        }
    }
    printf("3\n");
    return 0;
}
