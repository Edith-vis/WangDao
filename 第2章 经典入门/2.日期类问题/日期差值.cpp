#include <iostream>
using namespace std;
#define isLeap(x)   (x%100 != 0 && x%4 == 0) || x%400 == 0 ? 1 : 0

int days[13][2] = {
    {0, 0},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31}
};

struct Date{
    int day;
    int month;
    int year;
    void nextDay() {
        day++;
        if (day > days[month][isLeap(year)]) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int buf[5001][13][32];

int ABS(int x) {
    return x>0 ? x : -x;
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    //预处理
    Date temp;
    temp.day = 1;
    temp.month = 1;
    temp.year = 0;
    int cnt = 0;
    while (temp.year != 5001) {
        buf[temp.year][temp.month][temp.day] = cnt;
        temp.nextDay();
        cnt++;
    }

    int y1, m1, d1;
    int y2, m2, d2;
    while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("%d\n", 1+ABS(buf[y1][m1][d1]-buf[y2][m2][d2]) );
    }

    return 0;
}