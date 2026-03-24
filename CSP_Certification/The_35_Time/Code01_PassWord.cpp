#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int check[256];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        memset(check, 0, sizeof check);
        bool p1 = false, p2 = false, p3 = false;
        bool times = false;
        for (int j = 0; j < s.size(); j++) {
            check[s[j]]++;
            if ( (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') ) p1 = true;
            if (s[j] >= '0' && s[j] <= '9') p2 = true;
            if (s[j] == '*' || s[j] == '#') p3 = true;
            if (check[s[j]] > 2) times = true;
        }
        if (p1 && p2 && p3 && !times) cout << 2 << '\n';
        else if (p1 && p2 && p3 && times) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}

//简化版代码，去掉冗余项，需要学习这种方法
/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int check[256];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        memset(check, 0, sizeof check);
        bool letter = 0, digit = 0, sym = 0, repeat = 0;
        
        for (char c : s) {
            check[c]++;
            letter |= (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
            digit |= c >= '0' && c <= '9';
            sym |= c == '*' || c == '#';
            repeat |= check[c] > 2;
        }
        
        cout << (letter && digit && sym ? !repeat ? 2 : 1 : 0) << '\n';
    }
    return 0;
}
*/