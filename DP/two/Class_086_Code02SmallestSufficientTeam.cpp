class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int m = people.size();
        unordered_map<string, int> skillMap;
        int cnt = 0;
        for (string& skill : req_skills) {
            skillMap[skill] = cnt++;
        }
        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            int status = 0;
            for (string& skill : people[i]) {
                if (skillMap.count(skill)) {
                    status |= 1 << skillMap[skill];
                }
            }
            arr[i] = status;
        }
        vector<vector<int>> dp(m, vector<int>((1 << n), -1));
        int teamSize = f(arr, m, n, 0, 0, dp);
        vector<int> ans(teamSize);
        for (int j = 0, i = 0, s = 0; s != (1 << n) - 1; i++) {
            if (i == m - 1 || dp[i][s] != dp[i + 1][s]) {
                ans[j++] = i;
                s |= arr[i];
            }
        }
        return ans;
    }

    int f(vector<int>& arr, int m, int n, int i, int s, vector<vector<int>>& dp) {
        if (s == (1 << n) - 1) {
            return 0;
        }
        if (i == m) {
            return INT_MAX;
        }
        if (dp[i][s] != -1) {
            return dp[i][s];
        }
        int p1 = f(arr, m, n, i + 1, s, dp);
        int p2 = INT_MAX;
        int next2 = f(arr, m, n, i + 1, s | arr[i], dp);
        if (next2 != INT_MAX) {
            p2 = 1 + next2;
        }
        int ans = min(p1, p2);
        dp[i][s] = ans;
        return ans;
    }
};

int main() {
    return 0;
}