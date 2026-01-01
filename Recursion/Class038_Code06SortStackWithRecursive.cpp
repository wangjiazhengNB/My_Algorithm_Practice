#include <bits/stdc++.h>
using namespace std;

int deep(stack<int>& s) {
    if (s.empty()) {
        return 0;
    }
    int num = s.top();
    s.pop();
    int deepVal = 1 + deep(s);
    s.push(num);
    return deepVal;
}

int max_(stack<int>& s, int deep) {
    if (deep == 0) {
        return INT_MIN;
    }
    int num = s.top();
    s.pop();
    int maxVal = max(num, max_(s, deep - 1));
    s.push(num);
    return maxVal;
}

int times(stack<int>& s, int deep, int maxVal) {
    if (deep == 0) {
        return 0;
    }
    int num = s.top();
    s.pop();
    int k = (num == maxVal ? 1 : 0) + times(s, deep - 1, maxVal);
    s.push(num);
    return k;
}

void down(stack<int>& s, int deep, int maxVal, int k) {
    if (deep == 0) {
        for (int i = 0; i < k; i++) {
            s.push(maxVal);
        }
    } else {
        int num = s.top();
        s.pop();
        down(s, deep - 1, maxVal, k);
        if (num != maxVal) {
            s.push(num);
        }
    }
}

void sort(stack<int>& s) {
    int deepVal = deep(s);
    while (deepVal > 0) {
        int maxVal = max_(s, deepVal);
        int k = times(s, deepVal, maxVal);
        down(s, deepVal, maxVal, k);
        deepVal -= k;
    }
}

bool isSorted(stack<int>& s) {
    int step = INT_MIN;
    stack<int> temp;
    while (!s.empty()) {
        int val = s.top();
        s.pop();
        temp.push(val);
        if (step > val) {
            while (!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
            return false;
        }
        step = val;
    }
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
    return true;
}

stack<int> randomStack(int n, int v) {
    stack<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push(rand() % v);
    }
    return ans;
}

int main() {
    stack<int> test1;
    test1.push(1);
    test1.push(5);
    test1.push(4);
    test1.push(5);
    test1.push(3);
    test1.push(2);
    test1.push(3);
    test1.push(1);
    test1.push(4);
    test1.push(2);
    sort(test1);
    while (!test1.empty()) {
        cout << test1.top() << endl;
        test1.pop();
    }

    srand((unsigned int)time(nullptr));
    int N = 20;
    int V = 20;
    int testTimes = 20000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        int n = rand() % N;
        stack<int> s = randomStack(n, V);
        stack<int> temp = s;
        sort(s);
        if (!isSorted(s)) {
            cout << "出错了!" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;

    stack<int> test2;
    test2.push(3);
    test2.push(1);
    test2.push(4);
    test2.push(2);
    sort(test2);
    while (!test2.empty()) {
        cout << test2.top() << endl;
        test2.pop();
    }

    stack<int> test3;
    sort(test3);
    while (!test3.empty()) {
        cout << test3.top() << endl;
        test3.pop();
    }

    stack<int> test4;
    test4.push(5);
    test4.push(5);
    test4.push(5);
    sort(test4);
    while (!test4.empty()) {
        cout << test4.top() << endl;
        test4.pop();
    }

    return 0;
}