#include <iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int val;
}Tree[120];

int loc;

void preOrder(Node* pRoot) {
    printf("%d ", pRoot->val);
    if (pRoot->left != NULL) preOrder(pRoot->left);
    if (pRoot->right != NULL) preOrder(pRoot->right);
}

void inOrder(Node* pRoot) {
    if (pRoot->left != NULL) inOrder(pRoot->left);
    printf("%d ", pRoot->val);
    if (pRoot->right != NULL) inOrder(pRoot->right);
}

void postOrder(Node* pRoot) {
    if (pRoot->left != NULL) postOrder(pRoot->left);
    if (pRoot->right != NULL) postOrder(pRoot->right);
    printf("%d ", pRoot->val);
}

Node* create() {
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc++];
}

void Insert(Node* &T, int x) {
    if (T == NULL) {
        T = create();
        T->val = x;
    } 
    else if (x > T->val) Insert(T->right, x);
    else if (x < T->val) Insert(T->left, x);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF) {
        loc = 0;
        Node* T = NULL;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Insert(T, x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}