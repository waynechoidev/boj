#include <stdio.h>
#define MAX 100005

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int nums[MAX];
    nums[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        scanf("%d", &num);
        nums[i] = nums[i - 1] + num;
    }

    int fronts[MAX];
    int backs[MAX];
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &fronts[i]);
        scanf("%d", &backs[i]);
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", nums[backs[i]] - nums[fronts[i] - 1]);

    return 0;
}