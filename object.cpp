#include<iostream>

using namespace std;

class animal{
private:
int age=12;
public:
 animal(int u):age(u){
    cout<<"Constructor called"<<endl;}

int getAge(){
return age;
}
};



int main(){
    animal dog(56);
   int adde= dog.getAge();
   cout<<"animal age is "<<adde<<endl;

    return 0;
}