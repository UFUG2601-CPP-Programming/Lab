/*
Lab 12, Task 1: Basic Inheritance
Goals:
+ Learn the usage of inheritance.
+ Find out how C++ construct and destroy a derived class.
+ Learn the difference between public inheritance and private inheritance.
*/

#include <iostream>
#include <string>

using namespace std;

class Foo{
public:
	Foo(){cout<<"Foo Constructed!"<<endl;}
    ~Foo(){cout<<"Foo Destroyed!"<<endl;}
    string getName() const { return name; }
private:
    string name = "I'm Foo.";
};

class Bar: public Foo{
public:
    Bar(){cout<<"Bar Constructed!"<<endl;}
    ~Bar(){cout<<"Bar Destroyed!"<<endl;}
    string getChildName() const { return name; }
private:
    string name = "I'm Bar.";
};

class Cow: private Bar{
public:
    Cow(){cout<<"Cow Constructed!"<<endl;}
    ~Cow(){cout<<"Cow Destroyed!"<<endl;}
    string getBarName() const {
    // TODO: Try to get the name from Bar when you inherit it privately. 
        return "TODO";
    }
    string getFooName() const {
    // TODO: Try to get the name from Foo when you inherit it privately. 
        return "TODO";
    }
    string getCowName() const { return name; }
private:
    string name = "I'm Cow.";
};

int main(){

    Bar B;

    cout << B.getName() << " " << B.getChildName() << endl;

    // Cow C;
    // cout << C.getFooName() << " " << " " << C.getBarName() << " " << 
    //     C.getCowName() << endl;

    return 0;
}