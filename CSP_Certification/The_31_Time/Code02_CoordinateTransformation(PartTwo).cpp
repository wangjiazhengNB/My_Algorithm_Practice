#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 100005;
pair<int, double> ops[N];
double scale_prefix[N];
double rot_prefix[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(3);
    
    int n, m;
    cin >> n >> m;

    scale_prefix[0] = 1.0;
    rot_prefix[0] = 0.0;

    for (int i = 1; i <= n; i++) {
        cin >> ops[i].first >> ops[i].second;
        if (ops[i].first == 1) {
            scale_prefix[i] = scale_prefix[i-1] * ops[i].second;
            rot_prefix[i] = rot_prefix[i-1];
        } else {
            scale_prefix[i] = scale_prefix[i-1];
            rot_prefix[i] = rot_prefix[i-1] + ops[i].second;
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        double x, y;
        cin >> l >> r >> x >> y;

        double total_rot = rot_prefix[r] - rot_prefix[l-1];
        double total_scale = scale_prefix[r] / scale_prefix[l-1];

        double cos_rot = cos(total_rot);
        double sin_rot = sin(total_rot);
        
        double new_x = x * cos_rot - y * sin_rot;
        double new_y = x * sin_rot + y * cos_rot;
        new_x *= total_scale;
        new_y *= total_scale;

        cout << new_x << " " << new_y << '\n';
    }
    return 0;
}