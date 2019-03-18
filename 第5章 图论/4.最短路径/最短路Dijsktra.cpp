#include <iostream>
#include <vector>
#define N 101
using namespace std;

struct E{
    int next;
    int c;//该边的权值
};

bool mark[N]; //mark[i]=true表示i结点属于K集合
int Dis[N];//距离向量

vector<E> edge[N];//存图的邻接链表

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;

        //初始化邻接链表
        for (int i = 1; i <= n; i++) edge[i].clear();
        //输入邻接链表
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            E tmp;
            tmp.c = c;
            tmp.next = a;
            edge[b].push_back(tmp);
            tmp.next = b;
            edge[a].push_back(tmp);
        }
        //初始化mark和dis数组
        for (int i = 1; i <= n; i++) {
            mark[i] = false;
            Dis[i] = -1;//不可达
        }
        //初始化起点
        mark[1] = true;
        Dis[1] = 0;

        int newP = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < edge[newP].size(); j++) {
                int t = edge[newP][j].next;
                int c = edge[newP][j].c;
                if (mark[t] == true) continue;
                if (Dis[t] == -1 || Dis[t] > Dis[newP]+c) {
                    Dis[t] = Dis[newP]+c;
                }
            }

            int min = 123123123;
            for (int j = 1; j <= n; j++) {
                if (mark[j] == true) continue;
                if (Dis[j] == -1) continue;
                if (Dis[j] < min) {
                    min = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d\n", Dis[n]);
    }

    return 0;
}