//Keep calm and admire
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()

ll MAX = 1e18;
ll MIN = -1e17;
ll solve(auto &dp, auto &vis, auto &arr, auto mask, auto n, auto p){
  if(p >= n){
    return 0;
  }
  auto &ans = dp[mask];
  auto &seen = vis[mask];
  if(!seen){
    seen = true;
    ans = MAX;
    for(ll i = 0; i < n; i ++){
      if(! (mask & (1 << i)))
      ans = min(ans, solve(dp, vis, arr, mask | (1 << i), n, p + 1) + arr[p][i]);
    }
  }
  return ans;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
//  cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    //auto arr = vector(n, vector(n, 0));
   // auto dp = vector(n, vector(k + 1, 0));
    vector<ll> dp((1 << n), -1);
    vector<ll> vis((1 << n), false);
    auto arr = vector(n, vector(n +1, 0));
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }
    cout << solve(dp, vis, arr, 0ll, n, 0ll) << endl;;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    