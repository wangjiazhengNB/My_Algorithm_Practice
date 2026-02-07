#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, k;
    long long o = 0;
    cin >> x >> y;
    if(y >= (-x) && y <= x)//纵轴右方
    {
        k = x * 2 * x * 2 + (x - y);
    }
    else if(y <= (-x) && y > x)//纵轴左方
    {
        long long x2 = x;
        x = -x;
        k = (x * 2 - 1) * (x * 2 - 1) + (y - x2 - 1);
    }
    else if(y >= 0)//横轴上方
    {
        k = 2 * y * 2 * y - (y-x);
    }
    else if(y < 0)//横轴下方
    { 
        long long io = -y * 2;
        k=(io * (io + 1))+(-y -x + 1);
    }
    cout << k;
}
