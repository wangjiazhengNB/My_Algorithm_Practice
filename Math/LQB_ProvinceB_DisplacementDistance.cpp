#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    double x = 233, y = 666;
    double r = sqrt(x * x + y * y);
    double theta = atan2(y, x);
    cout << round(r * (1 + theta)) << '\n';
    return 0;
}