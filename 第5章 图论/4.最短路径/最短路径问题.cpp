#include <iostream>
#include <vector>
#define N 1001
using namespace std;

bool mark[N];
int Dis[N];
int cost[N];

struct E
{
    int next;
    int c;
    int co;
};

vector<E> edge[N];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    int S, T;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) edge[i].clear();
        while (m--) {
            int a, b, c, co;
            scanf("%d%d%d%d", &a, &b, &c, &co);
            E tmp;
            tmp.c = c;
            tmp.co = co;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        scanf("%d%d", &S, &T);
        for (int i = 1; i <= n; i++) {
            Dis[i] = -1;
            mark[i] = false;
            cost[i] = 0;
        }

        //初始化起始节点
        mark[S] = true;
        Dis[S] = 0;
        int newP = S;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < edge[newP].size(); j++) {
                int t = edge[newP][j].next;
                int c = edge[newP][j].c;
                int co = edge[newP][j].co;
                if (mark[t] == true) continue;
                if (Dis[t] == -1 || Dis[t] > Dis[newP]+c || 
                (Dis[t] == Dis[newP]+c && cost[t] > cost[newP]+co)) {
                    Dis[t] = Dis[newP]+c;
                    cost[t] = cost[newP]+co;
                }
            }
            int min = 123123123;
            for (int j = 1; j <= n; j++) {
                if (mark[j] == true || Dis[j] == -1) continue;
                if (Dis[j] < min) {
                    min = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d %d\n", Dis[T], cost[T]);
    }

    return 0;
}