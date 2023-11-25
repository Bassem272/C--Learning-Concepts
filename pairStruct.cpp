#include <utility>
#include <iostream>
#include <vector>
using namespace std;
int main (){

    struct car {
        int price ;
        string brand;
    };

    struct {
        int length;
        string name;
    }being;

    being.length= 234;
    being.name = "Bob";
    cout<<being.length<<" "<<being.name<<endl;

    pair<int ,string> p1;
    p1.first = 100;
    p1.second = "Bob";
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,string> home = make_pair(10,"Basssem ");

    cout<<home.first<<" "<<home.second<<endl;


    car car1;
    car1 .price = 100000;
    car1.brand = "BMW";
    cout<<"The price of the car is "<<car1.price<<" and the brand is "<<car1.brand<<endl;
 vector <pair<int,string>> v;
    v.push_back(make_pair(10,"Basssem"));
    v.push_back(make_pair(20,"Basssem"));

    for(int i =0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    };


    // int n;
    // cin >>n;
    // vector<pair<int,string>> v2(n);
    // for(int i = 0;i<n;i++){

    //     cin>>v2[i].first>>v2[i].second;
    // }
    // for( auto&i:v2) {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    vector<int> v3={1,2,3,4,5,6,7,8,9,1};
       v3.clear();
       for(const auto&i:v3){
           cout<<i<<"after clear"<<endl;
       }
cout<<v3.size()<<endl;
cout<<v3.capacity()<<endl;
cout<<v3.max_size()<<endl;
cout<<v3.empty()<<endl;
cout<<v3.front()<<endl;
cout<<v3.back()<<endl;
cout<<v3.at(0)<<endl;
 // Attempt to iterate over the vector (won't print anything as the vector is empty)
    for (const auto &i : v3) {
        std::cout << i << " after clear" << std::endl;
    }

    // Print vector properties after clearing
    std::cout << "Size: " << v3.size() << std::endl;        // 0
    std::cout << "Capacity: " << v3.capacity() << std::endl; // 10 (implementation-dependent)
    std::cout << "Max Size: " << v3.max_size() << std::endl; // Maximum size supported by the system
    std::cout << "Empty: " << v3.empty() << std::endl;       // 1 (true)

    // Attempting to access elements after clearing (undefined behavior)
    // std::cout << "Front: " << v3.front() << std::endl;
    // std::cout << "Back: " << v3.back() << std::endl;
    // std::cout << "At(0): " << v3.at(0) << std::endl;
std::vector<int> v = {1, 2, 3, 4, 5};
std::cout << "Size: " << v.size() << std::endl;  // Output: 5
std::vector<int> v = {1, 2, 3, 4, 5};
std::cout << "Capacity before reserve: " << v.capacity() << std::endl;  // Output: Implementation-dependent initial capacity
v.reserve(10);  // Set the capacity to 10
std::cout << "Capacity after reserve: " << v.capacity() << std::endl;   // Output: 10

    return 0; 
}