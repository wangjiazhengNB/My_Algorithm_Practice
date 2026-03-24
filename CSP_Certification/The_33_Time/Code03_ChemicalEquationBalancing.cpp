#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-8;

unordered_map<string, int> parse_formula(const string& s) {
    unordered_map<string, int> res;
    int i = 0, len = s.size();
    while (i < len) {
        int j = i;
        while (j < len && islower(s[j])) j++;
        string elem = s.substr(i, j - i);
        i = j;

        int num = 0;
        while (j < len && isdigit(s[j])) {
            num = num * 10 + (s[j] - '0');
            j++;
        }
        num = (num == 0) ? 1 : num;
        res[elem] += num;
        i = j;
    }
    return res;
}

int gauss_rank_recursive(vector<vector<double>>& mat, int start_row, int start_col) {
    int total_rows = mat.size();
    int total_cols = mat[0].size();

    if (start_row >= total_rows || start_col >= total_cols) {
        return 0;
    }

    int first_non_zero = -1;
    for (int i = start_row; i < total_rows; i++) {
        if (fabs(mat[i][start_col]) > EPS) {
            first_non_zero = i;
            break;
        }
    }

    if (first_non_zero == -1) {
        return gauss_rank_recursive(mat, start_row, start_col + 1);
    }

    if (first_non_zero != start_row) {
        swap(mat[start_row], mat[first_non_zero]);
    }

    double pivot = mat[start_row][start_col];
    for (int i = start_row + 1; i < total_rows; i++) {
        double factor = mat[i][start_col] / pivot;
        for (int j = start_col; j < total_cols; j++) {
            mat[i][j] -= factor * mat[start_row][j];
        }
    }

    int sub_rank = gauss_rank_recursive(mat, start_row + 1, start_col + 1);

    return 1 + sub_rank;
}

int get_rank(vector<vector<double>> mat) {
    if (mat.empty() || mat[0].empty()) return 0;
    return gauss_rank_recursive(mat, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;

        vector<unordered_map<string, int>> formulas(m);
        set<string> elements;

        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            formulas[i] = parse_formula(s);
            for (auto& p : formulas[i]) {
                elements.insert(p.first);
            }
        }

        vector<vector<double>> mat;
        for (auto& elem : elements) {
            vector<double> row(m, 0);
            for (int i = 0; i < m; i++) {
                if (formulas[i].count(elem)) {
                    row[i] = formulas[i][elem];
                }
            }
            mat.push_back(row);
        }

        int rank = get_rank(mat);
        cout << (rank < m ? "Y" : "N") << '\n';
    }

    return 0;
}