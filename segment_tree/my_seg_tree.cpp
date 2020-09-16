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
        vector<int> arr(n, 0);
        vector<int> st(4 * n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        function<void(int, int, int)> build = [&] (int l, int r, int v) {
            if (l > r) {
                return;
            }
            if (l == r) {
                st[v] = arr[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(l, mid, 2 * v + 1);
            build(mid + 1, r, 2 * v + 2);
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        };
        function<void(int, int, int, int, int)> update = [&] (int l, int r, int v, int value, int idx) {
            if (l > r) {
                return;
            } 
            if (l == r) {
                st[v] = value;
                return;
            }
            int mid = (l + r) >> 1;
            if (mid >= idx) {
                update(l, mid, 2 * v + 1, value, idx);
            } else {
                update(mid + 1, r, 2 * v + 2, value, idx);
            }
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        };
        function<int(int, int, int, int, int)> query = [&] (int l, int r, int v, int l1, int r1) {
            if (l > r1 or r < l1) {
                return 0;
            }
            if (l >= l1 and r <= r1) {
                return st[v];
            } 
            int mid = (l + r) >> 1;
            int ans1 = query(l, mid, 2 * v + 1, l1, r1);
            int ans2 = query(mid + 1, r, 2 * v + 2, l1, r1);
            return ans1 + ans2;
        };
        for (int i = 0; i < n; i++) {
            update(0, n - 1, 0, arr[i], i);
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            char c;
            cin >> c;
            if (c == 'q') {
                int l, r;
                cin >> l >> r;
                cout << query(0, n - 1, 0, l, r) << "\n";
            } else {
                int pos, value;
                cin >> pos >> value;
                update(0, n - 1, 0, value, pos);
            }
        }
    }
}