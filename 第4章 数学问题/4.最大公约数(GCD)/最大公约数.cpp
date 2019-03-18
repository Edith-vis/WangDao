#include <iostream>
using namespace std;

int gcd1(int a, int b) {
    if (b == 0) return a;
    return gcd1(b, a%b);
}

int gcd2(int a, int b) {
    while (b != 0) {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {printf("Invalid Input\n"); continue;}
        printf("%d\n", gcd2(a, b));
    }

    return 0;
}