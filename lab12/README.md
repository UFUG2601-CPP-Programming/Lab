# Lab 12 - Inheritance is All You Need

## Our Goal in Lab 12

1. Learn the basic usage of inheritance in C++ classes.
2. Learn the virtual functions in C++ classes.
3. Try and build different inheritance structures to see the differences.

## Inheritance: Call Your Parent

```cpp
class Parent{
public:
	string getName() const {return name;};
private:
	string name="Parent";
};

class Child: public Parent{
public:
	string getChildName() const {return name;};
private:
	string name="Child";
};

int main(){
	Child Jerry;
	cout << Jerry.getName() << " " << Jerry.getChildName() << endl;
	return 0;
}
```

The most basic usage of inheritance is to reuse some shared features and functions from the parent(base) classes in the children(derived) classes.

## Inheritance: Construct and Destroy

```cpp
class Foo{
public:
	Foo(){cout<<"Foo Constructed!"<<endl;}
  ~Foo(){cout<<"Foo Destoryed!"<<endl;}
};

class Bar: public Foo{
public:
	Bar(){cout<<"Bar Constructed!"<<endl;}
  ~Bar(){cout<<"Bar Destoryed!"<<endl;}
};
```

What will happen if you create and delete a new `Bar`? To explore how the C++ programs construct and destroy a parent class and a child class, you can test the code above to observe the result.

## Task 1: Complete the Inheritance Experiments in Lab12-1

1. Open the code `lab12-1.cpp` and try to understand the process of the inheritances.
2. Use `make task1` to compile the code.
3. Check the member variables in different classes and learn how to get them in the children classes.
4. Compare the private inheritance and the public inheritance and find out what is public and what is private after inheritance.

## Inheritance: From Virtual to Real

Sometimes, we need different implementations for the same function in the parent class.

```cpp
class Shape{
public:
	virtual double area() const = 0; 
};

class Round : public Shape{
public:
	double area() const;
private:
	int r;
}
double Round::area() const {
    return 3.1415*r*r;
}
class Square : public Shape{
public:
	double area() const;
private:
	int l;
}
double Square::area() const {
    return l*l;
}
```

There are two kinds of virtual functions: virtual and pure virtual.

- Virtual: like the `virtual int perimeter() const{return 0;};` above, the functions will become virtual, which will be automatically overridden by the children(derived) classes.
- Pure virtual: like the `virtual int area() const = 0;` above, the function will become pure virtual when you use `=0` for the function declaration. Pure virtual functions **must** be implemented by the children(derived) class, and you can’t create instances for the base classes with pure virtual functions.

The difference between a virtual function and a non-virtual function is the binding time, **non-virtual functions are binded at runtime, and virtual functions are binded at compile time.**

## Task 2: Complete the Virtual Function Experiments in Lab12-2

1. Open the code `lab12-2.cpp` and learn the inheritance structure of the code.
2. Use `make task2` to compile the code.
3. Compare the difference between virtual and non-virtual declarations.
4. Try to declare and implement the `perimeter()` function.

## Classes and Functions with Template

We have learned to use many containers from standard headers like `<vector>`, and we can find that we use `vector<data_type>` to create the containers for different data types. We can also apply the same syntax to the classes and functions to enable them to handle different data types:

For example, if we want to get the larger one between two values, we can use this kind of implementation with the template:

```cpp
template <typename T>
T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
}

string a = "Hello", b = "World";
cout << Max(a, b) << endl;
```

And also, we can use it to build classes as well:

```cpp
template <class T>
class Stack { 
  private: 
    vector<T> elems;
 
  public: 
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
        return elems.empty(); 
    } 
};
```

This is a very useful technique when you are creating algorithms and data structures for multiple data types.

## Thinking Time

How does the compiler deal with the template functions and classes? 

What’s the difference when we use the template functions/classes with one data type and with multiple data types?

## Additional Contents

You can check the full specification for the virtual function here:

[virtual function specifier - cppreference.com](https://en.cppreference.com/w/cpp/language/virtual)

And also templates:

[Templates - cppreference.com](https://en.cppreference.com/w/cpp/language/templates)

[C++ 模板 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cplusplus/cpp-templates.html)