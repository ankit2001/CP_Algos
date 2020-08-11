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

ll solve(vector<vector<ll>> &dp, vector<vector<ll>> &vis, vector<ll> &arr, ll n, ll value){
  auto &ans = dp[n][value];
  auto &seen = vis[n][value];
  if(value < 0){
      return 0;
  }
  if(!seen){
    seen = true;
    if(value == 0){
      ans = 1;
      return ans;
    }
    if(n == 0){
      ans = 0;
      return ans;
    }
    ans = solve(dp, vis, arr, n - 1, value) + solve(dp, vis, arr, n, value - arr[n - 1]);
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
  //cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll value;
    cin >> value;
    vector<vector<ll>> dp(n + 1, vector<ll>(value + 1, 0));
    vector<vector<ll>> vis(n + 1, vector<ll>(value + 1, false));
    cout << solve(dp, vis, arr, n, value) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    