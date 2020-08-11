#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void merge(ll start,ll mid,ll end,ll *arr){
    ll left[mid-start+1];
    ll right[end-mid];
    for(ll i=0;i<mid-start+1;i++){
    	left[i]=arr[i+start];
    }
    for(ll i=0;i<end-mid;i++){
    	right[i]=arr[i+mid+1];
    }
    ll i=0,j=0,index=start;
    while(i<mid-start+1 && j<end-mid){
    	if(left[i]<=right[j]){
    		arr[index]=left[i];
    		i++;
    		index++;
    	}
    	else{
    		arr[index]=right[j];
    		j++;
    		index++;
    	}
    }
    while(i<mid-start+1){
    	arr[index]=left[i];
    	i++;
    	index++;
    }
    while(j<end-mid){
    	arr[index]=right[j];
        j++;
        index++;
    }
}

void merge_sort(ll *arr,ll start,ll end){
	if(start>=end){
		return;
	}
	ll mid=(start+end)/2;
	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
    merge(start,mid,end,arr);
}

int  main(){
	cout<<"Enter size of array"<<endl;
	ll n;
	cin>>n;
	cout<<"Enter elements in the array"<<endl;
	ll arr[n];
	for(ll i=0;i<n;i++){
	    cin>>arr[i];
	}
    merge_sort(arr,0,n-1);
    cout<<"Sorted array is:"<<endl;
    for(ll i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}