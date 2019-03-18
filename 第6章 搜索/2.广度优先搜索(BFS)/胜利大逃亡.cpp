#include <iostream>
#include <queue>
using namespace std;

struct N
{
    int a, b, c;
    int t;
};

queue<N> Q;

bool mark[50][50][50];
int maze[50][50][50];

int go[][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}
};

int BFS(int a, int b, int c) {
    while(!Q.empty()) {
        N now = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = now.a+go[i][0];
            int ny = now.b+go[i][1];
            int nz = now.c+go[i][2];
            if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) continue;
            if (maze[nx][ny][nz] == 1) continue;
            if (mark[nx][ny][nz] == true) continue;
            N tmp;
            tmp.a = nx;
            tmp.b = ny;
            tmp.c = nz;
            tmp.t = now.t+1;
            Q.push(tmp);
            mark[nx][ny][nz] = true;
            if (nx == a-1 && ny == b-1 && nz == c-1) return tmp.t;
        }
    }
    return -1;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, c, t;
        scanf("%d%d%d%d", &a, &b, &c, &t);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    scanf("%d", &maze[i][j][k]);
                    mark[i][j][k] = false;
                }
            }
        }

        while (!Q.empty()) Q.pop();
        mark[0][0][0] = true;
        N tmp;
        tmp.a = 0;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0;
        Q.push(tmp);
        int ret = BFS(a, b, c);
        if (ret <= t) {
            printf("%d\n", ret);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}