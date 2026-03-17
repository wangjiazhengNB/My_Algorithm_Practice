#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

struct Node {
    ll val;
    ll der;
    Node(ll v = 0, ll d = 0) : val(v), der(d) {}
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin.ignore();

    string line;
    getline(cin, line);
    vector<string> tokens;

    string token;
    for (auto& c : line) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            token += c;
        }
    }
    if (!token.empty()) tokens.push_back(token);

    for (int q = 0; q < m; q++) {
        int k;
        cin >> k;
        k--;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= mod;
        }

        stack<Node> st;
        for (const string& t : tokens) {
            if (t[0] == 'x') {
                int idx = stoi(t.substr(1)) - 1;
                if (idx == k) st.emplace(a[idx], 1);
                else st.emplace(a[idx], 0);
            }
            else if (t == "+" || t == "-" || t == "*") {
                Node B = st.top();
                st.pop();
                Node A = st.top();
                st.pop();

                Node res;
                if (t == "+") {
                    res.val = (A.val + B.val) % mod;
                    res.der = (A.der + B.der) % mod;
                }
                else if (t == "-") {
                    res.val = (A.val - B.val + mod) % mod;
                    res.der = (A.der - B.der + mod) % mod;
                }
                else if (t == "*") {
                    res.val = (A.val * B.val) % mod;
                    ll term1 = (A.val * B.der) % mod;
                    ll term2 = (A.der * B.val) % mod;
                    res.der = (term1 + term2) % mod;
                }
                st.push(res);
            }
            else {
                ll num = stoll(t) % mod;
                st.emplace(num, 0);
            }
        }

        ll ans = st.top().der % mod;
        ans = (ans + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}