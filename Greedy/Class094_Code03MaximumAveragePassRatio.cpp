#include <bits/stdc++.h>
using namespace std;

struct ClassInfo {
    double pass;
    double total;
    double getIncrement() const {
        return (pass + 1) / (total + 1) - pass / total;
    }
};

struct compareClass {
    bool operator()(const ClassInfo& a, const ClassInfo& b) {
        return a.getIncrement() < b.getIncrement();
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int m) {
        int n = classes.size();
        priority_queue<ClassInfo, vector<ClassInfo>, compareClass> heap;
        for (const auto& c : classes) {
            double pass = c[0];
            double total = c[1];
            heap.push({pass, total});
        }
        while (m-- > 0) {
            ClassInfo cur = heap.top();
            heap.pop();
            cur.pass += 1;
            cur.total += 1;
            heap.push(cur);
        }
        double sum = 0;
        while (!heap.empty()) {
            ClassInfo cur = heap.top();
            heap.pop();
            sum += cur.pass / cur.total;
        }
        return sum / n;
    }
};

int main() {
    return 0;
}