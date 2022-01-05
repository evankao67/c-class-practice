#include <stdio.h>
#include <string.h>

int dp[100][100];

int main()
{
    int i, j, j_temp, num;
    int nums[100];
    memset(dp, 0, sizeof(dp));
    scanf("%d", &num);
    for (i = 0; i < num; ++i)
    {
        scanf("%d", &nums[i]);
    }
    j_temp = num;
    for (i = num - 2; i >= 0; --i)
    {
        j_temp--;
        j = j_temp;
        for (j; j < num; ++j)
        {
            int a = nums[i] - dp[i + 1][j];
            int b = nums[j] - dp[i][j - 1];
            dp[i][j] = (a > b) ? a : b;
        }
    }
    if (dp[0][num - 1] >= 0)
        printf("True");
    else
        printf("False");
    return 0;
}
