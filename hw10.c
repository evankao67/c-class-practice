#include <stdio.h>
int a[10005], b[10005], c[20005], a_now[10005], b_now[10005];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int find(int *nums1, int nums1Size, int *nums2, int nums2Size, int flag)
{
    int sizeSum = (nums1Size + nums2Size);

    if (sizeSum == 0)
        return 0;
    else if (nums1Size == 0 && nums2Size == 1)
        return nums2[0];
    else if (nums2Size == 0 && nums1Size == 1)
        return nums1[0];

    int count = 0;
    int i1 = 0;
    int i2 = 0;

    int mIndex = sizeSum / 2 - 1;

    while (count < mIndex)
    {
        if (i1 == nums1Size && i2 < nums2Size)
            i2++;
        else if (i2 == nums2Size && i1 < nums1Size)
            i1++;
        else if (nums1[i1] <= nums2[i2])
            i1++;
        else
            i2++;
        count++;
    }

    int median1 = 0;

    if (i1 == nums1Size && i2 < nums2Size)
        median1 = nums2[i2++];
    else if (i2 == nums2Size && i1 < nums1Size)
        median1 = nums1[i1++];
    else if (nums1[i1] <= nums2[i2])
        median1 = nums1[i1++];
    else
        median1 = nums2[i2++];

    int median2 = 0;

    if (i1 == nums1Size && i2 < nums2Size)
        median2 = nums2[i2++];
    else if (i2 == nums2Size && i1 < nums1Size)
        median2 = nums1[i1++];
    else if (nums1[i1] <= nums2[i2])
        median2 = nums1[i1++];
    else
        median2 = nums2[i2++];

    if (flag==0)
        return median2;

    return median1;
}
int main()
{
    int na, nb;
    scanf("%d", &na);
    for (int i = 0; i < na; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &nb);
    for (int i = 0; i < nb; i++)
    {
        scanf("%d", &b[i]);
    }
    int times, ax, ay, bx, by;
    scanf("%d", &times);
    for (int i = 0; i < times; i++)
    {
        int sum = 0, acount = 0, bcount = 0, target;
        scanf("%d%d%d%d", &ax, &ay, &bx, &by);
        sum = ay - ax + by - bx;
        for (int j = ax; j < ay; j++)
        {
            a_now[acount] = a[j];
            acount++;
        }
        for (int j = bx; j < by; j++)
        {
            b_now[bcount] = b[j];
            bcount++;
        }
        if((acount+bcount)%2==1)
        {
            int flag=0;
            int ans = find(a_now, acount, b_now, bcount,flag);
            printf("%d\n",ans);
        }
        else
        {
            int flag=1;
            int ans1 = find(a_now, acount, b_now, bcount,flag);
            flag=0;
            int ans2 = find(a_now, acount, b_now, bcount,flag);
            printf("%d %d\n",ans1,ans2);
        }
        //qsort(c,counter-1,sizeof(int),cmp);
        /*for(int k=0;k<counter;k++)
        {
            printf("%d ",c[k]);
        }
        puts("");*/
        /*if(sum%2==0)
        {
            printf("%d %d\n",c[(sum/2)-1],c[sum/2]);
        }
        else
        {
            printf("%d\n",c[(sum-1)/2]);
        }*/
    }
    return 0;
}
