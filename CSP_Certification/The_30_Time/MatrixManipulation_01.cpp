#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 10005, D = 21;
ll Q[N][D], K[N][D], V[N][D], W[N];
ll n, d;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < d; j++) {
            cin >> K[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
        cin >> W[i];
    }
    vector<vector<ll>> M(d, vector<ll>(d));
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            for (int c = 0; c < n; c++) {
                // 这里相当于直接算了转置矩阵
                M[i][j] += K[c][i] * V[c][j];
            }
        }
    }
    vector<vector<ll>> ans(n, vector<ll>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            ll tmp = 0;
            for (int k = 0; k < d; k++) {
                tmp += Q[i][k] * M[k][j];
            }
            ans[i][j] = W[i] * tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}