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

ll n;
vector<ll> arr(100000);
vector<ll> st(2 * 100000 + 1, MIN);

void build(vector<ll> &st, vector<ll> &arr, ll lo, ll hi, ll v){
  if(lo == hi){
    st[v] = arr[lo];
    return ;
  }
  ll mid = lo + hi >> 1;
  build(st, arr, lo, mid, 2 * v + 1);
  build(st, arr, mid + 1, hi, 2 * v + 2);
  st[v] = max(st[2 * v + 1], st[2 * v + 2]);
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
  st[v] =  max(st[2 * v + 1], st[2 * v + 2]);
}

ll query(vector<ll> &st, vector<ll> &arr, ll lo, ll hi, ll l, ll r, ll v){
  if(lo > r or hi < l){
    return MIN;
  }
  if(lo >= l and hi <= r){
    return st[v];
  }
  ll mid = lo + hi >> 1;
  return max(query(st, arr, lo, mid, l, r, 2 * v + 1), query(st, arr, mid + 1, hi, l, r, 2 * v + 2));
}

ll check(ll mid){
  return query(st, arr, 0, n - 1, 0, mid, 0);
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
    cin >> n;
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
        ll x;
        cin >> x;
        ll lo = 0, hi = n - 1, ans = -1;
       while(lo <= hi){
          ll mid = lo + hi >> 1;
          if(check(mid) >= x){
            ans = mid;
            hi = mid - 1;
          }
          else{
            lo = mid + 1;
          }
        }
        if(ans != -1){
          cout << ans;
        }
        cout << endl;
      }
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    