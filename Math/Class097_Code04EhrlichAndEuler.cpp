#include <bits/stdc++.h>
using namespace std;


//埃氏筛法
int ehrlich(int n) {
    vector<bool> vis(n + 1, false);
    for (int i = 2; i * i <= n; i++) {
        if (!vis[i]) {
            for (int j = i * i; j <= n; j += i) {
                vis[j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) cnt++;
    }
    return cnt;
}


//欧拉筛法
int euler(int n) {
    vector<bool> visit(n + 1, false);
    vector<int> prime(n / 2 + 1);
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (!visit[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (i * prime[j] > n) {
                break;
            }
            visit[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}