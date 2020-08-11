#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        
        string t, s;
        cin >> t >> s;
        auto prefix_function = [&] (string s) {
            int n = s.length();
            vector<int> ans(n, 0);
            int border = 0;
            for (int i = 1; i < n; i++) {
                while (border > 0 and s[i] != s[border]) {
                    border = s[border - 1];
                }
                if (s[border] == s[i]) {
                    border++;
                } else border = 0;
                ans[i] = border;
            }
            return ans;
        };
        auto kmp = [&] (string s, string t) {
            vector<int> ans;
            string final;
            final = s + "$" + t;
            vector<int> prefix = prefix_function(final);
            for (int i = 0; i < final.length(); i++) {
                if (prefix[i] == s.length()) {
                    ans.push_back(i - 2 * s.length());
                }
            }
            return ans;
        };
        vector<int> ans = kmp(s, t);
        for (auto x: ans) {
            cout << x << " ";
        } cout << endl;
    }
}