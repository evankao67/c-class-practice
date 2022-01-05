#include <stdio.h>
#include <string.h>
int arr1[1005], arr2[1005];
int main()
{
    int n1, n2, counter = 0, ans = 0, j, k;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (arr1[i] == arr2[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
