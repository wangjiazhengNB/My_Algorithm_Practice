class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int ans = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0) {
                ans = i + 1;
            }
            else {
                if (mp.count(sum - 1)) {
                    ans = max(ans, i - mp[sum - 1]);
                }
            }
            if (!mp.count(sum)) mp.insert({sum, i});
        }
        return ans;
    }
};

int main() {
    return 0;
}