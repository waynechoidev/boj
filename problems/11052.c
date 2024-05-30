#include <stdio.h>
#define MAX 1001

int main()
{
    int n;
    int p[MAX];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);

    int np[MAX] = {-1};

    for (int i = 1; i <= n; ++i)
    {
        int max = p[i];
        for (int j = 1; j < i; ++j)
        {
            int cur = np[j] + np[i - j];
            if (cur > max)
                max = cur;
        }
        np[i] = max;
    }

    printf("%d", np[n]);

    return 0;
}