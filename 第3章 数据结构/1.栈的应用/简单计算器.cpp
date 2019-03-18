#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<int> op;
stack<double> in;
char str[220];

int mat[5][5] = {
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0}
};

void getOp(bool &reto, int &retn, int &i) {
    if ((i == 0 && op.empty()) || str[i] == 0) {
        reto = true;
        retn = 0;
        return;
    } else if (str[i] >= '0' && str[i] <= '9') {
        reto = false;
        retn = 0;
        for(; !(str[i] == 0 || str[i] == ' '); i++) {
            retn *= 10;
            retn += str[i]-'0';
        }
        if (str[i] == ' ') {
            i++;
        }
        return;
    } else {
        reto = true;
        if (str[i] == '+') {
            retn = 1;
        } else if (str[i] == '-') {
            retn = 2;
        } else if (str[i] == '*') {
            retn = 3;
        } else {
            retn = 4;
        }
        i += 2;
        return;
    } 
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    while (gets(str)) {
        if (str[0] == '0' && str[1] == 0) break;
        while(!op.empty()) op.pop();
        while(!in.empty()) in.pop();
        bool retop; int retnum; int idx = 0;
        while(true) {
            getOp(retop, retnum, idx);
            if (retop == false) {//是操作数
                in.push((double)retnum);
            } else {//是操作符
                if (op.empty() || mat[retnum][op.top()] == 1) {
                    op.push(retnum);
                } else {
                    while (mat[retnum][op.top()] == 0) {
                        double tmp;
                        int ret = op.top();
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();

                        if (ret == 1) tmp = a+b;
                        else if (ret == 2) tmp = a-b;
                        else if (ret == 3) tmp = a*b;
                        else if (ret == 4) tmp = a/b;
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }

            if(op.size() == 2 && op.top() == 0) break;
        }
        printf("%.2lf\n", in.top());

    }

    return 0;
}