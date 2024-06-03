#include <stdio.h>
#define MAX 1000001

int arr[MAX];
int stack[MAX];
int res[MAX];

int main()
{
    int top = -1;
    int resTop = -1;
    int number;
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
        scanf("%d", &arr[i]);

    for (int i = number - 1; i >= 0; i--)
    {
        while (top > -1 && stack[top] <= arr[i])
            top--;

        if (top == -1)
            res[++resTop] = -1;
        else
            res[++resTop] = stack[top];

        stack[++top] = arr[i];
    }

    for (int i = resTop; i >= 0; i--)
        printf("%d ", res[i]);

    return 0;
}