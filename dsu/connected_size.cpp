#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  //cin >> tc;
  for (int tt = 1; tt <= tc; tt++) {
    //cout << "Case #" << tt << ": ";
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), size(n), parent(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
    auto Root = [&](auto a) {
      while (a != parent[a])
      {
        parent[a] = parent[parent[a]];
        a = parent[a];
      }
      return a;
    };
    auto Find = [&](auto a, auto b) {
      return Root(a) == Root(b);
    };
    auto Union = [&](auto a, auto b) {
      int x = Root(a);
      int y = Root(b);
      if (size[x] < size[y]) {
        parent[x] = parent[y];
        size[y] += size[x];
      }
      else {
        parent[y] = parent[x];
        size[x] += size[y];
      }
    };
    for (int i = 1; i <= m; i++) {
      unordered_map<int, int> mp;
      int x, y;
      cin >> x >> y;
      x--, y--;
      if (!Find(x, y)) {
        Union(x, y);
      }
      vector<int> ans;
      for (int i = 0; i < n; i++) {
        if (mp[Root(i)] == 0) {
          mp[Root(i)] = 1;
          ans.push_back(size[Root(i)]);
        }
      }
      sort(ans.begin(), ans.end());
      for (auto x : ans) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}