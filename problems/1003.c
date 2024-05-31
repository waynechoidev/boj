#include <stdio.h>
#define MAX 40

int main()
{
    int zeros[MAX + 1];
    int ones[MAX + 1];

    zeros[0] = 1;
    ones[0] = 0;
    zeros[1] = 0;
    ones[1] = 1;

    for (int i = 2; i <= MAX; ++i)
    {
        zeros[i] = zeros[i - 1] + zeros[i - 2];
        ones[i] = ones[i - 1] + ones[i - 2];
    }

    int n;
    scanf("%d", &n);
    int cases[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &cases[i]);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", zeros[cases[i]]);
        printf("%d\n", ones[cases[i]]);
    }

    return 0;
}