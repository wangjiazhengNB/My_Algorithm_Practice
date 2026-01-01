#include <bits/stdc++.h>
using namespace std;

struct Project {
    int p; 
    int c;
    Project(int profits, int cost) : p(profits), c(cost) {}
};

struct Cmp1 {
    bool operator()(const Project& a, const Project& b) {
        return a.c > b.c;
    }
};

struct Cmp2 {
    bool operator()(const Project& a, const Project& b) {
        return a.p < b.p;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<Project, vector<Project>, Cmp1> heap1;
        priority_queue<Project, vector<Project>, Cmp2> heap2;
        for (int i = 0; i < n; i++) {
            heap1.push(Project(profits[i], capital[i]));
        }
        while (k > 0) {
            while (!heap1.empty() && heap1.top().c <= w) {
                heap2.push(heap1.top());
                heap1.pop();
            }
            if (heap2.empty()) {
                break;
            }

            w += heap2.top().p;
            heap2.pop();
            k--;
        }
        return w;
    }
};

int main() {
    return 0;
}