#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    //cin >> tc;
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
            int tl = l / len, tr = r / len;
            int ans = 0;
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
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cout << query(i, j) << " ";
            } cout << "\n";
        }
    }
}