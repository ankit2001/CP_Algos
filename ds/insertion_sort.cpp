#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void insertion_sort(ll *arr,ll n){
	for(ll i=1;i<n;i++){
		ll el=arr[i];
        ll j=i-1;
        while(j>=0&&arr[j]>el){
       	    arr[j+1]=arr[j];
       	    j--;
        }
        arr[j+1]=el;
	}
}
int main(){
   cout<<"Enter size of array"<<endl;
   ll n;
   cin>>n;
   ll arr[n];
   cout<<"Enter elements"<<endl;
   for(ll i=0;i<n;i++){
       cin>>arr[i];
   }
   insertion_sort(arr,n);
   cout<<"Sorted array is:"<<endl;
   for(ll i=0;i<n;i++){
   	   cout<<arr[i]<<" ";
   }
   cout<<endl;
   return 0;
}