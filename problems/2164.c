#include <stdio.h>
#define MAX 500000

int main()
{
    int n;
    scanf("%d", &n);

    int q[MAX * 2];
    int t = 0, b = n - 1;
    for (int i = 0; i < n; ++i)
        q[i] = i + 1;

    while (b > t)
    {
        t++;
        if (b > t)
        {
            int temp = q[t++];
            q[++b] = temp;
        }
    }

    printf("%d", q[t]);

    return 0;
}