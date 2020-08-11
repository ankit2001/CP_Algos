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

class store{
public:
  ll max_prefix, max_suffix, sum, max_sum;
};

vector<ll> arr(100000 + 1);
vector<store> st(2 * 100000 + 1);
ll n, q;

store init(ll value){
  store data;
  data.sum = value;
  data.max_suffix = data.max_prefix = data.max_sum = max(0ll, value);
  return data;
}

store merge(store l, store r){
  store data;
  data.sum = l.sum + r.sum;
  data.max_prefix = max(l.max_prefix, l.sum + r.max_prefix);
  data.max_suffix = max(r.max_suffix, r.sum + l.max_suffix);
  data.max_sum = max(max(l.max_sum, r.max_sum), l.max_suffix + r.max_prefix);
  return data;
}
void build(ll lo, ll hi, ll v){
  if(lo == hi){
    st[v] = init(arr[lo]);
    return;
  }
  ll mid = lo + hi >> 1;
  build(lo, mid, 2 * v + 1);
  build(mid + 1, hi, 2 * v + 2);
  st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

void update(ll lo, ll hi, ll idx, ll value, ll v){
  if(lo == hi){
    arr[lo] = value;
    st[v] = init(value);
    return;
  }
  ll mid = lo + hi >> 1;
  if(mid >= idx){
    update(lo, mid, idx, value, 2 * v + 1);
  }
  else{
    update(mid + 1, hi, idx, value, 2 * v + 2);
  }
  st[v] = merge(st[2 * v + 1], st[2 * v + 2]);
}

store query(ll lo, ll hi, ll l, ll r, ll v){
  if(lo > r or hi < l){
    return init(0);
  }
  if(lo >= l and hi <= r){
    return st[v];  
  }
  ll mid = lo + hi >> 1;
  return merge(query(lo, mid, l, r, 2 * v + 1), query(mid + 1, hi, l, r, 2 * v + 2));
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
    build(0, n - 1, 0);
    cin >> q;
    for(ll i = 0; i < q; i++){
      char c;
      cin >> c;
      if(c == 'u'){
        ll idx, value;
        cin >> idx >> value;
        update(0, n - 1, idx, value, 0);
      }
      else{
        ll l, r;
        cin >> l >> r;
        cout << query(0, n - 1, l, r, 0).max_sum << endl;
      }
    }
  }
  cerr<<"Time taken: "<<int((clock()*1000.)/CLOCKS_PER_SEC)<<"ms"<<endl;
  return 0;
}    