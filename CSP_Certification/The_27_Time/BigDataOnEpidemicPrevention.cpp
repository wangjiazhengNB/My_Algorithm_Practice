#include <bits/stdc++.h>
using namespace std;

struct RoamRecord {
    long long date;
    long long user;
    long long region;
};

struct DailyData {
    int r;
    int m;
    vector<long long> risk_regions;
    vector<RoamRecord> records;
};

vector<pair<int, int>> merge_intervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return {};
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        auto& last = merged.back();
        int curr_s = intervals[i].first;
        int curr_e = intervals[i].second;
        if (curr_s <= last.second) {
            last.second = max(last.second, curr_e);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<DailyData> all_days(n);

    unordered_map<long long, vector<pair<int, int>>> region_risk_intervals;
    unordered_map<long long, vector<pair<int, pair<long long, long long>>>> user_records;

    for (int i = 0; i < n; ++i) {
        DailyData& day = all_days[i];
        cin >> day.r >> day.m;

        for (int j = 0; j < day.r; ++j) {
            long long r;
            cin >> r;
            day.risk_regions.push_back(r);

            pair<int, int> new_interval = {i, i + 7};
            auto& intervals = region_risk_intervals[r];
            intervals.push_back(new_interval);
            intervals = merge_intervals(intervals);
        }

        for (int j = 0; j < day.m; ++j) {
            RoamRecord rec;
            cin >> rec.date >> rec.user >> rec.region;
            day.records.push_back(rec);
            user_records[rec.user].emplace_back(i, make_pair(rec.date, rec.region));
        }

        set<long long> risk_users;
        for (auto& user_entry : user_records) {
            long long u = user_entry.first;
            auto& records = user_entry.second;
            bool is_risk = false;

            for (auto& rec : records) {
                int d0 = rec.first;
                long long d1 = rec.second.first;
                long long r = rec.second.second;

                if (d0 <= i - 7 || d0 > i) continue;
                if (d1 <= i - 7 || d1 > i) continue;

                if (!region_risk_intervals.count(r)) continue;
                auto& intervals = region_risk_intervals[r];
                for (auto& interval : intervals) {
                    int s = interval.first;
                    int e = interval.second;
                    if (s <= d1 && e >= i + 1) {
                        is_risk = true;
                        break;
                    }
                }
                if (is_risk) break;
            }
            if (is_risk) {
                risk_users.insert(u);
            }
        }

        cout << i;
        for (long long u : risk_users) {
            cout << " " << u;
        }
        cout << "\n";
    }

    return 0;
}