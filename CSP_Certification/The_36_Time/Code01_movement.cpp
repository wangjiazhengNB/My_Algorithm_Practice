#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'f') {
                y = (y + 1) > n ? y : y + 1; 
            }
            else if (s[i] == 'b') {
                y = (y - 1) < 1 ? y : y - 1;
            }
            else if (s[i] == 'l') {
                x = (x - 1) < 1 ? x : x - 1;
            }
            else {
                x = (x + 1) > n ? x : x + 1;
            }
        }
        cout << x << " " << y << '\n';
    }
    return 0;
}