#include <bits/stdc++.h>
using namespace std;

vector<int> bitSet;
int bitSetSize = 0;

void bitset_init(int n) {
    bitSetSize = n;
    int len = (n + 31) / 32;
    bitSet.assign(len, 0); 
}

void bitset_add(int num) {
    if (num < 0 || num >= bitSetSize) return;
    int index = num / 32;
    int offset = num % 32;
    bitSet[index] |= (1 << offset);
}

void bitset_remove(int num) {
    if (num < 0 || num >= bitSetSize) return;
    int index = num / 32;
    int offset = num % 32;
    bitSet[index] &= ~(1 << offset);
}

void bitset_reverse(int num) {
    if (num < 0 || num >= bitSetSize) return;
    int index = num / 32;
    int offset = num % 32;
    bitSet[index] ^= (1 << offset);
}

bool bitset_contains(int num) {
    if (num < 0 || num >= bitSetSize) return false;
    int index = num / 32;
    int offset = num % 32;
    return ((bitSet[index] >> offset) & 1) == 1;
}

void bitset_destroy() {
    vector<int>().swap(bitSet);
    bitSetSize = 0;
}

int main() {
    int n = 1000;
    int testTimes = 10000;
    cout << "测试开始" << endl;
    
    // 初始化位图
    bitset_init(n);
    // 使用unordered_set做对比测试
    unordered_set<int> hashSet;
    
    // 设置随机数种子
    srand((unsigned int)time(nullptr));
    
    cout << "调用阶段开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        double decide = (double)rand() / RAND_MAX; // 生成0~1的随机数
        int number = rand() % n; // 生成0~n-1的随机数
        
        if (decide < 0.333) {
            bitset_add(number);
            hashSet.insert(number);
        } else if (decide < 0.666) {
            bitset_remove(number);
            hashSet.erase(number);
        } else {
            bitset_reverse(number);
            if (hashSet.find(number) != hashSet.end()) {
                hashSet.erase(number);
            } else {
                hashSet.insert(number);
            }
        }
    }
    cout << "调用阶段结束" << endl;
    
    cout << "验证阶段开始" << endl;
    for (int i = 0; i < n; i++) {
        bool bitSetHas = bitset_contains(i);
        bool hashSetHas = (hashSet.find(i) != hashSet.end());
        if (bitSetHas != hashSetHas) {
            cout << "出错了!" << endl;
            break;
        }
    }
    cout << "验证阶段结束" << endl;
    
    // 重置位图（释放vector内存）
    bitset_destroy();
    cout << "测试结束" << endl;
    
    return 0;
}