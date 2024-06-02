#include <stdio.h>
#define MAX 505

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int dp[MAX][MAX];

    int num;
    scanf("%d", &num);
    dp[1][1] = num;

    for (int i = 2; i <= n; ++i)
    {
        int nums[i + 1];
        for (int j = 1; j <= i; ++j)
            scanf("%d", &nums[j]);

        for (int j = 1; j <= i; ++j)
            dp[i][j] = max(nums[j] + dp[i - 1][j - 1], nums[j] + dp[i - 1][j]);
    }

    int res = dp[n][1];
    for (int i = 2; i <= n; ++i)
        res = max(res, dp[n][i]);

    printf("%d\n", res);

    return 0;
}