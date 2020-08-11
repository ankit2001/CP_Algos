#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Student{
public:
	ll roll_no;
	double cgpi;
	string name,semester;
	void input(){
		cout<<"Enter Roll No of student"<<endl;
		ll roll;
		cin>>roll;
		this->roll_no=roll;
        string s;
        cout<<"Enter Name of student"<<endl;
        cin.ignore(1, '\n'); 
        getline(cin,s);
        this->name=s;
        cout<<"Enter CGPI of student"<<endl;
        double CG;
        cin>>CG;
        this->cgpi=CG;
        cout<<"Enter SEM of student"<<endl;
        cin.ignore(1, '\n'); 
        string sem;
        getline(cin,sem);
        this->semester=sem;
	}
	void output(){
		cout<<"Roll no of student is : "<<roll_no<<endl;
		cout<<"Name of student is : "<<name<<endl;
		cout<<"CGPI of student is : "<<cgpi<<endl;
		cout<<"Semester of student is : "<<semester<<endl;
	}
};
int main(){
	Student record[6];
	for(ll i=0;i<5;i++){
		record[i].input();
		cout<<endl;
	}
	double k;
	cout<<"Enter the cgpi for which you want students having cgpi's greater than this:"<<endl;
	cin>>k;
	cout<<"Record of students having cgpi greater than "<<k<<" are given below :"<<endl;
	for(ll i=0;i<5;i++){
		if(record[i].cgpi>k){
			record[i].output();
			cout<<endl;
		}
	}
	ll kth;
	cout<<"Enter value of position at which you wana insert a student record"<<endl;
	cin>>kth;
	if(kth<0 || kth>5){
		cout<<"Position is out of bounds"<<endl;
		return 0;
	}
	else{
		for(ll i=4;i>=kth;i--){
			record[i+1]=record[i];
		}
		Student new_st;
		new_st.input();
		record[kth]=new_st;
		cout<<"Final list of students are :"<<endl;
		for(ll i=0;i<6;i++){
			record[i].output();
			cout<<endl;
		}
	}
}