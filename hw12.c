#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans,subcount=0,acount;
    int k=a,sub=b-a;
    while(k!=0)
    {
        acount++;
        k/=2;
    }
    //printf("%d",acount);
    while(sub!=0)
    {
        subcount++;
        sub/=2;
    }
    if(subcount>=acount)
    {
        printf("0");
    }
    else
    {
        a=a>>subcount;
        b=b>>subcount;
        ans=a&b;
        printf("%d",ans<<subcount);
    }
    return 0;
}
