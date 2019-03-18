#include <iostream>
#include <cstring>
using namespace std;

struct bigInteger{
    int digit[1000];
    int size;

    void init() {
        for (int i = 0; i < 1000; i++) digit[i] = 0;
        size = 0;
    }

    void set(char str[]) {
        init();
        int length = strlen(str);
        for (int i = length-1, j = 0, t = 0, c = 1; i >= 0; i--) {
            t += (str[i]-'0')*c;
            c *= 10;
            j++;
            if (j == 4 || i == 0) {
                digit[size++] = t;
                t = 0;
                c = 1;
                j = 0;
            }
        }
    }

    void output() {
        for (int i = size-1; i >= 0; i--) {
            if (i == size-1) printf("%d", digit[i]);
            else printf("%04d", digit[i]);
        }
        printf("\n");
    }

    bigInteger operator + (const bigInteger & A) const {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < size || i < A.size; i++) {
            int tmp = digit[i] + A.digit[i] + carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        if (carry) ret.digit[ret.size++] = carry;
        return ret;
    }
}a, b, c;

char c1[1002], c2[1002];
int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%s%s", c1, c2) != EOF) {
        a.set(c1);
        b.set(c2);
        c = a+b;
        c.output();
    }

    return 0;
}