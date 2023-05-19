#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} Node;

Node *createNode(int val, Node *parent);
int height(Node *root);
void adjustHeight(Node *root);
Node *rightRotate(Node *root);
Node *leftRotate(Node *root);
Node *balance(Node *root);
Node *insert(Node *root, int val);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int tree[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &tree[j]);
        }
        Node *root = createNode(tree[0], NULL);
        for (int j = 1; j < m; j++) {
            root = insert(root, tree[j]);
        }
        printf("%d\n", cnt);

        cnt = 0;
        root = NULL;
    }
    return 0;
}

int height(Node *root) {
    return root ? root->height : 0;
}

void adjustHeight(Node *root) {
    int h = height(root->left) > height(root->right) ? height(root->left) : height(root->right);
    root->height = 1 + h;
}

Node *rightRotate(Node *root) {
    Node *new_root = root->left;
    if (root->parent) {
        if (root->parent->left == root)
            root->parent->left = new_root;
        else
            root->parent->right = new_root;
    }
    new_root->parent = root->parent;
    root->parent = new_root;
    root->left = new_root->right;
    if (root->left)
        root->left->parent = root;
    new_root->right = root;
    adjustHeight(root);
    adjustHeight(new_root);
    cnt++;
    return new_root;
}

Node *leftRotate(Node *root) {
    Node *new_root = root->right;
    if (root->parent) {
        if (root->parent->right == root)
            root->parent->right = new_root;
        else
            root->parent->left = new_root;
    }
    new_root->parent = root->parent;
    root->parent = new_root;
    root->right = new_root->left;
    if (root->right)
        root->right->parent = root;
    new_root->left = root;

    adjustHeight(root);
    adjustHeight(new_root);
    cnt++;
    return new_root;
}

Node *createNode(int val, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->parent = parent;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *balance(Node *root) {
    if (height(root->left) - height(root->right) > 1) {
        if (height(root->left->left) > height(root->left->right)) {
            root = rightRotate(root);
        }
        else {
            leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (height(root->right) - height(root->left) > 1) {
        if (height(root->right->right) > height(root->right->left)) {
            root = leftRotate(root);
        }
        else {
            rightRotate(root->right);
            root = leftRotate(root);
        }
    }
    return root;
}

Node *insert(Node *root, int val) {
    Node *cur = root;
    while (cur->val != val) {
        if (val < cur->val) {
            if (cur->left)
                cur = cur->left;
            else {
                cur->left = createNode(val, cur);
                cur = cur->left;
            }
        }
        else if (val > cur->val) {
            if (cur->right)
                cur = cur->right;
            else {
                cur->right = createNode(val, cur);
                cur = cur->right;
            }
        }
        else
            return root;
    }
    while (1) {
        cur = cur->parent;
        adjustHeight(cur);
        cur = balance(cur);
        if (!cur->parent)
            break;
    }
    return cur;
}