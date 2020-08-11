#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll partition(ll *arr,ll start,ll end){
	ll pivot_element=arr[end];
	ll index=start-1;
	for(ll i=start;i<end;i++){
		if(arr[i]<pivot_element){
			index++;
			swap(arr[i],arr[index]);
		}
	}
	swap(arr[index+1],arr[end]);
	return index+1;
}

void quick_sort(ll *arr,ll start,ll end){
	if(start>=end){
		return;
	}
	ll pivot_index=partition(arr,start,end);
	quick_sort(arr,start,pivot_index-1);
	quick_sort(arr,pivot_index+1,end);
}

int main(){
	ll n;
	cout<<"Enter size of array:"<<endl;
	cin>>n;
	cout<<"Enter elements in array:"<<endl;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
    cout<<"Sorted array is :"<<endl;
    quick_sort(arr,0,n-1);
    for(ll i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
