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
      ans = max(ans, 1 + LIS(dp, visit, arr, i) * (arr[n] > arr[i]));
    }
  }
  return ans;
}

ll LDS(vector<ll> &dp, vector<ll> &visit, vector<ll> &arr, ll n){
  auto &ans = dp[n];
  auto &seen = visit[n];
  if(!seen){
    seen = true;
    if(n == arr.size() - 1){
      ans = 1;
      return ans;
    }
    for(ll i = n + 1; i <= arr.size() - 1; i++){
      ans = max(ans, 1 + LDS(dp, visit, arr, i) * (arr[n] > arr[i]));
    }
  }
  return ans;
}
ll longest_bitonic(vector<ll> &LIS, vector<ll> LDS, ll n){
  ll maxi = -1;
  for(ll i = 0; i < n; i++){
    maxi = max(LIS[i] + LDS[i] - 1, maxi);
  }
  return maxi;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
 // cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
   // cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    vector<ll> Lis(n, 1);
    vector<ll> Lds(n, 1);
    vector<ll> vis1(n, false);
    vector<ll> vis2(n, false);
    LIS(Lis, vis1, arr, n - 1);
    LDS(Lds, vis2, arr, 0);
    cout << longest_bitonic(Lis, Lds, n) << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    