#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int h;
    while (scanf("%d", &h) != EOF) {
        int length = h + (h-1)*2;
        for (int i = 1; i <= h; i++) {
            int j = 0;
            for (j = 1; j <= length-h-2*(i-1); j++) {
                printf(" ");
            }
            for (;j <= length; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}