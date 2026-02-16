#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int dp[N][26];
string arr[N];
int n;

// 递归函数：当前处理到第i个工件，上一个工件的尾字符是last
// 返回值：从i到末尾，能获得的最大匹配次数
int dfs(int i, char last) {
    // 边界：所有工件处理完，没有更多匹配了
    if (i == n) return 0;
    if (dp[i][last] != -1) return dp[i][last];
    int ans = 0;
    // 选择1：不翻转当前工件
    char head1 = arr[i][0]; // 当前工件的首字符
    char tail1 = arr[i][1]; // 当前工件的尾字符
    int add1 = (head1 == last) ? 1 : 0; // 和上一个匹配，次数+1
    int res1 = add1 + dfs(i + 1, tail1);

    // 选择2：翻转当前工件
    char head2 = arr[i][1]; // 翻转后首字符是原来的尾
    char tail2 = arr[i][0]; // 翻转后尾字符是原来的首
    int add2 = (head2 == last) ? 1 : 0;
    int res2 = add2 + dfs(i + 1, tail2);
    ans = max(res1, res2);
    dp[i][last] = ans;
    // 取两种选择的最大值（匹配次数最多，总长度最小）
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_match = 0;
    // 第一个工件：前面没有字符，所以没有匹配，只需要选翻转/不翻转，记录尾字符
    // 选择1：第一个工件不翻转
    memset(dp, -1, sizeof dp);
    int res1 = dfs(1, arr[0][1]);
    // 选择2：第一个工件翻转
    int res2 = dfs(1, arr[0][0]);
    max_match = max(res1, res2);

    // 计算最终最小长度
    int ans = 2 * n - max_match;
    cout << ans << endl;

    return 0;
}