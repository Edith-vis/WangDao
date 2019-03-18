#include <iostream>
using namespace std;

int primeSize = 0;
int prime[10000];
bool mark[10001];//mark[x] == true标明x为非负数

void init() {
    for (int i = 0; i < 10001; i++) {
        mark[i] = false;
    }

    for (int i = 2; i < 10001; i++) {
        if (mark[i] == true) continue;
        prime[primeSize++] = i;
        for (int j = i*i; j < 10001; j+=i) {
            mark[j] = true;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        bool hasPrime = false;
        for (int i = 0; i < primeSize; i++) {
            if (prime[i] < n && prime[i]%10 == 1) {
                if (hasPrime == false) {
                    hasPrime = true;
                    printf("%d", prime[i]);
                } else {
                    printf(" %d", prime[i]);
                }
            }
        }

        if (hasPrime == false) {
            printf("-1\n");
        } else {
            printf("\n");
        }
    }

    return 0;
}