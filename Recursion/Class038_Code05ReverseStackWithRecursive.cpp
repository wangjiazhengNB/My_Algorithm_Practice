#include <bits/stdc++.h>
using namespace std;

int bottomOut(stack<int>& s) {
    int ans = s.top();
    s.pop();
    if (s.empty()) {
        return ans;
    }
    else {
        int last = bottomOut(s);
        s.push(ans);
        return last;
    }
}

void reverse(stack<int>& s) {
    if (s.empty()) {
        return ;
    }
    int num = bottomOut(s);
    reverse(s);
    s.push(num);
}

int main() {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    reverse(stack);
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}