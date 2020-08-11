#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll search(ll value, ll *arr, ll n){
	ll idx = -1;
	for(ll i = 0; i < n; i++){
		if(arr[i] == value){
			idx = i;
			break;
		}
	}
	return idx;
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
	ll x;
	cout << "Enter the element you want to search in the array :" << endl;
	cin >> x;
	ll idx = search(x, arr, n); 
	if(idx == -1){
		cout << "Element not found in array :" << endl;
	} 
	else cout <<"Element found at index : " << idx << " " << endl;
	return 0;
}