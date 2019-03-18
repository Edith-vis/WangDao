#include <iostream>
using namespace std;

long long F(int n) {
    if (n == 1) return 2;
    else return 3*F(n-1)+2;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", F(n));
    }

    return 0;
}