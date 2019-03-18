#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;//小顶堆:堆顶元素为最小的元素

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        while (!Q.empty()) Q.pop();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Q.push(x);
        }
        int ans = 0;
        while (Q.size() >= 2) {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a+b;
            Q.push(a+b);
        }
        printf("%d", ans);
    }
    return 0;
}