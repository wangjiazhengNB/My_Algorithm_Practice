#include <bits/stdc++.h>
using namespace std;

struct Employee {
    double ratio;
    int quality;

    Employee(double r, int q) : ratio(r), quality(q) {}
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<Employee> employees;
        for (int i = 0; i < n; i++) {
            employees.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
            return a.ratio < b.ratio;
        });
        priority_queue<int, vector<int>, less<int> > heap;
        int qualitySum = 0;
        double ans = DBL_MAX;
        for (int i = 0; i < n; i++) {
            int curQuality = employees[i].quality;
            if (heap.size() < k) {
                qualitySum += curQuality;
                heap.push(curQuality);
                if (heap.size() == k) {
                    ans = min(ans, qualitySum * employees[i].ratio);
                }
            }
            else {
                if (heap.top() > curQuality) {
                    qualitySum += curQuality - heap.top();
                    heap.pop();
                    heap.push(curQuality);
                    ans = min(ans, qualitySum * employees[i].ratio);
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}