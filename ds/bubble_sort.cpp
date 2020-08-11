#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void bubble_sort(ll *arr,ll n){
	for(ll i=0;i<n-1;i++){
		for(ll j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main(){
	ll n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	ll arr[n];
	cout<<"Enter elements in array"<<endl;
	for(ll i=0;i<n;i++){
      cin>>arr[i];
	}
	bubble_sort(arr,n);
	cout<<"Sorted array is :"<<endl;
	for(ll i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}