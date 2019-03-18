#include <iostream>
using namespace std;

int buf[50];
int main() {
    freopen("D:/in.txt", "r", stdin);
    int m;
    while (scanf("%d", &m) != EOF && m != 0) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long num = a+b;
        int size1 = 0;
        do {
            buf[size1++] = num%m;
            num = num/m;
        } while(num != 0);
        for(int i = size1-1; i >= 0; i--) {
            printf("%d", buf[i]);
        }
        printf("\n");
    }
    return 0;
}