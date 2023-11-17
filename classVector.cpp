#include<iostream>
using namespace std;

class vector{
    private :
    int sz;
    double* elem;
    public:
    vector(int s):elem{new double[s]},sz{s}{};
    double& operator[](int i){return elem[i];};
    int size() const {return sz;};
    ~vector(){delete[] elem;};

};
enum class Color { red, blue , green };
enum class Traffic_light { green, yellow, red };
 enum  People{ man, woman, child};



int main() {
    People human= People::man;
    cout<<human<<static_cast<int>(human)<<endl;
    
    vector v(8);
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>v[i];
    }

    for(int i=0;i<v.size();i++){

        cout<<v[i]<<" ";



    }
    
    return 0;


}