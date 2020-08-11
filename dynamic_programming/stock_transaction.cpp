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
ll MOD = 1000000007;
ll MIN = -1e17;

ll solve(vector<vector<vector<ll>>> &dp, vector<vector<vector<ll>>> &vis, vector<ll> &arr, ll n, ll k, ll value){
  //cout << n << k << value  << endl;
  auto &ans = dp[n][k][value];
  auto &seen = vis[n][k][value];
  if(!seen){
    seen = true;
    if(n == 0 and k != 0){
      ans = MIN;
    }
    else if(k == 0){
      ans = 0;
    }
    else{
      if(value == 1){
        ans = max(solve(dp, vis, arr, n - 1, k - 1, 0) - arr[n - 1], solve(dp, vis, arr, n - 1, k, 1));
      }
      else{
        ans = max(solve(dp, vis, arr, n - 1, k, 1) + arr[n - 1], solve(dp, vis, arr, n - 1, k , 0));
      }
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
  cin >> tc;
  for (ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n, k;
    cin >> k >> n;
    vector<ll> arr(n, 0);
    for(ll i = 0; i < n ; i++){
      cin >> arr[i];
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (k + 1, vector<ll> (2, 0)));
    vector<vector<vector<ll>>> vis(n + 1, vector<vector<ll>> (k + 1, vector<ll> (2, false)));
    cout << solve(dp, vis, arr, n, k, 0) << endl;
    if(solve(dp, vis, arr, n, k, 0) > 0){
      cout << solve(dp, vis, arr, n, k, 0) << endl;
    }
    else{
      cout << 0 << endl;
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    