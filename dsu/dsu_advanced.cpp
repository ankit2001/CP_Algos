#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("/Applications/input.txt", "r", stdin);
    freopen("/Applications/output.txt", "w", stdout);
  #endif
  int tc = 1;
  //cin >> tc;
  for(int tt = 1; tt <= tc; tt++){
    //cout << "Case #" << tt << ": ";
    int n;
    cin >> n;
    vector<int> arr(n), size(n), parent(n);
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      parent[i] = i;
    }
    auto Root = [&](auto a){
      while(a != parent[a]){
        parent[a] = parent[parent[a]];
        a = parent[a];
      }
      return a;
    };
    auto Find = [&](auto a, auto b){
      return Root(a) == Root(b);
    };
    auto Union = [&](auto a, auto b){
      int x = Root(a);
      int y = Root(b);
      if(size[x] < size[y]){
        parent[x] = parent[y];
        size[y] += size[x];
      } else {
        parent[y] = parent[x];
        size[x] += size[y];
      }
    };
  }
  return 0;
}