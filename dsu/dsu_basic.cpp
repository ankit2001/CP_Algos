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
    int arr[n], parent[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      parent[i] = i;
    }

    auto Root = [&](int a){
      while(a != parent[a]){
        a = parent[a];
      }
      return a;
    };
      
    auto Find = [&](int a, int b){
      return Root(a) == Root(b);
    };

    auto Union = [&](int a, int b){
      int x = Root(a);
      int y = Root(b);
      parent[x] = y;
    };

    for(int i = 0; i < n; i++){
      cout << arr[i] << "\n";
      int a = Root(i);
    }
  }
  return 0;
}