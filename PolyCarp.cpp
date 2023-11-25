#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n; 

  vector<string> v(n);
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s; cin>>v[i];  
    }
    for (int i=n-1;i>=0;i--){
        if( mp[v[i]] == 0 ){
            mp[v[i]] = 1;
            cout<<v[i]<<endl;
        }
        
       
    }





    return 0; 
}