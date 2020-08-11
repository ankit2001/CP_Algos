#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	cout<<"Enter the postfix expression : "<<endl;
    string post;
    getline(cin,post);
    stack<ll> st;
    for(ll i=0;i<post.length();i++){
    	if(post[i]==' '){
    		continue;
    	}
    	else if(isdigit(post[i])){
            ll num=0;  
            while(isdigit(post[i])){
                num=num*10+(ll)(post[i] - '0');  
                i++;  
            }  
            i--;  
            st.push(num); 
        }
    	else{
    		ll a=st.top();
    		st.pop();
    		ll b=st.top();
    		st.pop();
    		if(post[i]=='+'){
    			st.push(b+a);
    		}
    		else if(post[i]=='-'){
    			st.push(b-a);
    		}
    		else if(post[i]=='*'){
    			st.push(b*a);
    		}
    		else if(post[i]=='/'){
    			st.push(b/a);
    		}
    		else if(post[i]=='|'){
    			st.push(b|a);
    		}
    		else if(post[i]=='&'){
    			st.push(b&a);
    		}
    		else if(post[i]=='^'){
    			st.push(b^a);
    		}
    		else if(post[i]=='%'){
    			st.push(b%a);
    		}
    	}
    }
    cout<<"After solving the expression, final answer is : "<<endl;
    cout<<st.top()<<endl;
    return 0;
}