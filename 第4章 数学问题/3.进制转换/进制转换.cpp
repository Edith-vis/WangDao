#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int a,b;
    char c[30];
    while (scanf("%d %s %d", &a, c, &b) != EOF) {
        int length = strlen(c);
        int num = 0;
        int n = 1;
        int x;
        for (int i = length-1; i >= 0; i--) {
            if (c[i] >= '0' && c[i] <= '9') {
                x = c[i]-'0';
            } else if (c[i] >= 'a' && c[i] <= 'z') {
                x = c[i] - 'a' + 10;
            } else {
                x = c[i] - 'A' + 10;
            }
            num += x*n;
            n *= a;
        }

        char ans[20];
        length = 0;
        do{
            int x = num%b;
            ans[length++] = x < 10 ? x+'0' : x-10+'A';
            num = num/b;
        } while (num != 0);
        for (int i = length - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }

    return 0;
}