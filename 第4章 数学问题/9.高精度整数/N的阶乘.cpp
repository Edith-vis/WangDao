#include <iostream>
#include <cstring>
using namespace std;

struct bigInteger
{
    int digit[1000];
    int size;

    void init() {
        for (int i = 0; i < 1000; i++) digit[i] = 0;
        size = 0;
    }

    void set(int x) {
        init();
        do {
            digit[size++] = x%10000;
            x /= 10000;
        } while (x!= 0);
    }

    void output() {
        for (int i = size-1; i >= 0; i--) {
            if (i == size-1) printf("%d", digit[i]);
            else printf("%04d", digit[i]);
        }
        printf("\n");
    }

    bigInteger operator * (int x) const {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < size; i++) {
            int tmp = x*digit[i]+carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        if (carry) ret.digit[ret.size++] = carry;
        return ret;
    }
}a;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        a.init();
        a.set(1);
        for (int i = 1; i <= n; i++) {
            a=a*i;
        }
        a.output();
    }

    return 0;
}