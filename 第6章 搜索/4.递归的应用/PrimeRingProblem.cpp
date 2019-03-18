#include <iostream>
using namespace std;

int n;
int ans[20];
bool mark[20];

int prime[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
};

bool judge(int num) {
    for (int i = 0; i < 11; i++){
        if (prime[i] == num) return true;
    }
    return false;
}

void check() {
    if (judge(ans[n]+ans[1]) == false) return;
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return;
}

void DFS(int num) {
    if (num > 1) {
        if (judge(ans[num]+ans[num-1]) == false) return;
    }
    if (num == n) {
        check();
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (mark[i] == false) {
            mark[i] = true;
            ans[num+1] = i;
            DFS(num+1);
            mark[i] = false;
        }
    }
}



int main() {
    freopen("D:/in.txt", "r", stdin);
    int cas = 0;
    while(scanf("%d", &n) != EOF) {
        cas++;
        for (int i = 1; i <= n; i++) {
            mark[i] = false;
            ans[i] = 0;
        }
        printf("Case %d:\n", cas);
        mark[1] = true;
        ans[1] = 1;
        DFS(1);
    }

    return 0;
}