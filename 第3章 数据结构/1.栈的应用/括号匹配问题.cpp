#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> s;
char str[101];
char ans[101];

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (scanf("%s", str) != EOF) {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                s.push(i);
                ans[i] = ' ';
            } else if (str[i] == ')') {
                if (!s.empty()) {
                    s.pop();
                    ans[i] = ' ';
                } else {
                    ans[i] = '?';
                }
            } else {
                ans[i] = ' ';
            }
        }

        while (!s.empty()) {
            int temp = s.top();
            ans[temp] = '$';
            s.pop();
        }

        puts(str);
        puts(ans);
    }
    

    return 0;
}