#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        int x;
        int Hash[101] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            Hash[x]++;
        }
        scanf("%d", &x);
        printf("%d\n", Hash[x]);
    }
    return 0;
}