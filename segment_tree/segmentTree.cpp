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
void build(vector<ll> &st, vector<ll> &arr, ll lo, ll hi, ll v){
  if(lo == hi){
    st[v] = arr[lo];
    return ;
  }
  ll mid = lo + hi >> 1;
  build(st, arr, lo, mid, 2 * v + 1);
  build(st, arr, mid + 1, hi, 2 * v + 2);
  st[v] = st[2 * v + 1] + st[2 * v + 2];
}

void update(vector<ll> &st, vector<ll> &arr, ll lo, ll hi, ll idx, ll value, ll v){
  if(lo == hi){
    st[v] = value;
    return;
  }
  ll mid = lo + hi >> 1;
  if(mid >= idx){
    update(st, arr, lo, mid, idx, value, 2 * v + 1);
  }
  else{
    update(st, arr, mid + 1, hi, idx, value, 2 * v + 2);
  }
  st[v] =  st[2 * v + 1] + st[2 * v + 2];
}

ll query(vector<ll> &st, vector<ll> &arr, ll lo, ll hi, ll l, ll r, ll v){
  if(lo > r or hi < l){
    return 0;
  }
  if(lo >= l and hi <= r){
    return st[v];
  }
  ll mid = lo + hi >> 1;
  return query(st, arr, lo, mid, l, r, 2 * v + 1) + query(st, arr, mid + 1, hi, l, r, 2 * v + 2);
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
    //cout << "Case "<<tt<<" :";
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> st(2 * n + 1, 0);
    for(ll i = 0; i < n; i++){
      cin >> arr[i];
    }
    build(st, arr, 0, n - 1, 0);
    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++){
      char c;
      cin >> c;
      if(c == 'u'){
        ll idx, value;
        cin >> idx >> value;
        update(st, arr, 0, n - 1, idx, value, 0);
      }
      else{
        ll l, r;
        cin >> l >> r;
        cout << query(st, arr, 0, n - 1, l, r, 0) << endl;
      }
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    