#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 3 == 0) {
            cout << 2 * n << '\n';
        }
        else {
            cout << n << '\n';
        }
    } 
    return 0;    
}