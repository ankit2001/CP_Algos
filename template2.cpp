#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define db double
#define f(i, a, n, x) for (ll i = a; i <= n; i = i + x)
#define rf(i, a, n, x) for (ll i = a; i >= n; i = i - x)
#define bs(start, end, value) binary_search(start, end, value)
#define is(start, end) is_sorted(start, end)
#define np(start, end) next_permutation(start, end)
#define pp(start, end) prev_permutation(start, end)
#define fastio()               \
  ios::sync_with_stdio(false); \
  cin.tie(NULL);               \
  cout.tie(NULL);
#define F first
#define S second
#define endl "\n"
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mt make_tuple
#define mp make_pair
#define all(v) v.begin(), v.end()
#define ub(v, value) upper_bound(all(v), value) - v.begin()
#define lb(v, value) lower_bound(all(v), value) - v.begin()
#define indexof(i, n) (n + i) % n
#define precision(x) cout << fixed << setprecision(x)

#define get1(a) \
  ll a = 1;     \
  cin >> a;
#define get2(a, b) \
  ll a, b;         \
  cin >> a >> b;
#define get3(a, b, c) \
  ll a, b, c;         \
  cin >> a >> b >> c;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define iarr(arr, n) \
  ll arr[n];         \
  f(i, 0, n - 1, 1) cin >> arr[i];
#define oarr(arr, n)                       \
  f(i, 0, n - 1, 1) cout << arr[i] << " "; \
  cout << endl;
#define ivec(veci, n) \
  vector<ll> veci(n); \
  f(i, 0, n - 1, 1) cin >> veci[i];
#define ovec(veci, n)                       \
  f(i, 0, n - 1, 1) cout << veci[i] << " "; \
  cout << endl;

using pa = pair<ll, ll>;
using vec = vector<ll>;
using dque = deque<ll>;
using que = queue<ll>;
using stk = stack<ll>;
using pque = priority_queue<ll>;
using um = unordered_map<ll, ll>;
using sm = map<ll, ll>;
using umm = unordered_multimap<ll, ll>;
using mm = multimap<ll, ll>;
using us = unordered_set<ll>;
using ss = set<ll>;
const ll MIN = -10000000;
const ll INF = INT_MAX, N = 500000004;
const double PI = acos(-1);
const ll LINF = LLONG_MAX;
ll MOD = 998244353;

ll power(ll x, ll n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power(((x % MOD) * (x % MOD)) % MOD, n / 2);
  else
    return ((x % MOD) * (power(((x % MOD) * (x % MOD)) % MOD, (n - 1) / 2) % MOD)) % MOD;
}

bool prime[10000000 + 1];
void picop(ll n) {
  memset(prime, true, sizeof(prime));
  for (ll p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (ll i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
}

ll gcd_method(ll a, ll b, ll *x, ll *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcd_method(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

ll inverse(ll a, ll m) {
  ll x, y;
  ll g = gcd_method(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    ll res = (x % m + m) % m;
    return res;
  }
}

ll divide(ll x, ll y) {
  return ((x % MOD) * inverse(y, MOD)) % MOD;
}

ll sub(ll x, ll y) {
  x -= y;
  if (x < 0)
    return x + MOD;
  return x;
}

ll add(ll x, ll y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

ll multiply(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

ll lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}
bool checkroot(ll b) {
  return sqrt(b) * sqrt(b) == b;
}

int main() {
  fastio();
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt","w",stdout);
  #endif
  ll tc;
  cin >> tc;
  f(tt, 1, tc, 1) {
    ll n;
    cin >> n;
    ll ans = 0;
    ll k = sqrt(n);
    ll mapi[k + 3] = {0};
    f(i, 2, k, 1) {
      if (mapi[i] > 0) {
        continue;
      }
      for (ll a = i * i; a <= n; a = i * a) {
        if (a <= k)
          mapi[a] = 1;
        ans = ans + ((n / a) * a) % MOD;
        ans %= MOD;
      }
    }
    cout << (ans + n % MOD) % MOD << endl;
  }
  return 0;
}