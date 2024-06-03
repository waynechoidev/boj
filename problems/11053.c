#include <stdio.h>
#define MAX 1005

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[MAX];

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int dp[MAX];
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    int res = dp[1];
    for (int i = 2; i <= n; ++i)
        res = max(res, dp[i]);

    printf("%d", res);

    return 0;
}