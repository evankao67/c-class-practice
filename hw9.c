#include <stdio.h>
int binary_search(int list[], int left, int right, int target,int *counter)
{
    int mid;
    while (left <= right)
    {
        *counter+=1;
        mid = (right + left) / 2;
        if (target == list[mid])
            return mid;
        if (target < list[mid])
            right = mid;
        else
            left = mid+1 ;
        
    }
    return -1;
}
int arr[100000000];
int main()
{
    int key, num, count = 0,counter=0;
    scanf("%d", &num);
    while (scanf("%d", &arr[count]) != EOF)
    {
        count++;
    }
    key = binary_search(arr, 0, count-1, num,&counter);
    printf("%d\n", key);
    if(key!=-1) 
        printf("%d",counter);
    return 0;
}
