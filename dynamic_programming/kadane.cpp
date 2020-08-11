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
 
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  cin >> tc;
  for(ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll max_sum = 0;
    ll best_sum = MIN;
    for(ll i = 0; i < n; i++){
      max_sum += arr[i];
      if(best_sum < max_sum){
        best_sum = max_sum;
      }
      if(max_sum < 0){
        max_sum = 0;
      }
    }
    cout << best_sum << endl;
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    