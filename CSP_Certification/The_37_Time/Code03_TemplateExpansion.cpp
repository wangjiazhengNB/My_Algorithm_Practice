#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> char_to_string;  // 存储变量原始值
unordered_map<string, bool> check;             // 标记是否间接赋值
unordered_map<string, string> memo;             // 【优化1：记忆化缓存】存储已解析的结果
int n;

// 记忆化递归解析函数 + vector<char>高效拼接
string analysis(string& var) {
    // 【记忆化核心】缓存命中，直接返回，不重复计算
    if (memo.find(var) != memo.end()) {
        return memo[var];
    }

    string temp = char_to_string[var];
    vector<char> res;  // 【优化2：vector替代string拼接】高效内存分配

    for (int i = 0; i < temp.size(); ) {
        if (temp[i] == '$') {
            int j = i;
            while (j+1 < temp.size() && temp[j+1] != ' ') j++;
            string name = temp.substr(i+1, j - i);
            // 递归解析，结果存入vector
            string sub = analysis(name);
            for (char c : sub) res.push_back(c);
            i = j + 1;
        } 
        else if (temp[i] == ' ') {
            i++;
        }
        else {
            res.push_back(temp[i]);  // vector尾插，比string+=快
            i++;
        }
    }

    // vector转string，存入缓存
    string ans(res.begin(), res.end());
    memo[var] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n--) {
        int op;
        string var;
        cin >> op >> var;
        if (op == 1) {
            check[var] = false;
            memo.clear();  // 【记忆化】变量更新，清空缓存
            cin.ignore(); 
            string line;
            getline(cin, line);
            vector<char> s;  // vector高效拼接
            for (int i = 0; i < line.size(); ) {
                if (line[i] == '$') {
                    int j = i;
                    while (j+1 < line.size() && line[j+1] != ' ') j++;
                    string name = line.substr(i+1, j - i);
                    string sub = analysis(name);
                    for (char c : sub) s.push_back(c);
                    i = j + 1;
                } 
                else if (line[i] == ' ') {
                    i++;
                }
                else {
                    s.push_back(line[i]);
                    i++;
                }    
            }
            char_to_string[var] = string(s.begin(), s.end());
        } 
        else if (op == 2) {
            check[var] = true;
            memo.clear();  // 【记忆化】变量更新，清空缓存
            cin.ignore();
            string line;
            getline(cin, line);
            char_to_string[var] = line;
        }
        else {
            if (check[var]) {
                cout << analysis(var).size() << '\n';
            }
            else {
                cout << char_to_string[var].size() << '\n';
            }
        }
    }
    return 0;
}