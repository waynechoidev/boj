#include <stdio.h>
#define MAX 1005

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int h[MAX][3];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &h[i][j]);

    int dp[MAX][3];
    for (int i = 0; i < 3; ++i)
        dp[0][i] = h[0][i];

    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = h[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = h[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = h[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    printf("%d", min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]));

    return 0;
}