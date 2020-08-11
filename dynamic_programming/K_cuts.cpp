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
ll MOD = 720720;
ll MIN = -1e17;

ll solve(vector<vector<ll>> &dp, vector<vector<ll>> &vis, vector<ll> arr,ll n, ll k){
  auto &ans = dp[i][j];
  auto &seen = vis[i][j];
  if(!seen){
    seen = true;
    if(n == 0){
      ans = 0;
      return ans;
    }
    if(k == 0){
      ans = 1;
      return ans;
    }
    ans = solve()
  }
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
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll k;
    cin >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    vector<vector<ll>> vis(n + 1, vector<ll>(k + 1, false));
    cout << solve(dp, vis, arr, n, k);
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    