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
        vector<int> decompose(len, 0);
        function<void(void)> build = [&] () {
            for (int i = 0; i < n; i++) {
                decompose[i / len] += arr[i];
            }
        };
        build();
        function<int(int, int)> query = [&] (int l, int r) {
            int tl = l / len, tr = r / len, ans = 0;
            if (tl == tr) {
                for (int i = l; i <= r; i++) {
                    ans += arr[i];
                }
                return ans;
            }
            for (int i = l; i <= (tl + 1) * len - 1; i++) {
                ans += arr[i];
            }
            for (int i = tl + 1; i <= tr - 1; i++) {
                ans += decompose[i];
            }
            for (int i = tr * len; i <= r; i++) {
                ans += arr[i];
            }
            return ans;
        };
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
            function<void(int, int)> add = [&] (int l, int r) {
                final += query(l, r);
            };
            function<void(int, int)> remove = [&] (int l, int r) {
                final -= query(l, r);
            };
            function<int(void)> find = [&] () {
                int ans = final;
                return ans;
            };
            int curr_l = 0, curr_r = -1;
            for (auto x: queries) {
                int ql = x[0], qr = x[1], idx = x[2];
                while (ql > curr_l) {
                    remove(curr_l, ql - 1);
                    curr_l = ql;
                }
                while (ql < curr_l) {
                    add(ql, curr_l - 1);
                    curr_l = ql;
                }
                while (qr > curr_r) {
                    add(curr_r + 1, qr);
                    curr_r = qr;
                }
                while (qr < curr_r) {
                    remove(qr + 1, curr_r);
                    curr_r = qr;
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