#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100005
#define MAX 2000000000

int a[LENGTH];

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), compare);

    int en = 0, res = MAX;
    for (int st = 0; st < n; ++st)
    {
        while (en < n && a[en] - a[st] < m)
            en++;

        if (en == n)
            break;

        res = min(res, a[en] - a[st]);
    }

    printf("%d", res);

    return 0;
}