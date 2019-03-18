#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    int score;
} buf[100];

bool cmp(stu a, stu b) {
    return a.score != b.score ? a.score < b.score : a.id < b.id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &buf[i].id, &buf[i].score);
    }
    sort(buf, buf+n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", buf[i].id, buf[i].score);
    }
    return 0;
}