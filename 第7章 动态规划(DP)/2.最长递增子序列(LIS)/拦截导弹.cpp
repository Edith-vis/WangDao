#include <iostream>
using namespace std;

int list[26];
int dp[26];

int max(int a, int b) {
    return a>b ? a : b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d" , &list[i]);
        }

        for (int i = 1; i <= n; i++) {
            int tmax = 1;
            for (int j = i-1; j >= 1; j--) {
                if (list[j] >= list[i]) {
                    tmax = max(tmax, dp[j]+1);
                }
            }
            dp[i] = tmax;
        }

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}