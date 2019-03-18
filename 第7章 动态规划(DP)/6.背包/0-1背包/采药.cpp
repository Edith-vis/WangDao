#include <iostream>
using namespace std;

struct E
{
    int w;
    int v;
}list[101];

int dp[101][1001];

int max(int a, int b) {
    return a>b?a:b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int t,m;
    while (scanf("%d%d", &t, &m) != EOF) {
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &list[i].w, &list[i].v);
        }

        for (int j = 0; j <= t; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = t; j >= list[i].w; j--) {
                dp[i][j] = max(dp[i-1][j-list[i].w]+list[i].v, dp[i-1][j]);
            }
            for (int j = list[i].w-1; j >= 0; j--) {
                dp[i][j] = dp[i-1][j];
            }
        }
        printf("%d\n", dp[m][t]);
    }

    return 0;
}