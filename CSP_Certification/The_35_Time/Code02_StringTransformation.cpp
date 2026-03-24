// 暴力写法 80分，看到k这么大就知道要用倍增算法了，需要构建st表

/*
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string line;
    getline(cin, line);
    string s = line.substr(1, line.size() - 2);
    
    int n;
    cin >> n;
    cin.ignore();
    
    unordered_map<char, char> mp;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        char a = line[1];
        char b = line[2];
        mp[a] = b;
    }
    
    int q;
    cin >> q;
    while (q--) {
        string current = s;
        int k;
        cin >> k;
        for (int step = 0; step < k; step++) {
            string next_str;
            for (char c : current) {
                if (mp.count(c)) 
                    next_str += mp[c];
                else 
                    next_str += c;
            }
            current = next_str; // 
        }
        cout << "#" << current << "#\n";
    }
    return 0;
}
*/


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int CHAR_CNT = 256;
const int LIMIT = 30;
string s;
int n;

char stjump[CHAR_CNT][LIMIT];

void build(unordered_map<char, char>& func) {
    // 初始化
    for (int c = 0; c < CHAR_CNT; c++) {
        stjump[c][0] = c;
    }
    for (auto& [c, cc] : func) {
        stjump[c][0] = cc;
    }

    // 倍增，填st表
    for (int p = 1; p < LIMIT; p++) {
        for (int c = 0; c < CHAR_CNT; c++) {
            stjump[c][p] = stjump[stjump[c][p - 1]][p - 1];
        }
    }
}

char jump(char c, int k) {
    char cur = c;
    for (int p = LIMIT - 1; p >= 0; p--) {
        if (k & (1 << p)) {
            cur = stjump[cur][p];
        }
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string line;
    getline(cin, line);
    s = line.substr(1, line.size() - 2);
    cin >> n;
    cin.ignore();
    unordered_map<char, char> func;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        char a = line[1], b = line[2];
        func[a] = b;
    }

    build(func);

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        string res;
        for (char c : s) {
            res += jump(c, k);
        }
        cout << "#" << res << "#\n";
    }
    return 0;
}

