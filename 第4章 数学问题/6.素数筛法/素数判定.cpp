#include <iostream>
#include <cmath>
using namespace std;

bool judge(int x) {
    if (x <= 1) return false;
    int bound = (int)sqrt(x) + 1;
    for (int i = 2; i < bound; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        puts(judge(x) ? "Yes": "No");
    }
    return 0;
}