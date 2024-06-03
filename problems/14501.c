#include <stdio.h>
#define MAX 15

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N;
    scanf("%d", &N);

    int T[MAX] = {0};
    int P[MAX] = {0};
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &T[i]);
        scanf("%d", &P[i]);
    }

    int dp[MAX + 1] = {0};

    for (int i = N - 1; i >= 0; --i)
    {
        if (T[i] + i > N)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
    }

    printf("%d", dp[0]);

    return 0;
}