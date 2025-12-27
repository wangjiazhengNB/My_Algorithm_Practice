#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int ring[N], key[N];
int sizes[N], where[N][N];
int dp[N][N];
int n, m;

int f(int i, int j);
int clocksun(int i, int t);
int clockni(int i, int t);

void build(string& r, string& k) {
    n = r.size();
    m = k.size();
    memset(sizes, 0, sizeof sizes);
    memset(dp, -1, sizeof dp);
    memset(where, 0, sizeof where);
    for (int i = 0; i < n; i++) {
        int v = r[i] - 'a';
        where[v][sizes[v]++] = i;
        ring[i] = v;
    }
    for (int i = 0; i < m; i++) {
        int v = k[i] - 'a';
        key[i] = v;
    }
}

int f(int i, int j) {
    if (j == m) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (ring[i] == key[j]) {
        ans = 1 + f(i, j + 1);
    }
    else {
        int jump1 = clocksun(i, key[j]);
        int distance1 = (jump1 > i) ? (jump1 - i) : (n - i + jump1);
        int jump2 = clockni(i, key[j]);
        int distance2 = (jump2 > i) ? (n + i - jump2) : (i - jump2);
        ans = min(distance1 + f(jump1, j), distance2 + f(jump2, j));
    }
    dp[i][j] = ans;
    return ans;
}

int clocksun(int i, int t) {
    int l = 0, r = sizes[t] - 1, m;
    int *sun = where[t];
    int ans = -1;
    while (l <= r) {
        m = l + r >> 1;
        if (sun[m] > i) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans == -1 ? sun[0] : sun[ans];
}

int clockni(int i, int t) {
    int l = 0, r = sizes[t] - 1, m;
    int ans = -1;
    int *ni = where[t];
    while (l <= r) {
        m = l + r >> 1;
        if (ni[m] < i) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return ans == -1 ? ni[sizes[t] - 1] : ni[ans];
}

int findRotateSteps(string r, string k) {
    build(r, k);
    return f(0, 0);
}

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return ::findRotateSteps(ring, key);
    }
};

int main() {
    return 0;
}