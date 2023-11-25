#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
int main(){
    string str1; 
getline(cin, str1);
set<char> s1(str1.begin(), str1.end());

if( s1.size() % 2 == 0 ){
    cout<<"CHAT WITH HER!"<<endl;
 
}else{
    cout<<"IGNORE HIM!"<<endl;
}

    return 0;
}