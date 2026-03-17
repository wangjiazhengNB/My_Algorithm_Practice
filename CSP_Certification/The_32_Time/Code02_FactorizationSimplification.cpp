#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Num {
    vector<ll> prime;   
    vector<int> power; 
} num[100]; 

int q, k, idx;
ll n;  


void factorize() {
    for (ll i = 2; i * i <= n; ++i) { 
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            num[idx].prime.push_back(i);
            num[idx].power.push_back(cnt);
        }
    }

    if (n > 1) {
        num[idx].prime.push_back(n);
        num[idx].power.push_back(1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    idx = 0; 
    while (q--) {
        cin >> n >> k;
        num[idx].prime.clear();
        num[idx].power.clear();
        factorize();
        
        ll res = 1;
        for (size_t i = 0; i < num[idx].prime.size(); ++i) {
            if (num[idx].power[i] >= k) {
                ll p = num[idx].prime[i];
                int t = num[idx].power[i];
                ll pow_p = 1;
                for (int j = 0; j < t; ++j) {
                    pow_p *= p;
                }
                res *= pow_p;
            }
        }
        cout << res << '\n';
        idx++;  
    }
    return 0;
}