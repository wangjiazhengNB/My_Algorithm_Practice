#include <bits/stdc++.h>
using namespace std;

struct Role {
    vector<string> op;
    vector<string> type;
    vector<string> name;
};

bool check(const Role& r, const string& op, const string& t, const string& n) {
    bool ok1 = false;
    for (auto& s : r.op) {
        if (s == "*" || s == op) {
            ok1 = true;
            break;
        }
    }

    bool ok2 = false;
    for (auto& s : r.type) {
        if (s == "*" || s == t) {
            ok2 = true;
            break;
        }
    }

    bool ok3 = r.name.empty();
    if (!ok3) {
        for (auto& s : r.name) {
            if (s == n) {
                ok3 = true;
                break;
            }
        }
    }
    return ok1 && ok2 && ok3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    unordered_map<string, Role> role;
    map<string, vector<string>> user_to_role;
    map<string, vector<string>> group_to_role;

    for (int i = 0; i < n; ++i) {
        string name;
        int nv, no, nn;
        cin >> name >> nv;
        Role r;
        for (int j = 0; j < nv; ++j) {
            string s;
            cin >> s;
            r.op.push_back(s);
        }
        cin >> no;
        for (int j = 0; j < no; ++j) {
            string s;
            cin >> s;
            r.type.push_back(s);
        }
        cin >> nn;
        for (int j = 0; j < nn; ++j) {
            string s;
            cin >> s;
            r.name.push_back(s);
        }
        role[name] = r;
    }

    for (int i = 0; i < m; ++i) {
        string r_name;
        int ns;
        cin >> r_name >> ns;
        for (int j = 0; j < ns; ++j) {
            string type, obj;
            cin >> type >> obj;
            if (type == "u") {
                user_to_role[obj].push_back(r_name);
            }
            if (type == "g") {
                group_to_role[obj].push_back(r_name);
            }
        }
    }

    while (q--) {
        string username, op, t, n;
        int g_num;
        cin >> username >> g_num;

        vector<string> groups(g_num);
        for (int i = 0; i < g_num; ++i) {
            cin >> groups[i];
        }
        cin >> op >> t >> n;

        bool ans = false;

        for (auto& role_name : user_to_role[username]) {
            if (check(role[role_name], op, t, n)) {
                ans = true;
                break;
            }
        }

        if (ans) {
            cout << 1 << '\n';
            continue;
        }

        for (auto& g : groups) {
            for (auto& role_name : group_to_role[g]) {
                if (check(role[role_name], op, t, n)) {
                    ans = true;
                    goto end_check;
                }
            }
        }

        end_check:
        cout << ans << '\n';
    }
    return 0;
}