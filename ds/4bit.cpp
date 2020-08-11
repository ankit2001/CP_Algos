#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	string s1;
	string s2;
	cout<<"ENTER 1st number"<<endl;
	cin>>s1;
	cout<<"ENTER 2nd number"<<endl;
	cin>>s2;
	ll ans,count1=0,count2=0,val1=0,val2=0;
	for(ll i=s1.length()-1;i>=0;i--){
       val1+=pow(2,count1)*(s1[i]-'0');
       count1++;
	}
	for(ll i=s2.length()-1;i>=0;i--){
		val2+=pow(2,count2)*(s2[i]-'0');
		count2++;
	}
	ans=val2+val1;
	string f_ans="";
	for(ll i=4;i>=0;i--){
		if(pow(2,i)<=ans){
			f_ans+="1";
			ans-=pow(2,i);
		}
		else f_ans+="0";
	}
	cout<<f_ans<<endl;
}