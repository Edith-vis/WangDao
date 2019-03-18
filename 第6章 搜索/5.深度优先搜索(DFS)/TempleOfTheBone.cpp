#include <iostream>
using namespace std;

int n, m, t;
char maze[10][10];
int go[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};
bool success;
void DFS(int x, int y, int time) {
    for (int i = 0; i < 4; i++) {
        int nx = x+go[i][0];
        int ny = y+go[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (maze[nx][ny] == 'X') continue;
        if (maze[nx][ny] == 'D') {
            if (time+1 == t) {
                success = true;
                return;
            } else {
                continue;
            }
        }
        maze[nx][ny] = 'X';
        DFS(nx, ny, time+1);
        maze[nx][ny] = '.';
        if (success) return;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%d%d%d", &n, &m, &t) != EOF) {
        if (n == 0 && m == 0 && t == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        success = false;

        int dx = 0, dy = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'D') {
                    dx = i;
                    dy = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'S' && (i+j)%2 == ((dx+dy)%2+t%2)%2) {
                    maze[i][j] = 'X';
                    DFS(i, j, 0);
                }
            }
        }
        puts(success == true ? "YES" : "NO");
    }
    return 0;
}