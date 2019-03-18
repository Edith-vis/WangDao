#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101];
int max(int a, int b) {
    return a>b ? a : b;
}

char str1[101], str2[101];

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%s%s", str1, str2) != EOF) {
        int l1 = strlen(str1);
        int l2 = strlen(str2);

        for (int i = 0; i <= l1; i++) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= l2; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        printf("%d\n", dp[l1][l2]);
    }

    return 0;
}