#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct stu {
    char no[20];
    char name[20];
    char sex[20];
    int age;

    bool operator < (const stu & a) const {
        return strcmp(no, a.no) < 0;
    }
}buf[1000];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s %s %s %d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
        }
        sort(buf, buf+n);
        int t;
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            char no[20];
            scanf("%s", no);

            //二分查找
            int ans = -1;
            int left = 0, right = n-1;
            while (left <= right) {
                int mid = (left+right)/2;
                int temp = strcmp(no, buf[mid].no);
                if (temp == 0) {
                    ans = mid;
                    break;
                } else if (temp < 0) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }

            if (ans == -1) {
                printf("No Answer!\n");
            } else {
                printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
            }
        }

        
    }

    return 0;
}