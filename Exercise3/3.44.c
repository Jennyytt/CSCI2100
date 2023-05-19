#include <stdio.h>
#include <stdlib.h>

long ans[10000] = {0};
long cnt = 0;

typedef struct node {
    long val;
    struct node *left;
    struct node *right;
} Node;
 
Node* createNode (long val) {
    Node* temp = (Node*) malloc( sizeof(Node) );
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
//recursion
Node* buildHelper (long pre[], long post[], long* pre_idx, long start, long end, long size) {  
    if (*pre_idx >= size || start > end)  //pre_idx>= size mean tai yuen whole pre[]can end
        return NULL;
    Node* root = createNode(pre[*pre_idx]);
    (*pre_idx)++;
    if (start == end)
        return root;
    long i = start;
    while (i <= end) {
        if (pre[*pre_idx] == post[i])
            break;
        i++;
    }
    if (i <= end) {
        root->left = buildHelper (pre, post, pre_idx, start, i, size);
        root->right = buildHelper (pre, post, pre_idx, i + 1, end - 1, size);
    }
 
    return root;
}
 
Node *build (long pre[], long post[], long size) {
    long pre_idx = 0;
    return buildHelper (pre, post, &pre_idx, 0, size - 1, size);
}
 

void saveInorder (Node* node) {
    if (node == NULL)
        return;
    saveInorder(node->left);
    ans[cnt++] = node->val;
    saveInorder(node->right);
}
 

long main() {
    long n;  //1
    scanf("%ld", &n);
    for (long i = 0; i < n; i++) {
        long m;
        scanf("%ld", &m);  //9
        long pre[m];
        for (long j = 0; j < m; j++) {
            scanf("%ld", &pre[j]);
        }
        long post[m];
        for (long j = 0; j < m; j++) {
            scanf("%ld", &post[j]);
        }
        Node *root = build(pre, post, m);
        saveInorder(root);
        for (long j = 0; j < cnt; j++) {
            if (j == cnt - 1) {
                printf("%ld\n", ans[j]);
                break;
            }
            printf("%ld ", ans[j]);
        }
        cnt = 0;
    }
    return 0;
}