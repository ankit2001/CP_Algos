#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n = 100000;
void print(ll *arr, ll n){
	for(ll i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert(ll x, ll val, ll *size, ll *arr){
	if(x < 0 or x > *size or *size == 2 * n){
		cout << "Insertion is not possible" << endl;
		return ;
	}
	for(ll i = *size; i > x; i--){
		arr[i] = arr[i - 1];
	}
	arr[x] = val;
	*size += 1;
	return;
}

void remove(ll idx, ll *arr, ll *size){
	if(*size == 0 or idx >= *size or idx < 0){
		cout << "Deletion is not possible" << endl;
		return ;
	}
	for(ll i = idx; i < *size - 1; i++){
		arr[i] = arr[i + 1];
	}
	*size -= 1;
	return ;
}
int main(){
	ll size;
	cout << "Enter size of array" << endl;
	cin >> size;
	ll arr[2 * 100000];
	cout << "Enter elements in array" << endl;
	for(ll i = 0; i < size; i++){
		cin >> arr[i];
	}
	cout << "Output array :" << endl;
	print(arr, size);
	cout << "Enter the position you want to insert in array " << endl;
	ll x;
	cin >> x;
	cout << "Enter the value of element you want to insert " << endl;
	ll val;
	cin >> val;
	insert(x, val, &size, arr);
	cout << "Array after insertion :" << endl;
	print(arr, size);
	cout << "Enter the index of element you want to delete " << endl;
	ll k;
	cin >> k;
	remove(k, arr, &size);
	cout << "Array after deletion" << endl;
	print(arr, size);
	return 0;
}