#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto dp = vector(n, vector(2, INT_MAX));
        auto vis = vector(n, vector(2, 0));
        function<int(int, int)> solve = [&] (int idx, int f) {
            if (idx > n - 1) {
                return 0;
            }
            auto &ans = dp[idx][f];
            auto &seen = vis[idx][f];
            if (!seen) {
                if (idx == n - 1) {
                    if (f == 1) {
                        ans = (arr[idx] == 1);
                    } else ans = 0;
                    return ans;
                }
                seen = true;
                if (f == 0) {
                    int ans1 = solve(idx + 1, 1);
                    int ans2 = solve(idx + 2, 1);
                    ans = min(ans1, ans2);
                    return ans;
                } else {
                    if (idx + 2 < n) {
                        int ans1 = (arr[idx] == 1) + solve(idx + 1, 0);
                        int ans2 = (arr[idx] == 1) + (arr[idx + 1] == 1) + solve(idx + 2, 0); 
                        ans = min(ans1, ans2);
                        return ans;
                    } else {
                        ans = (arr[idx] == 1) + solve(idx + 1, 0);
                    }
                }
            }
            return ans;
        };
        int x = solve(0, 1);
        cout << x << endl;
    }
}