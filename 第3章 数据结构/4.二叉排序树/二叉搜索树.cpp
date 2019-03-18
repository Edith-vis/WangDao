#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int val;
}Tree[120];

int loc;
Node* create() {
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc++];
}

int size1, size2;
char str1[25], str2[25];

int* length;
char* str;

void postOrder(Node* T) {
    if (T->left != NULL) postOrder(T->left);
    if (T->right != NULL) postOrder(T->right);
    str[(*length)++] = T->val + '0'; 
}

void inOrder(Node* T) {
    if (T->left != NULL) inOrder(T->left);
    str[(*length)++] = T->val + '0';
    if (T->right != NULL) inOrder(T->right);
}

void insert(Node* &T, int x) {
    if (T == NULL) {
        T = create();
        T->val = x;
    } else if (x < T->val) {
        insert(T->left, x);
    } else if (x > T->val) {
        insert(T->right, x);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    char tmp[12];
    while (scanf("%d", &n) != EOF && n != 0) {
        loc = 0;
        scanf("%s", tmp);
        Node* root1 = NULL;
        for (int i = 0; tmp[i] != 0; i++) {
            insert(root1, tmp[i]-'0');
        }
        size1 = 0;
        str = str1;
        length = &size1;
        postOrder(root1);
        inOrder(root1);
        str[size1] = 0;
        while(n--) {
            scanf("%s", tmp);
            Node* root2 = NULL;
            for (int i = 0; tmp[i] != 0; i++) {
                insert(root2, tmp[i]-'0');
            }
            size2 = 0;
            str = str2;
            length = &size2;
            postOrder(root2);
            inOrder(root2);
            str[size2] = 0;

            puts(strcmp(str1, str2) == 0 ? "Yes" : "No"); 
        }
    }

    return 0;
}