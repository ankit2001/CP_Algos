#include<bits/stdc++.h>
using namespace std;
class obj {
    public:
    int max_suff, max_pref, max_sum, sum;
};
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
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<obj> st(4 * n);
        function<obj(int)> init = [&] (int value) {
            obj o;
            o.sum = value;
            o.max_pref = o.max_suff = o.max_suff = max(0, value);
            return o;
        };
        function<obj(obj, obj)> merge = [&] (obj o1, obj o2) {
            obj o;
            o.sum = o1.sum + o2.sum;
            o.max_pref = max({o1.sum + o2.max_pref, o1.max_pref});
            o.max_suff = max({o1.max_suff + o2.sum, o2.max_suff});
            o.max_sum = max({o1.max_suff + o2.max_pref, o1.max_sum, o2.max_sum}); 
            return o;
        };
        function<void(int, int, int)> build = [&] (int l, int r, int v) {
            if (l > r) {
                return;
            }
            if (l == r) {
                st[v] = init(arr[l]);
                return;
            }
            int mid = (l + r) >> 1;
            build (l, mid, 2 * v + 1);
            build(mid + 1, r, 2 * v + 2);
            st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
        };
        function<void(int, int, int, int, int)> update = [&] (int l, int r, int v, int pos, int val) {
            if (l > r) {
                return;
            }
            if (l == r) {
                st[v] = init(val);
                return;
            }
            int mid = (l + r) >> 1;
            if (mid >= pos) {
                update(l, mid, 2 * v + 1, pos, val);
            } else {
                update(mid + 1, r, 2 * v + 2, pos, val);
            }
            st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
        };
        function<obj(int, int, int, int, int)> query = [&] (int l, int r, int v, int l1, int r1) {
            if (l > r1 or r < l1) {
                return init(0);
            } 
            if (l >= l1 and r <= r1) {
                return st[v];
            }
            int mid = (l + r) >> 1;
            obj ans1 = query(l, mid, 2 * v + 1, l1, r1);
            obj ans2 = query(mid + 1, r, 2 * v + 2, l1, r1);
            st[v] = merge(ans1, ans2);
            return st[v];
        };
        build(0, n - 1, 0);
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            char c;
            cin >> c;
            if (c == 'q') {
                int l, r;
                cin >> l >> r;
                cout << query(0, n - 1, 0, l, r).sum << "\n";
            } else {
                int pos, value;
                cin >> pos >> value;
                update(0, n - 1, 0, pos, value);
            }
        }
    }
}