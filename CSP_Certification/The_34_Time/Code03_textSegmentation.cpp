#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


// 80 分的题解， 满分要用链表的写法，麻烦
vector<pair<vector<string>, int>> init_map;
vector<string> ans;
int n, m, sumlen;
bool flag = false;

struct Candidate {
    int count;
    int concat_len;
    int first_len;
    string concat_str;
};

bool is_better(const Candidate& a, const Candidate& b) {
    if (a.count != b.count) return a.count > b.count;
    if (a.concat_len != b.concat_len) return a.concat_len < b.concat_len;
    if (a.first_len != b.first_len) return a.first_len < b.first_len;
    return a.concat_str < b.concat_str;
}

void update(string str) {
    vector<pair<vector<string>, int>> new_map;
    for (auto& entry : init_map) {
        vector<string> vec = entry.first;
        int freq = entry.second;
        for (int i = 0; i < (int)vec.size() - 1; ++i) {
            if (vec[i] + vec[i+1] == str) {
                vec[i] = str;
                vec.erase(vec.begin() + i + 1);
                break;
            }
        }
        new_map.emplace_back(vec, freq);
    }
    init_map = move(new_map); 
}

void process() {
    map<pair<string, string>, int> pair_cnt;
    for (auto& entry : init_map) {
        auto& chars = entry.first;
        int num = entry.second;
        for (int i = 0; i < (int)chars.size() - 1; i++) {
            string s1 = chars[i], s2 = chars[i+1];
            pair_cnt[{s1, s2}] += num;
        }
    }

    if (pair_cnt.empty()) {
        flag = true;
        return;
    }

    Candidate best;
    best.count = -1;
    for (auto& entry : pair_cnt) {
        string s1 = entry.first.first;
        string s2 = entry.first.second;
        Candidate cur;
        cur.count = entry.second;
        cur.concat_len = s1.size() + s2.size();
        cur.first_len = s1.size();
        cur.concat_str = s1 + s2;
        
        if (best.count == -1 || is_better(cur, best)) {
            best = cur;
        }
    }

    ans.push_back(best.concat_str);
    if (best.concat_str.size() == sumlen) {
        flag = true;
        return;
    }
    update(best.concat_str);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    set<char> alphbet;
    for (int i = 0; i < n; i++) {
        string s;
        int num;
        cin >> s >> num;
        sumlen += s.size();
        vector<string> char_vec;
        for (int j = 0; j < s.size(); j++) {
            char_vec.emplace_back(1, s[j]);
            alphbet.emplace(s[j]);
        }
        init_map.emplace_back(char_vec, num);
    }

    for (auto& c : alphbet) {
        if (ans.size() == m) break;
        ans.emplace_back(1, c);
    }
    while (ans.size() < m && !flag) {
        process();
    }

    for (auto& res : ans) {
        cout << res << '\n';
    }
    return 0;
}


// 满分题解
/*
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

vector<string> vocab;             
map<char, int> char_id;          
list<int> seq;                   
unordered_map<ll, int> pair_cnt; 
vector<string> ans;              
int n, m, total_len;             

struct Node {
    int cnt;    // 频率
    int cl;     // 拼接长度
    int fl;     // 前词长度
    string str; // 拼接结果
    ll key;     // 相邻对编码

    bool operator<(const Node& t) const {
        if (cnt != t.cnt) return cnt < t.cnt;
        if (cl != t.cl) return cl > t.cl;
        if (fl != t.fl) return fl > t.fl;
        return str > t.str;
    }
};
priority_queue<Node> q;

ll get_key(int a, int b) {
    return (ll)a << 32 | b;
}

void init() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    set<char> st;
    vector<pair<string, int>> words;

    for (int i=0; i<n; i++) {
        string s; int f;
        cin >> s >> f;
        words.emplace_back(s, f);
        for (char c : s) st.insert(c);
        total_len += s.size() * f;
    }

    int id = 0;
    for (char c : st) {
        char_id[c] = id;
        vocab.emplace_back(1, c);
        ans.push_back(vocab[id++]);
    }

    for (auto& [s, f] : words) {
        vector<int> cur;
        for (char c : s) cur.push_back(char_id[c]);
        for (int i=0; i<f; i++)
            for (int x : cur)
                seq.push_back(x);
    }

    if (seq.size() < 2) return;
    auto it = seq.begin();
    int pre = *it; it++;
    for (; it!=seq.end(); it++) {
        ll key = get_key(pre, *it);
        pair_cnt[key]++;
        pre = *it;
    }

    for (auto& [key, cnt] : pair_cnt) {
        int a = key >> 32, b = key & 0xFFFFFFFF;
        string s = vocab[a] + vocab[b];
        // 修复点1：强转int消除警告
        q.push({cnt, (int)s.size(), (int)vocab[a].size(), s, key});
    }
}

void merge() {
    while (ans.size() < m) {
        while (!q.empty()) {
            Node top = q.top();
            if (pair_cnt.count(top.key) && pair_cnt[top.key] == top.cnt)
                break;
            q.pop();
        }
        if (q.empty()) break;

        Node now = q.top(); q.pop();
        ll key = now.key;
        int a = key >> 32, b = key & 0xFFFFFFFF;
        string new_str = now.str;
        int new_id = vocab.size();
        vocab.push_back(new_str);
        ans.push_back(new_str);

        if (ans.size() == m || new_str.size() == total_len) break;

        if (seq.size() < 2) break;
        auto it = seq.begin();
        int pre = *it; it++;

        while (it != seq.end()) {
            int cur = *it;
            if (pre == a && cur == b) {
                it = seq.erase(it);
                auto pre_it = prev(it);
                *pre_it = new_id;

                if (pre_it != seq.begin()) {
                    int l = *prev(pre_it);
                    ll old_k = get_key(l, a);
                    if (--pair_cnt[old_k] == 0) pair_cnt.erase(old_k);
                    ll new_k = get_key(l, new_id);
                    pair_cnt[new_k]++;
                    // 修复点2：强转int消除警告
                    q.push({pair_cnt[new_k], (int)vocab[l].size() + (int)new_str.size(), (int)vocab[l].size(), vocab[l]+new_str, new_k});
                }
                if (it != seq.end()) {
                    int r = *it;
                    ll old_k = get_key(b, r);
                    if (--pair_cnt[old_k] == 0) pair_cnt.erase(old_k);
                    ll new_k = get_key(new_id, r);
                    pair_cnt[new_k]++;
                    // 修复点3：强转int消除警告
                    q.push({pair_cnt[new_k], (int)new_str.size() + (int)vocab[r].size(), (int)new_str.size(), new_str+vocab[r], new_k});
                }

                if (it == seq.end()) break;
                pre = *pre_it;
            } else {
                pre = cur;
                it++;
            }
        }
    }
}

int main() {
    init();
    merge();
    for (auto& s : ans) cout << s << '\n';
    return 0;
}
*/