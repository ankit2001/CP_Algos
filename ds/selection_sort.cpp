#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void selection_sort(ll *arr,ll n){
	for(ll i=0;i<n-1;i++){
		ll mini=arr[i];
		ll min_index=i;
		for(ll j=i+1;j<n;j++){
			if(arr[j]<mini){
				mini=arr[j];
				min_index=j;
			}
		}
		swap(arr[i],arr[min_index]);
	}
}
int main(){
	ll n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	ll arr[n];
	cout<<"Enter elements"<<endl;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	selection_sort(arr,n);
	cout<<"Sorted array is:"<<endl;
	for(ll i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
    return 0;
}