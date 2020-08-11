#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Stack{
public:
    T* data;
    ll max_size;
    ll size;
    ll last;
    Stack(ll array_size){
        data = new T[array_size];
        this -> max_size = array_size;
        this -> size = 0;
        this -> last = -1;
    }

    ll length(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

    T top(){
        if(size == 0){
            cout << "No element is present in stack " << endl;
            return 0;
        }
        return data[last];
    }

    void push(T x){
        if(size == max_size){
            cout << "Overflow occur " << endl;
            return;
        }
        last++;
        data[last] = x;
        size++;
    }

    T pop(){
        if(size == 0){
            cout << "No element is present in stack" << endl;
            return 0;
        }
        T ans = data[last];
        last--;
        size--;
        return ans;
    }

    void print(){
        for(ll i = 0; i <= last; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    cout << "Enter the capacity of stack you want to make :" << endl;
    ll cap;
    cin >> cap;
    Stack<ll> s(cap);
    cout << "Enter the element you want to push in the stack" << endl;
    ll el;
    cin >> el;
    s.push(el);
    cout << "After the push operation elements in stack are :" << endl;
    s.print();
    cout << "Size of stack is :" << endl;
    cout << s.length() << endl;
    ll a, b;
    cout << "Enter 2 elements for pushing in stack :" << endl;
    cin >> a >> b;
    s.push(a);
    s.push(b);
    cout << "After push operation elements in stack are :" << endl;
    s.print();
    cout << "Top element in stack " << endl;
    cout << s.top() << endl;
    cout << "After pop operation elements in stack are : " << endl;
    s.pop();
    s.print();
    cout << "Check is empty" << endl;
    cout << s.empty() << endl;
    return 0;
}