#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;
ll n;

struct People {
    ll a, b;
    bool operator<(const People& C) const {
        return abs(a - b) - abs(C.a - C.b) < 0;
    }
}arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr, arr + n);

    ll maxA = arr[0].a;
    ll maxB = arr[0].b;

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].a <= arr[i].b) {
            ans = max(ans, arr[i].a + maxA);
        }
        else {
            ans = max(ans, arr[i].b + maxB);
        }
        maxA = max(maxA, arr[i].a);
        maxB = max(maxB, arr[i].b);
    }
    printf("%.1f\n", (double)ans / 2);
    return 0;
}







