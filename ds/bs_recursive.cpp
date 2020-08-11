#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void print(ll *arr, ll n){
	for(ll i = 0; i < n; i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
}
ll bs_recur(ll val, ll *arr, ll lo, ll hi){
	if(lo <= hi){
		ll mid = lo + hi >> 1;
		if(arr[mid] > val){
			bs_recur(val, arr, lo, mid - 1);
		}
		else if(arr[mid] < val){
			bs_recur(val, arr, mid + 1, hi);
		}
		else if(arr[mid] == val){
			return mid;
		}
	}
	else return -1;
}
int main(){
	ll n;
	cout << "Enter size of array :" << endl;
	cin >> n;
	ll arr[n];
	cout << "Enter elements in array :" << endl;
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Sorted array is :" << endl;
	sort(arr, arr + n);
	print(arr, n);
	ll x;
	cout << "Enter the element you want to search in the array :" << endl;
	cin >> x;
	ll idx = bs_recur(x, arr, 0, n - 1); 
	if(idx == -1){
		cout << "Element not found in array :" << endl;
	} 
	else cout <<"Element found at index : " << idx << " " << endl;
	return 0;
}