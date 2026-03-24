#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Block {
    int NN;    // 原文件预期起始行
    int MM;    // 原文件修改行数
    int mm;    // 新文件行数
    vector<string> old_lines;  // 要匹配的原文件片段
    vector<string> new_lines;  // 要替换的新文件片段
};

vector<string> original;  // 原文件（1-based 行号）
vector<Block> blocks;     // 所有补丁块
bool damaged = false;     // 补丁是否损坏

// 解析块头 @@ -NN,MM +nn,mm @@
void parse_block_head(const string& line, int& NN, int& MM, int& mm) {
    vector<string> parts;
    string tmp;
    for (char c : line) {
        if (c == ' ') {
            if (!tmp.empty()) {
                parts.push_back(tmp);
                tmp.clear();
            }
        } else tmp += c;
    }
    // 步骤4：校验块头格式
    if (parts.size() != 4 || parts[0] != "@@" || parts[3] != "@@") {
        damaged = true;
        return;
    }
    // 解析 -NN,MM
    string old_part = parts[1];
    if (old_part.empty() || old_part[0] != '-') { damaged = true; return; }
    old_part = old_part.substr(1);
    size_t comma1 = old_part.find(',');
    if (comma1 == string::npos) { damaged = true; return; }
    NN = stoi(old_part.substr(0, comma1));
    MM = stoi(old_part.substr(comma1+1));
    if (NN <= 0 || MM <= 0) { damaged = true; return; }
    // 解析 +nn,mm（忽略 nn）
    string new_part = parts[2];
    if (new_part.empty() || new_part[0] != '+') { damaged = true; return; }
    new_part = new_part.substr(1);
    size_t comma2 = new_part.find(',');
    if (comma2 == string::npos) { damaged = true; return; }
    mm = stoi(new_part.substr(comma2+1));
    if (mm <= 0) { damaged = true; return; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. 读取原文件
    int n;
    cin >> n;
    cin.ignore();  // 吃掉换行
    original.resize(1);  // 行号从 1 开始（1-based）
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        original.push_back(line);
    }

    // 2. 读取补丁并过滤注释行（# 开头）
    vector<string> patch_lines;
    string line;
    while (getline(cin, line)) {
        // 步骤1：移除 # 开头的注释行
        if (!line.empty() && line[0] == '#') continue;
        patch_lines.push_back(line);
    }

    // 3. 分割补丁块（步骤2）
    vector<int> at_lines;
    for (int i = 0; i < patch_lines.size(); ++i) {
        if (!patch_lines[i].empty() && patch_lines[i].substr(0, 2) == "@@") {
            at_lines.push_back(i);
        }
    }
    if (at_lines.empty()) damaged = true;  // 无块 → 损坏
    else {
        // 4. 解析每个块（步骤3~11）
        int prev_NN_sum_MM = 0;  // 前一个块的 NN + MM
        for (int i = 0; i < at_lines.size(); ++i) {
            Block block;
            int start = at_lines[i];
            int end = (i == at_lines.size()-1) ? patch_lines.size()-1 : at_lines[i+1]-1;

            // 解析块头（步骤4~5）
            parse_block_head(patch_lines[start], block.NN, block.MM, block.mm);
            if (damaged) break;

            // 步骤6：非首块校验 NN ≥ 前一块 NN+MM
            if (i > 0 && block.NN < prev_NN_sum_MM) { damaged = true; break; }
            prev_NN_sum_MM = block.NN + block.MM;

            // 解析块内容（步骤7~11）
            vector<string> old_lines, new_lines;
            for (int j = start+1; j <= end; ++j) {
                const string& l = patch_lines[j];
                if (l.empty()) { damaged = true; break; }
                char op = l[0];
                // 步骤7：行首必须是 - / + / 空格
                if (op != '-' && op != '+' && op != ' ') { damaged = true; break; }
                string cnt = l.substr(1);
                // 步骤8：提取原片段（- 和 空格）
                if (op == '-' || op == ' ') old_lines.push_back(cnt);
                // 步骤10：提取新片段（+ 和 空格）
                if (op == '+' || op == ' ') new_lines.push_back(cnt);
            }
            if (damaged) break;
            // 步骤9：原片段行数 == MM
            if (old_lines.size() != block.MM) { damaged = true; break; }
            // 步骤11：新片段行数 == mm
            if (new_lines.size() != block.mm) { damaged = true; break; }
            block.old_lines = old_lines;
            block.new_lines = new_lines;
            blocks.push_back(block);
        }
    }

    // 提前终止：补丁已损坏
    if (damaged) {
        cout << "Patch is damaged.\n";
        return 0;
    }

    // 5. 应用补丁（步骤12~16）
    int prev_end = 0;  // 前一个块替换后的结束行（1-based）
    for (int idx = 0; idx < blocks.size(); ++idx) {
        Block& b = blocks[idx];
        int NN = b.NN, MM = b.MM, mm = b.mm;
        const vector<string>& old_lines = b.old_lines;
        const vector<string>& new_lines = b.new_lines;

        // 步骤13：寻找合法 δ（|δ| < MM）
        int best_delta = INT_MAX;
        int best_st = -1;
        int max_st = original.size() - MM;  // 原文件 1-based，st + MM -1 ≤ size-1
        for (int delta = -(MM-1); delta <= MM-1; ++delta) {
            int st = NN + delta;
            // 边界校验
            if (st < 1 || st > max_st) continue;
            // 非首块：不重叠 → st ≥ 前一块结束行
            if (idx > 0 && st < prev_end) continue;
            // 片段匹配校验
            bool match = true;
            for (int k = 0; k < MM; ++k) {
                if (original[st + k] != old_lines[k]) {
                    match = false; break;
                }
            }
            if (match) {
                // 步骤14：选最优 δ（绝对值最小，相同则取更小的 δ）
                if (abs(delta) < abs(best_delta) || (abs(delta) == abs(best_delta) && delta < best_delta)) {
                    best_delta = delta;
                    best_st = st;
                }
            }
        }

        // 无合法 δ → 补丁损坏
        if (best_st == -1) { damaged = true; break; }

        // 步骤15：替换原文件片段
        original.erase(original.begin() + best_st, original.begin() + best_st + MM);
        original.insert(original.begin() + best_st, new_lines.begin(), new_lines.end());

        // 步骤16：更新当前块及后续块的 NN
        for (int j = idx; j < blocks.size(); ++j) blocks[j].NN += best_delta;
        prev_end = best_st + new_lines.size();  // 更新前一块结束行
    }

    // 输出结果
    if (damaged) {
        cout << "Patch is damaged.\n";
    } else {
        for (int i = 1; i < original.size(); ++i) {
            cout << original[i] << '\n';
        }
    }

    return 0;
}