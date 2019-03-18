#include <iostream>
#include <cstring>
#define isLeap(x) (x%4 == 0 && x%100 != 0) || x%400 == 0 ? 1 : 0
using namespace std;

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

int Abs(int x) {
    return x > 0 ? x : -x;
}

int buf[3001][13][32];

char weekDay[7][20] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

char months[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int main() {
    freopen("D:/in.txt", "r", stdin);

    //预处理
    Date temp;
    temp.day = 1;
    temp.month = 1;
    temp.year = 0;
    int cnt = 0;
    while (temp.year != 3001) {
        buf[temp.year][temp.month][temp.day] = cnt;
        cnt++;
        temp.nextDay();
    }

    char s[20];
    int d, m, y;
    while (scanf("%d %s %d", &d, s, &y) != EOF) {
        for (m = 1; m < 13; m++) {
            if (strcmp(months[m], s) == 0) {
                break;
            }
        }

        int between = buf[y][m][d] - buf[2019][3][12];
        between += 2;
        printf("%s\n", weekDay[(between%7+7)%7]);
    }

    return 0;
}