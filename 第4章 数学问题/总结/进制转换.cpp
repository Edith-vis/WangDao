#include <iostream>
#include <cstring>
using namespace std;

struct bigInteger{
    int digit[100];
    int size;

    void init() {
        for (int i = 0; i < 100; i++) digit[i] = 0;
        size = 0;
    }

    void set(int x) {
        init();
        do {
            digit[size++] = x%10000;
            x /= 10000;
        } while (x != 0);
    }

    bigInteger operator * (int x) const {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < size; i++) {
            int tmp = x*digit[i] + carry;
            ret.digit[ret.size++] = tmp%10000;
            carry = tmp/10000;
        }

        if (carry) ret.digit[ret.size++] = carry;
        return ret;
    }

    bigInteger operator + (const bigInteger & A) const {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < A.size || i < size; i++) {
            int tmp = digit[i] + A.digit[i] + carry;
            ret.digit[ret.size++] = tmp%10000;
            carry = tmp/10000;
        }

        if (carry) ret.digit[ret.size++] = carry;
        return ret;
    }

    bigInteger operator / (int x) const {
        bigInteger ret;
        ret.init();
        int remainder = 0;
        for (int i = size-1; i >= 0; i--) {
            ret.digit[i] = (remainder*10000+digit[i])/x;
            remainder = (remainder*10000+digit[i])%x;
        }

        //确定最高有效位
        ret.size = 0;
        for (int i = 0; i < 100; i++) {
            if (digit[i]!=0) ret.size = i;
        }
        ret.size++;

        return ret;
    }

    int operator % (int x) const {
        int remainder = 0;
        for (int i = size-1; i>=0; i--) {
            remainder = (remainder*10000+digit[i])%x;
        }
        return remainder;
    }

}a, b;

char str[10000], ans[10000];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        scanf("%s", str);
        int length = strlen(str);
        a.set(0);//存m进制转为10进制后的数
        b.set(1);//存中间的十的倍数
        //m进制转10进制
        for (int i = length-1; i >= 0; i--) {
            int t;
            if (str[i] >= '0' && str[i] <= '9') {
                t = str[i] - '0';
            } else {
                t = str[i] - 'A' + 10;
            }

            a = a + b*t;
            b = b*m;
        }

        //10进制转n进制
        int size = 0;
        do {
            int t = a%n;
            ans[size++] = (t > 10) ? t-10+'a' : t+'0';
            a = a/n;
        } while (a.digit[0] != 0 || a.size != 1);

        for (int i = size-1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}