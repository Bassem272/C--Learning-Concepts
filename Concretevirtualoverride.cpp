#include<iostream>
#include<string>


using namespace std;


class shape{
    public:
     virtual void draw() const {
      cout<<"drawing a shape"<<endl;
     };
};

class circle : public shape{
    public: 
      void draw() const override {
        cout<<"Drawing a circle"<<endl;
      };

};

class square : public shape{
    public: 
      void draw() const override {
        cout<<"Drawing a square"<<endl;
      };
};


int main(){
    shape *shapes[2];
    shapes[0] = new circle;
    shapes[1] = new square;
    for(int i=0;i<2;i++){       
        shapes[i]->draw();
        delete shapes[i];
    }






    return 0; 
}