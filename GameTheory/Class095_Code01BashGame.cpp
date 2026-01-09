#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 对应Java中的MAXN，定义全局常量
const int MAXN = 1001;
// 对应Java中的二维String数组，全局二维字符串数组存储记忆化结果
string dp[MAXN][MAXN];

// 动态规划验证方法（对应Java的bashGame1）
string bashGame1(int n, int m) {
    if (n == 0) {
        return "后手";
    }
    // C++中判断字符串是否已初始化（非空即已计算过，对应Java的dp[n][m] != null）
    if (!dp[n][m].empty()) {
        return dp[n][m];
    }
    string ans = "后手";
    for (int pick = 1; pick <= m; pick++) {
        // 递归调用，逻辑与Java完全一致
        if (bashGame1(n - pick, m) == "后手") {
            ans = "先手";
            break;
        }
    }
    // 记忆化存储结果
    dp[n][m] = ans;
    return ans;
}

// 正式方法（对应Java的bashGame2）
string bashGame2(int n, int m) {
    // 三元表达式逻辑与Java完全一致
    return (n % (m + 1) != 0) ? "先手" : "后手";
}

// 测试主方法（对应Java的main）
int main() {
    const int V = 500; // 需小于MAXN
    const int testTimes = 5000;
    
    // 初始化随机数种子（C++特有，解决随机数重复问题）
    srand((unsigned int)time(nullptr));
    
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        // 生成随机n和m，对应Java的Math.random()
        int n = rand() % V;
        int m = rand() % V + 1; // 保证m至少为1
        
        string ans1 = bashGame1(n, m);
        string ans2 = bashGame2(n, m);
        
        // 验证两个方法结果是否一致
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
        }
    }
    cout << "测试结束" << endl;
    
    return 0;
}

