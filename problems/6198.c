#include <stdio.h>
#define MAX 80005

int main()
{
    int n;
    scanf("%d", &n);
    int h[MAX];
    for (int i = 0; i < n; ++i)
        scanf("%d", &h[i]);

    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        int idx = 0;
        int j = i + 1;
        while (j < n && h[i] > h[j])
        {
            j++;
            res++;
        }
    }

    printf("%lld", res);

    return 0;
}