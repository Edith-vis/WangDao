#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int Tree[101];
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
    double length;

    bool operator < (const Edge & A) const {
        return length < A.length;
    }
} edge[6000];

struct Point{
    double x, y;
    double getDistance(Point A) {
        return sqrt((x-A.x)*(x-A.x)+(y-A.y)*(y-A.y));
    }
} point[101];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &point[i].x, &point[i].y);
        }
        int size = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                edge[size].a = i;
                edge[size].b = j;
                edge[size].length = point[i].getDistance(point[j]);
                size++;
            }
        }
        sort(edge, edge+size);

        for (int i = 0; i < 101; i++) {
            Tree[i] = -1;
        }
        double ans = 0;
        for (int i = 0; i < size; i++) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if (b != a) {
                Tree[a] = b;
                ans += edge[i].length;
            }
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}