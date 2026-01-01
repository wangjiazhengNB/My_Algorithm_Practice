#include <iostream>
#include <string>

using namespace std;

void f(int i, const string& from, const string& to, const string& other);

void hanoi(int n) {
    if (n > 0) {
        f(n, "左", "右", "中");
    }
}

void f(int i, const string& from, const string& to, const string& other) {
    if (i == 1) {
        cout << "移动圆盘 1 从 " << from << " 到 " << to << endl;
    } else {
        f(i - 1, from, other, to);
        cout << "移动圆盘 " << i << " 从 " << from << " 到 " << to << endl;
        f(i - 1, other, to, from);
    }
}

int main() {
    int n1 = 1;
    cout << "n=1 时汉诺塔移动轨迹：" << endl;
    hanoi(n1);

    int n2 = 2;
    cout << "\nn=2 时汉诺塔移动轨迹：" << endl;
    hanoi(n2);

    int n3 = 3;
    cout << "\nn=3 时汉诺塔移动轨迹：" << endl;
    hanoi(n3);

    int n4 = 4;
    cout << "\nn=4 时汉诺塔移动轨迹：" << endl;
    hanoi(n4);

    return 0;
}