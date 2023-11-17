#include<iostream>

using namespace std;
template<typename T>
T sum(T a , T b){

    T sum = a + b;
    cout<<"sum of "<<a<<" and "<<b<<" is "<<sum<<endl;
    return sum;
}





int main(){
 
int s =sum(10,20);
cout<<s<<endl;
 
 
 
    return 0; 
}