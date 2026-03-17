#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 十六进制字符转数值（处理小写a-f）
uint8_t char_to_hex(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    return 0; // 题目保证输入合法，无需处理异常
}

// 解析导引域，返回原始数据长度，同时移除code中的导引域字节
uint32_t extract_l(vector<uint8_t>& code) {
    uint32_t original_len = 0;
    uint32_t mul = 1; // 128^k 的权重，初始为128^0=1
    int read_cnt = 0;

    while (read_cnt < code.size()) {
        uint8_t byte = code[read_cnt];
        uint8_t c_k = byte & 0x7F; // 取低7位
        original_len += c_k * mul;
        read_cnt++;

        // 最高位为0，导引域结束
        if ((byte & 0x80) == 0) break;
        mul *= 128;
    }

    // 移除已解析的导引域字节
    code.erase(code.begin(), code.begin() + read_cnt);
    return original_len;
}

// 核心解压缩逻辑，输入去除导引域的字节流，返回解压后的原始字节
vector<uint8_t> decompress(const vector<uint8_t>& code) {
    vector<uint8_t> decompressed;
    int ptr = 0;
    int code_len = code.size();

    while (ptr < code_len) {
        uint8_t header = code[ptr];
        uint8_t elem_type = header & 0x03; // 最低两位为元素类型

        if (elem_type == 0x00) { // 字面量类型
            ptr++;
            uint32_t data_len;
            uint8_t high6 = header >> 2;

            if (high6 <= 60) {
                // 长度直接存在高6位
                data_len = high6 + 1;
            } else {
                // 高6位为60/61/62/63，对应后续1/2/3/4字节存长度（小端序）
                int byte_cnt = high6 - 60 + 1;
                data_len = 0;
                for (int i = 0; i < byte_cnt; i++) {
                    data_len |= (uint32_t)code[ptr + i] << (8 * i);
                }
                data_len += 1;
                ptr += byte_cnt;
            }

            // 追加字面量数据到结果
            for (uint32_t i = 0; i < data_len; i++) {
                decompressed.push_back(code[ptr + i]);
            }
            ptr += data_len;
        }
        else if (elem_type == 0x01) { // 短回溯引用 (4≤l≤11, 0<o≤2047)
            ptr++;
            // 解析长度l
            uint8_t l_part = (header >> 2) & 0x07;
            uint32_t l = l_part + 4;
            // 解析偏移量o
            uint8_t o_high = (header >> 5) & 0x07;
            uint8_t o_low = code[ptr];
            uint32_t o = (o_high << 8) | o_low;
            ptr++;

            // 循环复制数据（自动处理o<l的循环场景）
            int start_pos = decompressed.size() - o;
            for (uint32_t i = 0; i < l; i++) {
                decompressed.push_back(decompressed[start_pos + i]);
            }
        }
        else if (elem_type == 0x02) { // 长回溯引用 (1≤l≤64, 0<o≤65535)
            ptr++;
            // 解析长度l
            uint8_t high6 = header >> 2;
            uint32_t l = high6 + 1;
            // 解析偏移量o（小端序）
            uint8_t o_low = code[ptr];
            uint8_t o_high = code[ptr + 1];
            uint32_t o = (uint32_t)o_high << 8 | o_low;
            ptr += 2;

            // 循环复制数据
            int start_pos = decompressed.size() - o;
            for (uint32_t i = 0; i < l; i++) {
                decompressed.push_back(decompressed[start_pos + i]);
            }
        }
        // elem_type=0x03为非法格式，题目保证输入合法，无需处理
    }
    return decompressed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input_byte_cnt;
    cin >> input_byte_cnt;
    cin.ignore(); // 忽略输入数字后的换行符，避免getline读空行

    int line_cnt = (input_byte_cnt + 7) / 8; // 计算输入行数，向上取整
    vector<uint8_t> code;

    // 读取所有输入行，转成字节数组
    for (int i = 0; i < line_cnt; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < line.size(); j += 2) {
            uint8_t high = char_to_hex(line[j]);
            uint8_t low = char_to_hex(line[j + 1]);
            code.push_back((high << 4) | low);
        }
    }

    // 解析导引域，获取原始数据长度
    uint32_t expect_len = extract_l(code);
    // 执行解压缩
    vector<uint8_t> result = decompress(code);

    // 格式化输出，每行8个字节，小写十六进制
    const char hex_table[] = "0123456789abcdef";
    for (int i = 0; i < result.size(); i++) {
        uint8_t byte = result[i];
        cout << hex_table[(byte >> 4) & 0x0F] << hex_table[byte & 0x0F];
        if ((i + 1) % 8 == 0) {
            cout << '\n';
        }
    }
    // 最后一行不足8个字节时补充换行
    if (result.size() % 8 != 0) {
        cout << '\n';
    }

    return 0;
}