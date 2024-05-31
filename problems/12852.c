#include <stdio.h>
#define MAX 1000001

int main()
{
    int n;
    scanf("%d", &n);
    int dp[MAX];
    int pre[MAX];

    dp[1] = 0;
    pre[1] = 0;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    printf("%d\n", dp[n]);
    printf("%d ", n);
    while (n > 1)
    {
        printf("%d ", pre[n]);
        n = pre[n];
    }

    return 0;
}