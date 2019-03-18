#include <iostream>
using namespace std;

#define OFFSET 2000
#define INF 0x7fffffff
int dp[101][4001];
int list[101];

int main() {
    freopen("D:/in.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    int cas = 0;
    while(t--) {
        int n;
        scanf("%d", &n);
        bool haveZero = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &list[++cnt]);
            if (list[cnt] == 0) {
                cnt--;
                haveZero = true;
            }
        }
        n = cnt;

        //初始化
        
        for (int j = -2000; j <= 2000; j++) {
            dp[0][j+OFFSET] = -INF;
        }
        dp[0][0+OFFSET] = 0;

        for (int i = 1; i <= n; i++) {//遍历每个柑橘
            for (int j = -2000; j <= 2000; j++) {//遍历每个可能的重量差
                int tmp1=-INF, tmp2=-INF;
                //tmp1:将第i个柑橘放在第一堆后得到的新值
                if (dp[i-1][j+list[i]+OFFSET] != -INF && j+list[i] <= 2000) {
                    tmp1 = dp[i-1][j+list[i]+OFFSET]+list[i];
                }
                if (dp[i-1][j-list[i]+OFFSET] != -INF && j-list[i] >= -2000) {
                    tmp2 = dp[i-1][j-list[i]+OFFSET]+list[i];
                }
                if (tmp1 < tmp2) {//tmp1中保存较大值
                    tmp1 = tmp2;
                }
                if (tmp1 < dp[i-1][j+OFFSET]) {//不放第i个柑橘
                    tmp1 = dp[i-1][j+OFFSET];
                }
                dp[i][j+OFFSET] = tmp1;
            }
        }



        printf("Case %d: ", ++cas);
        if (dp[n][0+OFFSET] == 0) {
            puts(haveZero==true?"0":"-1");
        } else {
            printf("%d\n", dp[n][0+OFFSET]/2);
        }

    }

    return 0;
}