#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff
int dp[1002][2002];
int list[2002];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &list[i]);
        }
        sort(list+1, list+n+1);

        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 2*i; j <= n; j++) {
                if (j > 2*i) dp[i][j] = dp[i][j-1];
                else dp[i][j] = INF;

                if (dp[i][j] > dp[i-1][j-2] + (list[j]-list[j-1])*(list[j]-list[j-1])) {
                    dp[i][j] = dp[i-1][j-2] + (list[j]-list[j-1])*(list[j]-list[j-1]);
                }
            }
        }
        printf("%d\n", dp[k][n]);
    }

    return 0;
}