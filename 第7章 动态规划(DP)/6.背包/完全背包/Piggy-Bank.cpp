#include <iostream>
#define INF 0x7fffffff
using namespace std;

int min(int a, int b) {
    return a<b ? a : b;
}

int dp[10001];

struct E{
    int w;//重量
    int v;//价值
} list[501];


int main() {
    freopen("D:/in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int w1, w2;
        scanf("%d%d", &w1, &w2);
        int s = w2-w1;//钱币的总重量
        int n;
        scanf("%d", &n);//钱币的种类数量
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &list[i].v, &list[i].w);
        }

        //初始化
        for (int j = 0; j <= s; j++) {
            dp[j] = INF;
        }
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = list[i].w; j <= s; j++) {
                if (dp[j-list[i].w] != INF)
                    dp[j] = min(dp[j], dp[j-list[i].w]+list[i].v);
            }
        }

        if (dp[s] != INF) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[s]);
        } else {
            printf("This is impossible.\n");
        }
    }

    return 0;
}