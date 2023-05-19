#include <stdio.h>

void inorder(int idx, int len, int nodes[], int *c)
{
    if (idx > len || nodes[idx] == 0) // Base condition
        return;
    inorder(2 * idx + 1, len, nodes, c); // Travese left tree
    if (*c > 1)
        printf("%d ", nodes[idx]);
    else
        printf("%d", nodes[idx]);
    (*c)--;
    inorder(2 * idx + 2, len, nodes, c); // Traverse right tree
}

int main()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    int nodes[10000] = {0};
    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &nodes[j]);
            if (nodes[j] != 0)
                c++;
        }
        inorder(0, len, nodes, &c);
        printf("\n");
    }
    return 0;
}