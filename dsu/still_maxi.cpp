#include<bits/stdc++.h>
using namespace std;

int main() {
  int tc = 1;
  //cin >> tc
  for (int tt = 1; tt <= tc; tt++) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, pair<int, int>> mp;
    int arr[n], size[n];
    int value[n];
    int mini[n];
    int maxi[n];
    for (int i = 0; i < n; i++) {
      arr[i] = i;
      size[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      mp[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
      cin >> value[i];
    }
    for (int i = 0; i < n; i++) {
      maxi[i] = value[i];
      mini[i] = value[i];
    }
    stack<int> query, ans;
    for (int i = 0; i < n - 1; i++) {
      int x;
      cin >> x; x--;
      query.push(x);
    }
    ans.push(0);
    auto root = [&] (int x) {
      while (x != arr[x]) {
        arr[x] = arr[arr[x]];
        x = arr[x];
      }
      return x;
    };
    auto find = [&] (int x, int y) {
      return root(x) == root(y);
    };
    auto Union = [&] (int x, int y) {
      int root_x = root(x);
      int root_y = root(y);
      if (size[root_x] < size[root_y]) {
        arr[root_x] = arr[root_y];
        size[root_y] += size[root_x];
        mini[root_y] = min(mini[root_x], mini[root_y]);
        maxi[root_y] = max(maxi[root_y], maxi[root_x]); 
      } else {
        arr[root_y] = arr[root_x];
        size[root_x] += size[root_y];
        mini[root_x] = min(mini[root_x], mini[root_y]);
        maxi[root_x] = max(maxi[root_x], maxi[root_y]);
      }
      return;
    };
    int final = INT_MIN;
    for (int i = 0; i < n - 2; i++) {
      int idx = query.top();
      query.pop();
      pair<int, int> p = mp[idx];
      int x = p.first, y = p.second;
      int root_x = root(x), root_y = root(y);
      final = max({final, maxi[root_x] - mini[root_y], maxi[root_y] - mini[root_x]});
      ans.push(final);
      Union(x, y);
    }
    for (int i = 0; i < n - 1; i++) {
      cout << ans.top() << "\n";
      ans.pop();
    }
  }
  return 0;
}