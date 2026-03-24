#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, N, q;
    cin >> n >> N >> q;
    vector<list<pair<ll, bool>>> groups(N);
    vector<unordered_map<ll, list<pair<ll, bool>>::iterator>> pos(N);

    while (q--) {
        int op;
        ll addr;
        cin >> op >> addr;

        int group = (addr / n) % N;
        auto& lst = groups[group];
        auto& mp = pos[group];

        if (mp.count(addr)) {
            auto it = mp[addr];
            if (op == 1) {
                it->second = true;
            }
            lst.splice(lst.begin(), lst, it);
        }
        else {
            if (lst.size() >= n) {
                auto victim = lst.back();
                lst.pop_back();
                mp.erase(victim.first);
                if (victim.second) {
                    cout << "1 " << victim.first << '\n';
                }
            }

            lst.push_front({addr, false});
            mp[addr] = lst.begin();

            if (op == 1) {
                lst.begin()->second = true;
            }

            cout << "0 " << addr << '\n';
        }
    }
    return 0;
}