#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005, M = 200005;

int n, m, f[N];
struct Edge {
	int a, b, c;
	bool operator<(const Edge &C)const {
		return c < C.c;
	}
}edge[M]; 

int find(int x) {
	if (x != f[x]) f[x] = find(f[x]);
	return f[x];
}

bool merge(int x, int y) {
	if (x == y) return false;
	f[y] = x;
	return true;
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	int a, b, c;
    	cin >> edge[i].a >> edge[i].b >> edge[i].c;
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	sort(edge + 1, edge + m + 1);
	ll ans = 0;
	int k = 0;
	for (int i = 1; i <= m; i++) {
		int fa = find(edge[i].a), fb = find(edge[i].b); 
		if (merge(fa, fb)) {
			k++;
			ans += edge[i].c;
		}
	}
	if (k == n - 1) cout << ans;
	else {
		cout << "orz";
	}
    return 0;
}