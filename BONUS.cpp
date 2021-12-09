#include <bits/stdc++.h>

using namespace std;

int row, col;
vector<vector<int>> a;

namespace sub2 {
    const int N = 207;
    long long res;
    void dfs(int u, int d, long long sum) {
        res = max(res, abs(sum));
        for (int v = 1; v < u-d; ++v) {
            dfs(v, u-v, sum + a[1][v]);
        }
        for (int v = u+d+1; v <= col; ++v) {
            dfs(v, v-u, sum + a[1][v]);
        }
    }
    long long solve() {
        res = 0;
        for (int i = 1; i <= col; ++i) {
            dfs(i, 0, a[1][i]);
        }
        return res;
    }
}

namespace sub3 {
    const int N = 2007;
    long long dp[N][N][2]; // 0 -> min | 1 -> max
    long long res;
    void minimize(long long &x, long long y) {
        if (x > y) x = y;
    }
    void maximize(long long &x, long long y) {
        if (x < y) x = y;
    }
    long long solve() {
        for (int i = 1; i <= col; ++i) {
            dp[0][i][0] = dp[0][i][1] = a[1][i];
            maximize(res, abs(a[1][i]));
        }
        for (int d = 1; d < col; ++d) {
            for (int i = 1; i <= col; ++i) {
                if (i-d < 1 && i+d > col) continue;
                dp[d][i][0] = LLONG_MAX;
                dp[d][i][1] = LLONG_MIN;
                if (i-d >= 1) {
                    minimize(dp[d][i][0], dp[d-1][i-d][0] + a[1][i]);
                    maximize(dp[d][i][1], dp[d-1][i-d][1] + a[1][i]);
                }
                if (i+d <= col) {
                    minimize(dp[d][i][0], dp[d-1][i+d][0] + a[1][i]);
                    maximize(dp[d][i][1], dp[d-1][i+d][1] + a[1][i]);
                }
                minimize(dp[d][i][0], dp[d-1][i][0]);
                maximize(dp[d][i][1], dp[d-1][i][1]);
                maximize(res, abs(dp[d][i][0]));
                maximize(res, abs(dp[d][i][1]));
            }
        }
        return res;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("BONUS.inp", "r", stdin);
    freopen("BONUS.out", "w", stdout);

    cin >> row >> col;
    a.resize(row+7, vector<int>(col+7));
    for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j) {
        cin >> a[i][j];
    }
    // if (col <= 200)
    //     cout << sub2::solve();
    // else
    //     cout << sub3::solve();
    cout << sub3::solve();
    return 0;
}