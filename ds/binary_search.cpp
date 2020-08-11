#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	ll arr[n+1],copy[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		copy[i]=arr[i];
	}
	cout<<"Enter item you want to find in the array"<<endl;
	ll ITEM;
	cin>>ITEM;
	sort(copy,copy+n);
	cout<<ITEM<<endl;
	ll found_index=-1;
	ll lo=0,hi=n-1;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		if(copy[mid]<ITEM){
			lo=mid+1;
		}
		else if(copy[mid]>ITEM){
			hi=mid-1;
		}
		else if(copy[mid]==ITEM){
			found_index=mid;
			break;
		}
	}
	if(found_index!=-1){
		for(ll i=0;i<n;i++){
			if(arr[i]==copy[found_index]){
				found_index=i;
				break;
			}
		}
		cout<<"ITEM was found in array at index "<<found_index<<endl;
		cout<<"Now after deleting this element array will be:"<<endl;
		for(ll i=found_index+1;i<n;i++){
			arr[i-1]=arr[i];
		}
		for(ll i=0;i<n-1;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"ITEM was not found in array"<<endl;
		cout<<"Enter the position at which you want to insert it"<<endl;
		ll k;
		cin>>k;
		cout<<"After adding the element at kth position array will be"<<endl;
		for(ll i=n-1;i>=k;i--){
			arr[i+1]=arr[i];
		}
		arr[k]=ITEM;
		for(ll i=0;i<n+1;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;

}