#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[5005], b[5005];
double slope[5005][5005];
int cmpfunc(const void *a, const void *b)
{
    return (*(double *)a > *(double *)b) ? 1 : -1;
}
int main()
{
    //float arr[5]={3.5,-78,-78.9,243,80};
    int n;
    scanf("%d", &n);
    int sum = 1, ans = 0, ex = 0;
    for (int y = 0; y < n + 1; y++)
    {
        for (int x = 0; x < n + 1; x++)
        {
            slope[y][x] = -1223;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        //printf("a=%d\nb=%d\n",a[i],b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int J = j;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] - a[j] == 0 && b[i] - b[j] == 0)
            {
                ex++;
            }
            if (a[i] - a[j] == 0)
            {
                slope[i][j] = -1234;
                //printf("%lf ",slope[i][j]);
            }

            else
            {
                slope[i][j] = ((double)(b[i] - b[j])) / (double)(a[i] - a[j]);
                //printf("%lf ",slope[i][j]);
            }
        }
        qsort(&slope[i][J], n - i - 1, sizeof(double), cmpfunc);
        //puts("jhg");
        //printf("\n");
    }
    //for(int u=0;u<n;u++)
    //{
    //qsort(&slope[u][0], n-1, sizeof(int), cmpfunc);
    //}
    int j = 0;
    //for(int i=0;i<n;i++)
    //{
    //for(int j=i+1;j<n;j++)
    //{
    //slope[i][j]=((b[i]-b[j])*1000)/(a[i]-a[j]);
    //printf("%lf ",slope[i][j]);
    //}
    //qsort(&slope[i][0], n-1-i, sizeof(float), cmpfunc);
    //puts("jhg");
    //printf("\n");
    //}
    for (int i = 0; i < n; i++)
    {
        sum = 1;
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            while (slope[i][j] == slope[i][j + count])
            {
                sum++;
                count++;
            }
            if (sum > ans)
            {
                ans = sum;
            }
            //printf("sum=%d\n",sum);
            count = 1;
            sum = 1;
            //slope[i][j]=((b[i]-b[j])*1000)/(a[i]-a[j]);
            //printf("%lf ",slope[i][j]);
        }

        //slope[i][j]=(float)(b[j]-b[i])/(float)(a[j]-a[i]);
        //printf("%d ",slope[i][j]);

        //qsort(slope[i], n-i, sizeof(int), cmpfunc);
        //printf("\n");
    }
    //qsort(arr,5,sizeof(float),cmpfunc);
    //for(int u=0;u<5;u++)
    //{
    //printf("%f ",arr[u]);
    //}
    printf("%d", ans + 1);
    return 0;
}
