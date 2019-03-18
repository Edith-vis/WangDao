#include <iostream>
#include <cstring>
using namespace std;

char str1[30], str2[30];//1:前序 2:中序
int loc;//已经分配了的结点个数

struct Node
{
    Node* left;
    Node* right;
    char c;
}Tree[50];

void postOrder(Node* pRoot) {
    if (pRoot->left != NULL) postOrder(pRoot->left);
    if (pRoot->right != NULL) postOrder(pRoot->right);
    printf("%c", pRoot->c);
}

Node* create() {
    Tree[loc].left = Tree[loc].right = NULL;
    return &Tree[loc++];
}

Node* build(int s1, int e1, int s2, int e2) {
    Node* pRoot = create();
    pRoot->c = str1[s1];

    int rootIdx = 0;
    for (int i = s2; i <= e2; i++) {
        if (str1[s1] == str2[i]) {
            rootIdx = i;
            break;
        }
    }

    if (rootIdx != s2) {//左子树不为空
        pRoot->left = build(s1+1, s1+(rootIdx-s2) , s2, rootIdx-1);
    }
    if (rootIdx != e2) {//右子树不为空
        pRoot->right = build(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2);
    }
    return pRoot;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        loc = 0;
        Node* root = build(0, len1-1, 0, len2-1);
        postOrder(root);
        printf("\n");
    }

    return 0;
}