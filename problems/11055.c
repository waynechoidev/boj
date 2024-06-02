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
    int dp[MAX];
    for (int i = 0; i < n; ++i)
    {
        int num;
        scanf("%d", &num);
        a[i] = num;
        dp[i] = num;
    }

    int max = a[1];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i] && dp[i] < dp[j] + a[i])
                dp[i] = dp[j] + a[i];
        if (max < dp[i])
            max = dp[i];
    }

    printf("%d", max);
    return 0;
}