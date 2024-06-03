#include <stdio.h>
#define MAX 100

int main()
{
    long long dp[MAX + 1];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= MAX; ++i)
        dp[i] = dp[i - 3] + dp[i - 2];

    int T;
    scanf("%d", &T);

    int N[T + 1];
    for (int i = 1; i <= T; ++i)
        scanf("%d", &N[i]);

    for (int i = 1; i <= T; ++i)
        printf("%lld\n", dp[N[i]]);

    return 0;
}