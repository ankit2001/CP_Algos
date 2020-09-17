#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int len = sqrt(n) + 1;
        int q;
        cin >> q;
        vector<vector<int>> queries;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            queries.push_back({l, r, i});
        }
        function<vector<int>(void)> MOS = [&] () {
            vector<int> ans(q);
            int final = 0;
            sort(queries.begin(), queries.end(), [&] (vector<int> p1, vector<int> p2) {
                int l1 = p1[0] / len, r1 = p1[1];
                int l2 = p2[0] / len, r2 = p2[1];
                if (l1 == l2) {
                    return r1 < r2;
                } return l1 < l2;
            });
            function<void(int)> add = [&] (int idx) {
                final += arr[idx];
            };
            function<void(int)> remove = [&] (int idx) {
                final -= arr[idx];
            };
            function<int(void)> find = [&] () {
                int ans = final;
                return ans;
            };
            int curr_l = 0, curr_r = -1;
            for (auto x: queries) {
                int ql = x[0], qr = x[1], idx = x[2];
                while (ql > curr_l) {
                    remove(curr_l);
                    curr_l++;
                }
                while (ql < curr_l) {
                    curr_l--;
                    add(curr_l);
                }
                while (qr > curr_r) {
                    curr_r++;
                    add(curr_r);
                }
                while (qr < curr_r) {
                    remove(curr_r);
                    curr_r--;
                }
                ans[idx] = find();
            }
            return ans;
        };
        vector<int> ans =  MOS();
        for (auto x: ans) {
            cout << x << " ";
        } cout << "\n";
    }
}