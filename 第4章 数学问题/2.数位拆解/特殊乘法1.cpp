#include <iostream>
#include <cstring>
using namespace std;

char str1[11], str2[11];

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%s %s", str1, str2) != EOF) {
        int ans = 0;
        for(int i = 0; i < strlen(str1); i++) {
            for (int j = 0; j < strlen(str2); j++) {
                ans += (str1[i]-'0')*(str2[j]-'0');
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}