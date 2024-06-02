#include <stdio.h>
#define MAX 100005

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int dp[MAX];
    dp[0] = 0;
    int maxNum = -1000;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        scanf("%d", &num);
        if (num > maxNum)
            maxNum = num;
        dp[i] = max(dp[i - 1] + num, 0);
    }

    int res = dp[1];
    for (int i = 2; i <= n; ++i)
        res = max(res, dp[i]);

    if (maxNum < 0)
        printf("%d", maxNum);
    else
        printf("%d", res);

    return 0;
}