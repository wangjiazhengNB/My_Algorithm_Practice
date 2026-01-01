#include <bits/stdc++.h>
using namespace std;

// 加inline，提示编译器内联优化
inline int f(int i, int n, int m, vector<vector<int>>& games, vector<int>& cnt) {
    if (i == n) {
        int ans = 0;
        // 局部变量移到循环内部
        for (int j = 0; j < m; j++) {
            int k = games[j][0];
            int b = games[j][1];
            int x = cnt[j];
            // 三元运算符替代std::max，避免函数调用开销，同时防止int溢出
            long long calc = (long long)x * (b - (long long)x * k);
            ans += (calc > 0) ? (int)calc : 0;
        }
        return ans;
    } else {
        int ans = f(i + 1, n, m, games, cnt);
        for (int j = 0; j < m; j++) {
            cnt[j]++;
            ans = max(ans, f(i + 1, n, m, games, cnt));
            cnt[j]--;
        }
        return ans;
    }
}

int enough1(int n, vector<vector<int>>& games) {
    int m = games.size();
    vector<int> cnts(m, 0);
    return f(0, n, m, games, cnts);
}

struct Game {
    int ki;
    int bi;
    int people;

    Game(int a, int b) : ki(a), bi(b), people(0) {}
    // 显式默认拷贝构造，便于编译器优化
    Game(const Game& other) = default;

    int earn() const {
        return bi - (1 + people) * ki - people * ki;
    }
};

struct GameCompare {
    bool operator()(const Game& a, const Game& b) const {
        return a.earn() < b.earn();
    }
};

int enough2(int n, vector<vector<int>>& games) {
    int m = games.size();
    priority_queue<Game, vector<Game>, GameCompare> heap;
    for (auto& g : games) {
        heap.emplace(g[0], g[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (heap.top().earn() <= 0) break;
        Game cur = heap.top();
        heap.pop();

        ans += cur.earn();
        cur.people++;
        heap.push(cur);
    }
    return ans;
}

vector<vector<int>> randomGames(int m, int v) {
    vector<vector<int>> ans(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        ans[i][0] = rand() % v + 1;
        ans[i][1] = rand() % v + 1;
    }
    return ans;
}

int main() {
    srand((unsigned int)time(nullptr));
    int N = 8;
    int M = 8;
    int V = 20;
    int testTimes = 2000;
    cout << "测试开始" << endl;
    // 循环索引从1开始，输出更直观
    for (int i = 1; i <= testTimes; i++) {
        int n = rand() % N + 1;
        int m = rand() % M + 1;
        vector<vector<int>> games = randomGames(m, V);
        int ans1 = enough1(n, games);
        int ans2 = enough2(n, games);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
            // 出错时打印用例，便于调试
            cout << "n=" << n << ", m=" << m << endl;
            break;
        }
        if (i % 100 == 0) {
            cout << "测试到第" << i << "组" << endl;
        }
    }

    cout << "测试结束" << endl;
    return 0;
}