#include <bits/stdc++.h>
using namespace std;

int where;

class Solution {
public:
    string countOfAtoms(string s) {
        where = 0;
        map<string, int> atomMap = f(s, 0);
        string ans;
        for (auto& entry : atomMap) {
            ans += entry.first;
            int cnt = entry.second;
            if (cnt > 1) {
                ans += to_string(cnt);
            }
        }
        return ans;
    }

    // 核心修改1：将pre从指针改为值类型，新增preValid标记是否有效
    map<string, int> f(const string& s, int i) {
        map<string, int> ans;
        string name;
        map<string, int> pre; // 替换原const map<string, int>* pre = nullptr;
        bool preValid = false; // 标记pre是否有有效数据（替代指针判空）
        int cnt = 0;

        while (i < s.size() && s[i] != ')') {
            if ((s[i] >= 'A' && s[i] <= 'Z') || s[i] == '(') {
                // 调用fill时传入pre和preValid
                fill(ans, name, pre, preValid, cnt);
                name.clear();
                pre.clear(); // 清空pre
                preValid = false; // 重置标记
                cnt = 0;
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    name.push_back(s[i++]);
                } else {
                    // 核心修改2：直接赋值给pre，而非指针
                    pre = f(s, i + 1);
                    preValid = true; // 标记pre有有效数据
                    i = where + 1;
                }
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                name.push_back(s[i++]);
            } else {
                cnt = cnt * 10 + (s[i] - '0');
                i++;
            }
        }
        // 处理最后一段数据
        fill(ans, name, pre, preValid, cnt);
        where = i;
        return ans;
    }

    // 核心修改3：调整fill参数，用preValid替代指针判空，移除指针
    void fill(map<string, int>& ans, const string& name, const map<string, int>& pre, bool preValid, int cnt) {
        // 原!name.empty() || pre != nullptr → 改为!name.empty() || preValid
        if (!name.empty() || preValid) {
            cnt = (cnt == 0) ? 1 : cnt;
            if (name.size() > 0) {
                ans[name] = ans.find(name) != ans.end() ? ans[name] + cnt : cnt;
            } else {
                // 直接遍历pre（值拷贝后的有效数据），无悬空指针问题
                for (const auto& entry : pre) {
                    const string& key = entry.first;
                    int val = entry.second;
                    ans[key] = ans.find(key) != ans.end() ? ans[key] + val * cnt : val * cnt;
                }
            }
        }
    }
};

int main() {
    return 0;
}