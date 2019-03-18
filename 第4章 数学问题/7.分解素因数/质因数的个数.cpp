#include <iostream>
using namespace std;


bool mark[100000];
int prime[100000];
int primeSize = 0;
void init() {
    for (int i = 0; i < 100000; i++) {
        mark[i] = false;
    }
    for (int i = 2; i < 100000; i++) {
        if (mark[i] == true) continue;
        prime[primeSize++] = i;
        if (i >= 10000) continue;
        for (int j = i*i; j < 100000; j+=i) {
            mark[j] = true;
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    init();
    int n;
    while(scanf("%d", &n) != EOF) {
        int ansPrime[30];
        int ansCount[30];
        int ansSize = 0;
        for (int i = 0; i < primeSize; i++) {
            if (n%prime[i] == 0) {
                ansPrime[ansSize] = prime[i];
                ansCount[ansSize] = 0;
                while (n%prime[i] == 0) {
                    ansCount[ansSize]++;
                    n/=prime[i];
                }
                ansSize++;
                if (n==1) break;
            }
        }

        if (n!=1) {
            ansPrime[ansSize] = n;
            ansCount[ansSize] = 1;
            ansSize++;
        }

        int ans = 0;
        for (int i = 0; i < ansSize; i++) {
            ans += ansCount[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}