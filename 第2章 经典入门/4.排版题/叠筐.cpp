#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    char c1, c2;
    int res[82][82];
    bool firstCase = true;
    while (scanf("%d %c %c", &n, &c1, &c2) == 3) {
        if (firstCase == true) {
            firstCase = false;
        } else {
            printf("\n");
        }

        for (int i = 1, j = 1; i <= n; i += 2, j++) {
            char c = j%2 == 1 ? c1 : c2;

            int x = n/2 + 1 - (j-1);
            int y = x;

            for (int k = 0; k < i; k++) {
                res[x][y+k] = c;//上
                res[x+i-1][y+k] = c;//下
                res[x+k][y] = c;//左
                res[y+k][y+i-1] = c;//右
            }
        }

        if (n != 1) {
            res[1][1] = ' ';
            res[n][n] = ' ';
            res[1][n] = ' ';
            res[n][1] = ' ';
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= n; j++) {
                printf("%c", res[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}