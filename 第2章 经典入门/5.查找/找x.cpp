#include <iostream>
using namespace std;

int nums[200];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        int x;
        scanf("%d", &x);
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                index = i;
                break;
            }
        }
        printf("%d\n", index);
    }

    return 0;
}