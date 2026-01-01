#include <bits/stdc++.h>
using namespace std;

void f1(string& s, int i, string& path, unordered_set<string>& set) {
    if (i == s.size()) {
        set.insert(path);
    }
    else {
        path.push_back(s[i]);
        f1(s, i + 1, path, set);
        path.pop_back();
        f1(s, i + 1, path, set);
    }
}

void f2(string& s, int i, char* path, int size, unordered_set<string>& set) {
    if (i == s.size()) {
        set.insert(string(path, size));
    }
    else {
        path[size] = s[i];
        f2(s, i + 1, path, size + 1, set);
        f2(s, i + 1, path, size, set);
    }
}

vector<string> generatePermutation1(string str) {
    string s = str;
    unordered_set<string> set;
    string path;
    f1(s, 0, path, set);
    int m = set.size();
    vector<string> ans(m);
    int i = 0;
    for (string cur : set) {
        ans[i++] = cur;
    }
    return ans;
}

vector<string> generatePermutation2(string str) {
    string s = str;
    unordered_set<string> set;
    int strlen = s.size();
    char* path = new char[strlen];
    f2(s, 0, path, 0, set);
    int m = set.size();
    vector<string> ans(m);
    int i = 0;
    for (string cur : set) {
        ans[i++] = cur;
    }
    delete[] path;
    return ans;
}

int main() {
    string testStr1 = "ab";
    vector<string> res1 = generatePermutation1(testStr1);
    cout << "generatePermutation1 test with \"ab\":" << endl;
    for (string s : res1) {
        cout << s << " ";
    }
    cout << endl;

    string testStr2 = "ab";
    vector<string> res2 = generatePermutation2(testStr2);
    cout << "generatePermutation2 test with \"ab\":" << endl;
    for (string s : res2) {
        cout << s << " ";
    }
    cout << endl;

    string testStr3 = "abc";
    vector<string> res3 = generatePermutation1(testStr3);
    cout << "generatePermutation1 test with \"abc\":" << endl;
    for (string s : res3) {
        cout << s << " ";
    }
    cout << endl;

    string testStr4 = "abc";
    vector<string> res4 = generatePermutation2(testStr4);
    cout << "generatePermutation2 test with \"abc\":" << endl;
    for (string s : res4) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}