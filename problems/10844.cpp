#include <bits/stdc++.h>
using namespace std;

long long dp[105][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= 9; ++j)
            if (j == 0)
                dp[i][j] = dp[i - 1][1] % 1000000000;
            else if (j == 9)
                dp[i][j] = dp[i - 1][8] % 1000000000;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;

    int res = 0;
    for (int i = 0; i <= 9; ++i)
        res = (res + dp[n][i]) % 1000000000;

    cout << res;

    return 0;
}