#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct stu{
    char name[100];
    int score;
    int id;
}buf[100];

bool cmp0(stu a, stu b) {
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

bool cmp1(stu a, stu b) {
    return a.score != b.score ? a.score < b.score : a.id < b.id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int flag;
    scanf("%d", &flag);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buf[i].name, &buf[i].score);
        buf[i].id = i;
    }
    if (flag == 0) {
        sort(buf, buf+n, cmp0);
    } else {
        sort(buf, buf+n, cmp1);
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", buf[i].name, buf[i].score);
    }

    return 0;
}