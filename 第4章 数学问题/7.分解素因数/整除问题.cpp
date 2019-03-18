#include <iostream>
using namespace std;

int prime[1000];
bool mark[1000];
int primeSize = 0;

void init() {
    for (int i = 0; i < 1000; i++) {
        mark[i] = false;
    }

    for (int i = 2; i < 1000; i++) {
        if (mark[i] == true) continue;
        prime[primeSize++] = i;
        if (i > 100) continue;
        for (int j = i*i; j < 1000; j+=i) {
            mark[j] = true;
        }
    }
}

int cnt1[1000];
int cnt2[1000];
int main() {
    freopen("D:/in.txt", "r", stdin);
    init();
    int n, a;
    while (scanf("%d%d", &n, &a) == 2) {
        for (int i = 0; i < primeSize; i++) {
            cnt1[i] = cnt2[i] = 0;
        }

        for (int i = 0; i < primeSize; i++) {
            int t = n;
            while (t) {
                cnt1[i] += t/prime[i];
                t/=prime[i];
            }
        }

        int ans = 123123123;
        for (int i = 0; i < primeSize; i++) {
            while (a%prime[i] == 0) {
                cnt2[i]++;
                a /= prime[i];
            }

            if (cnt2[i] == 0) continue;
            ans = (cnt1[i]/cnt2[i] < ans) ? cnt1[i]/cnt2[i] : ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}