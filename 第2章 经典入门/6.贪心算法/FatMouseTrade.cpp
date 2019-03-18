#include <iostream>
#include <algorithm>
using namespace std;

struct goods{
    double j;//物品总重
    double f;//物品总价值
    double s;//物品性价比

    bool operator < (const goods & a) const {//性价比高的在前
        return s > a.s;
    }

}buf[1000];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m;//我有的钱
    int n;//物品个数
    while (scanf("%d%d", &m, &n) != EOF) {
        if (m == -1 && n == -1) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j/buf[i].f;
        }
        sort(buf, buf+n);
        int idx = 0;
        double res = 0;
        while(m > 0 && idx < n) {
            if (m > buf[idx].f) {
                res += buf[idx].j;
                m -= buf[idx].f;
            } else {
                res += m/buf[idx].f*buf[idx].j;
                m = 0;
                break;
            }
            idx++;
        }
        printf("%.3lf\n", res);
    }

    return 0;
}