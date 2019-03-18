#include <iostream>
#include <vector>
#include <queue>
#define N 501
using namespace std;

vector<int> edge[N];
int inDegree[N];
queue<int> Q;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n != 0) {
        for (int i = 0; i < n; i++) {
            inDegree[i] = 0;
            edge[i].clear();
        }
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);//读入一条由x指向y的有向边
            edge[x].push_back(y);//将y加入x的邻接链表
            inDegree[y]++;//又出现了一条指向y的边,累加结点y的入度
        }

        while (!Q.empty()) Q.pop();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) Q.push(i);
        }

        int cnt = 0;
        while (!Q.empty()) {
            int nowP = Q.front();
            Q.pop();
            cnt++;
            for (int i = 0; i < edge[nowP].size(); i++) {
                inDegree[edge[nowP][i]] --;
                if (inDegree[edge[nowP][i]] == 0) {
                    Q.push(edge[nowP][i]);
                }
            }
        }
        if (cnt == n) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}