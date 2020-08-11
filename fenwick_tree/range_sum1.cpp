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

vector<ll> BIT(1000000 + 1, 0);
vector<ll> arr(1000000 + 1);
ll n, q;

void update(ll idx, ll value){
  for(ll i = idx; i <= n; i += i & -i){
    BIT[i] += value;
  }
}

ll query(ll idx){
  ll count = 0;
  for(ll i = idx; i > 0; i -= i & - i){
    count += BIT[i];
  }
  return count;
}
int main(){
  fastio();
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  ll tc = 1;
  //cin >> tc;
  for (ll tt = 1; tt <= tc; tt++){
    //cout << "Case "<<tt<<" :";
    cin >> n >> q;
    for(ll i = 1; i <= n; i++){
      cin >> arr[i];
      update(i, arr[i]);
    }
    for(ll i = 1; i <= q; i++){
      ll l, r;
      cin >> l >> r;
      cout << query(r)  - query(l - 1) << endl;
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    