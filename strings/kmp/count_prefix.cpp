#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto prefix_function = [&] (string s) {
            int n = s.length();
            int border = 0;
            vector<int> ans(n, 0);
            for (int i = 1; i < n; i++) {
                while (border > 0 and s[border] != s[i]) {
                    border = s[border - 1];
                }
                if (s[border] == s[i]) {
                    border++;
                } else border = 0;
                ans[i] = border;
            }
            return ans;
        };
        vector<int> prefix = prefix_function(s);
        vector<int> count_occ(n + 1, 0);
        for (int i = 0; i < n; i++) {
            count_occ[prefix[i]]++;
        }
        for (int i = n - 1; i > 0; i--) {
            count_occ[prefix[i - 1]] += count_occ[i];
        }
        for (int i = 0; i <= n; i++) {
            count_occ[i]++;
        }
        for (auto x: count_occ) {
            cout << x << " ";
        } cout << endl;
    }
}