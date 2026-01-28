#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        int leftSum = 0;
        int leftNeed = 0;
        int rightNeed = 0;
        int bottleNeck = 0;
        int ans = 0;
        for (int i = 0; i < n; leftSum += arr[i], i++) {
            leftNeed = i * avg - leftSum;
            rightNeed = (n - i - 1) * avg - (sum - leftSum - arr[i]);
            if (leftNeed > 0 && rightNeed > 0) {
                bottleNeck = leftNeed + rightNeed;
            }
            else {
                bottleNeck = max(abs(leftNeed), abs(rightNeed));
            }
            ans = max(ans, bottleNeck);
        }
        return ans;
    }
};

int main() {
    return 0;
}