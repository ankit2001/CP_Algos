// MOD functions
ll power(ll x,ll n){
  if(n == 0)
      return 1;
  else if(n % 2==0)       
      return power(((x % MOD)*(x % MOD)) %MOD , n/2);
  else                            
      return ((x % MOD)*(power(((x % MOD)*(x % MOD)) % MOD, (n-1)/2) % MOD)) % MOD;
}
ll sub(ll x,ll y) {
  return (x % MOD- y % MOD + MOD )%MOD;
}
         
ll add(ll x,ll y) {
  return (x % MOD + y % MOD) % MOD;
}
         
ll multiply(ll a,ll b){
  return ((a % MOD)*(b % MOD)) % MOD;
}
ll divide(ll x,ll y){
  return multiply(x % MOD, power(y, MOD - 2)) % MOD;
}

// lcm
ll lcm(ll a,ll b){  
  return (a*b)/__gcd(a, b);  
}

// ncr
ll fact[1000000 + 1];
 
void comb(){
  fact[0] = 1;
  for(ll i = 1; i <= 1000000; i++){
    fact[i] = multiply(fact[i - 1], i);
  }
}
 
ll ncr(ll n, ll r){
  if(r > n || n < 0 || r < 0) return 0;
  if(n == 0 || r == 0){
    return 1;
  }
  ll ans = fact[n];
  ans = divide(ans, fact[r]);
  ans = divide(ans, fact[n - r]);
  return ans;
}

// seive
ll prime[10000000 + 1];
void picop(ll n){   
  memset(prime, true, sizeof(prime)); 
  for(ll p = 2; p * p <= n; p++){ 
    if(prime[p] == true){ 
        for(ll i = p * p; i <= n; i += p) prime[i] = false; 
    } 
  }    
}

// inverse using gcd
ll gcd_method(ll a, ll b, ll *x,ll *y){
  if(a == 0){
    *x = 0, *y = 1; 
    return b;
  } 
  ll x1, y1; 
  ll gcd = gcd_method(b % a, a, &x1, &y1); 
  *x = y1 - (b / a) * x1; 
  *y = x1; 
  return gcd; 
} 
     
ll inverse(ll a,ll m){
  ll x, y; 
  ll g = gcd_method(a, m, &x, &y); 
  if(g != 1) return -1;
  else{
    ll res = (x % m + m) % m; 
    return res;
  }
} 