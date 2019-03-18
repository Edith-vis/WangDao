#include <iostream>
using namespace std;

int dp[101];

struct E{
    int w, v;
} list[2001];

int max(int a, int b) {
    return a>b?a:b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;//经费为n大米种类为m
        scanf("%d%d", &n, &m);

        int cnt = 0;//读取数据及拆分
        for (int i = 1; i <= m; i++) {
            int p, h, k;
            scanf("%d%d%d", &p, &h, &k);

            //拆k
            int c = 1;
            while (k-c>0)
            {
                k-=c;
                list[++cnt].w = c*p;
                list[cnt].v = c*h;
                c*=2;
            }
            //剩下的k
            list[++cnt].w = k*p;
            list[cnt].v = k*h;
        }

        //初始化
        for (int j = 0; j <= n; j++) {
            dp[j] = 0;
        }

        for (int i = 1; i <= cnt; i++) {
            for (int j = n; j >= list[i].w; j--) {
                dp[j] = max(dp[j], dp[j-list[i].w]+list[i].v);
            }
        }
        printf("%d\n", dp[n]);
    }

    return 0;
}