#include <iostream>
#include <algorithm>
using namespace std;

#define N 100
int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b;
    int weight;

    bool operator < (const Edge & A) const {
        return weight < A.weight;
    }
} edge[6000];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < N; i++) {
            Tree[i] = -1;
        }
        for (int i = 0; i < (n-1)*n/2; i++) {
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].weight);
        }
        sort(edge, edge+(n-1)*n/2);

        int ans = 0;
        for (int i = 0; i < (n-1)*n/2; i++) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if (b != a) {
                Tree[a] = b;
                ans += edge[i].weight;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}