#include <bits/stdc++.h>
#define MAX 1500005
using namespace std;

int dp[MAX];
int t[MAX];
int p[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> t[i] >> p[i];

    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (i + t[i] > n)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
    }

    cout << dp[0];

    return 0;
}