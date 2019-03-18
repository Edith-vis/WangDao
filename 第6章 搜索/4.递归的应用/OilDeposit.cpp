#include <iostream>
using namespace std;

char maze[101][101];
bool mark[101][101];
int n, m;

int go[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    
    {0, -1}, 
    {0, 1},
    
    {1, -1},
    {1, 0},
    {1, 1},
};

void DFS(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x+go[i][0];
        int ny = y+go[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (maze[nx][ny] == '*') continue;
        if (mark[nx][ny] == true) continue;
        mark[nx][ny] = true;
        DFS(nx, ny);
    }
    return;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maze[i][j] = ' ';
                mark[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == '*') continue;
                if (mark[i][j] == true) continue;
                mark[i][j] = true;
                DFS(i, j);
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}