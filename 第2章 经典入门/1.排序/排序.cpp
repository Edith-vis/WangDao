#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int b[100];
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        sort(b, b+n);
        for (int i = 0; i < n; i++) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }

    return 0;
}