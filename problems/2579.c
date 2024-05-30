#include <stdio.h>
#define MAX 305

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int s[MAX];
    for (int i = 0; i < n; ++i)
        scanf("%d", &s[i]);

    int dp[MAX][2];
    dp[0][0] = dp[0][1] = s[0];
    dp[1][0] = s[1];
    dp[1][1] = s[0] + s[1];

    for (int i = 2; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + s[i];
        dp[i][1] = dp[i - 1][0] + s[i];
    }

    printf("%d", max(dp[n - 1][0], dp[n - 1][1]));

    return 0;
}