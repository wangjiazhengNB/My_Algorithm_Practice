#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int maxDeque[N], minDeque[N];
int n, d, maxh, maxt, minh, mint;

struct Node {
    int x, y;
}arr[N];

bool ok() {
    int max_val = maxh < maxt ? arr[maxDeque[maxh]].y : 0;
    int min_val = minh < mint ? arr[minDeque[minh]].y : 0;
    return max_val - min_val >= d; 
}

void push(int r) {
    while (maxh < maxt && arr[maxDeque[maxt - 1]].y <= arr[r].y) {
        maxt--;
    }
    maxDeque[maxt++] = r;
    while (minh < mint && arr[minDeque[mint - 1]].y >= arr[r].y) {
        mint--;
    }
    minDeque[mint++] = r;
}

void pop(int l) {
    if (maxh < maxt && maxDeque[maxh] == l) {
        maxh++;
    }
    if (minh < mint && minDeque[minh] == l) {
        minh++;
    }
}

int compute() {
    maxh = maxt = minh = mint = 0;
    int ans = INT_MAX;
    for (int l = 0, r = 0; l < n; l++) {
        while (!ok() && r < n) {
            push(r++);
        }
        if (ok()) {
            ans = min(ans, arr[r - 1].x - arr[l].x);
        }
        pop(l);
    }
    return ans;
}

bool cmp(Node a, Node b) {
    return a.x < b.x;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    int ans = compute();
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}
