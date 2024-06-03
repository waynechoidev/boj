#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

int main()
{
    int N, k;
    scanf("%d", &N);
    scanf("%d", &k);

    if (N == 1)
    {
        printf("<1>");
        return 0;
    }

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    for (int i = 2; i <= N; ++i)
    {
        Node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        newNode->prev = cur;
        cur->next = newNode;

        if (i == N)
        {
            newNode->next = head;
            head->prev = newNode;
        }
    }

    printf("<");

    Node *p = head;
    while (p != p->next)
    {
        int n = k - 1;
        while (n--)
        {
            p = p->next;
        }
        printf("%d", p->data);
        Node *temp = p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p = p->next;
        free(temp);
        printf(", ");
    }

    printf("%d>", p->data);
    free(p);

    return 0;
}