#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int INF = 1e9;
int n, k;
int a[25];
int dp[1 << 20][2];

bool allSame() {
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) return false;
    }
    return true;
}

int solveTask2() {
    int v = a[0];
    int len = (n + 1) / 2;
    if (k == 1) {
        cout << len * v << '\n';
    }
    else {
        if (n % 2 == 1) {
            cout << v << '\n';
        }
        else {
            cout << len * v << '\n';
        }
    }
}

int count1(int status) {
    int cnt = 0;
    while (status) {
        cnt += status & 1;
        x >>= 1;
    }
    return cnt; 
}

int ctz(int status) {
    int cnt = 0;
    while ((status & 1) == 0) {
        cnt++;
        status >>= 1;
    }
    return cnt;
}

int clz(int status) {
    int cnt = 0;
    for (int i = 31; i >= 0; i--) {
        if ((status >> i) & 1) break;
        cnt++;
    }
    return cnt;
}

int f(int status, int who) {
    int cnt = count1(status);
    if (cnt == 1) {
        int pos = ctz(status);
        return a[pos];
    }

    if (dp[status][who] != -1) return dp[status][who];
    int res = 0;
    if (who == 0) res = INF;
    else res = -INF;

    int left = 31 - clz(status);
    int op1 = f(status ^ (1 << left), 1 - who);
    if (who == 0) res = min(res, op1);
    else res = max(res, op1);

    int right = ctz(status);
    int op2 = f(status ^ (1 << right), 1 - who);
    if (who == 0) res = min(res, op2);
    else res = max(res, op2);

    for (int i = 0; i < n - 1; i++) {
        if ((status & (1 << i)) && (status & (1 << i + 1))) {
            int new_st = status & ~(1 << i) & ~(1 << i + 1);
            new_st |= (1 << i);
            int temp = a[i];
            a[i] += a[i + 1];
            int op3 = f(new_st, 1 - who);
            a[i] = temp;

            if (who == 0) res = min(res, op3);
            else res = max(res, op3);
        }
    }

    dp[status][who] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (allSame()) {
        cout << solveTask2() << '\n';
        return 0;
    }
    cout << f((1 << n) - 1, k) << endl;
    return 0;
}