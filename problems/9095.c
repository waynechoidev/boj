#include <stdio.h>
#define MAX 11

int main()
{
    int dp[MAX];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < MAX; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int n;
    scanf("%d", &n);

    int t[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &t[i]);

    for (int i = 0; i < n; ++i)
        printf("%d\n", dp[t[i]]);

    return 0;
}