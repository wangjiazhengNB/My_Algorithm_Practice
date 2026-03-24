#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
const int mod = 998244353;

struct Matrix {
    ll m[2][2];
    Matrix() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                m[i][j] = 0;
            }
        }
    }

    static Matrix identity() {
        Matrix res;
        res.m[0][0] = res.m[1][1] = 1;
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

struct Command {
    int type;
    Matrix mat;
};

// 35分代码
// 其余分必须要 可持久化线段树 或者 分块 来做 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Command> cmds(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> cmds[i].type;
        if (cmds[i].type == 1 || cmds[i].type == 2) {
            cin >> cmds[i].mat.m[0][0] >> cmds[i].mat.m[0][1]
            >> cmds[i].mat.m[1][0] >> cmds[i].mat.m[1][1];
        }
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            cin >> pos;
            cin >> cmds[pos].type;
            if (cmds[pos].type == 1 || cmds[pos].type == 2) {
                cin >> cmds[pos].mat.m[0][0] >> cmds[pos].mat.m[0][1]
                >> cmds[pos].mat.m[1][0] >> cmds[pos].mat.m[1][1];
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            deque<Matrix> dq;
            stack<bool> st;
            for (int i = l; i <= r; i++) {
                if (cmds[i].type == 1) {
                    dq.push_front(cmds[i].mat);
                    st.push(true);
                }
                else if (cmds[i].type == 2) {
                    dq.push_back(cmds[i].mat);
                    st.push(false);
                }
                else if (cmds[i].type == 3 && !st.empty()) {
                    bool last = st.top();
                    st.pop();
                    last ? dq.pop_front() : dq.pop_back();
                }
            }

            Matrix ans = Matrix::identity();
            for (auto& mat : dq) {
                ans = ans * mat;
            }
            cout << ans.m[0][0] << " " << ans.m[0][1] << " " 
                 << ans.m[1][0] << " " << ans.m[1][1] << "\n";
        }
    }
    return 0;
}