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

ll MOD = 1000000007;
ll MAX = 1e18;
ll MIN = -1e17;

ll LIS(vector<ll> &dp, vector<ll> &visit, vector<ll> &arr, ll n){
  auto &ans = dp[n];
  auto &seen = visit[n];
  if(!seen){
    seen = true;
    if(n == 0){
      ans = 1;
      return ans;
    }
    for(ll i = n - 1; i >= 0; i--){
      ans = max(ans, (1 + LIS(dp, visit, arr, i) * (arr[n] >= arr[i])));
    }
  }
  return ans;
}
int main(){
  fastio();
 /* #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif*/
  ll tc = MAX;
  cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    vector<ll> dp(n + 1, 1);
    vector<ll> visit(n + 1, false);
    ll lis = -1;
    LIS(dp, visit, arr, n - 1);
    for(ll i = 0; i < n; i++){
      lis = max(lis, dp[i]);
    }
    cout <<  lis << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    