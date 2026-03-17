#include <bits/stdc++.h>
using namespace std;

const int N = 1005, S = 55;
pair<int, int> a[N];
int bb[S][S]; // 存储藏宝图B[i][j]
int n, s, l, ans;
set<pair<int, int>> st; // 存储绿化图中所有树的坐标

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> s;
    
    // 读取绿化图中树的坐标
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
        st.insert(a[i]);
    }
    
    // 读取藏宝图B，注意输入顺序对应B[i][j]
    for (int i = s; i >= 0; i--) {
        for (int j = 0; j <= s; j++) {
            cin >> bb[i][j];
        }
    }
    
    ans = 0;
    // 遍历所有可能的藏宝图左下角位置（即所有树的坐标）
    for (int i = 0; i < n; i++) {
        int x = a[i].first;
        int y = a[i].second;
        // 检查藏宝图是否超出绿化图边界
        if (x + s > l || y + s > l) continue;
        
        bool flag = true;
        // 遍历藏宝图的所有位置，检查是否完全匹配
        for (int dx = 0; dx <= s; dx++) {
            for (int dy = 0; dy <= s; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (bb[dx][dy] == 1) {
                    // B中为1的位置，A中必须有树
                    if (st.find({nx, ny}) == st.end()) {
                        flag = false;
                        break;
                    }
                } else {
                    // B中为0的位置，A中必须无树
                    if (st.find({nx, ny}) != st.end()) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        
        if (flag) ans++;
    }
    
    cout << ans << '\n';
    return 0;
}