#include <iostream>
#define OFFSET 500000
using namespace std;

int Hash[1000001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i <= 1000000; i++) {
            Hash[i] = 0;
        }
        int x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            Hash[x+OFFSET] = 1;
        }

        for (int i = 500000; i >= -500000; i--) {
            if (Hash[i+OFFSET] != 0) {
                printf("%d", i);
                m--;
                if (m != 0) {
                    printf(" ");
                } else {
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}