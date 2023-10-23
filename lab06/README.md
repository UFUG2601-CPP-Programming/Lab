# Lab 06 - Meet Your Class-mate!

## Our Goal in Lab 06

1. Learn the usage of classes and structs.
2. Learn to build functions around classes and structs.
3. Use classes and structs to design programs with recursions.

## Class and Struct - A way to Abstract

Classes and structs are powerful helpers when we want to construct a complex program involving a lot of components with different data types. For some very simple usages, you can use class and struct when:

- The internal data types are not enough to represent the data you want to handle. For example:

```cpp
#include <cmath>
#include <vector>
// If you have learned the knowledge of complex numbers, they contain two parts: real and imaginary
// However, it's not so easy to operate with them using only floating-point numbers

// Without using classes and structs, we need to store two parts separately.
double real, imag;
double get_modulus(double real, double imag){
	return real*real + imag*imag;
}
// And we need two vectors if we want to store multiple complex numbers
std::vector<double> real, imag, modulus;
for(int i=0; i<real.size(); i++){
	modulus[i] = get_modulus(real[i], imag[i]);
}

// Using classes, we can form the two parts into one data type as complex numbers
// And also define the operations inside the class
class Complex{
// To make the following functions and variables accessible from the outside of the class
public: 
	// Two parts of a complex number
	double real, imag;
	// Constructor function to construct the class, automatically called when declared
	Complex() {};
	// We can use such a function to initialize our classes
	Complex(double real, double imag): real(real), imag(imag){};
	// Define the modulus operation of the complex numbers
	double modulus(){
		return std::sqrt(real*real + imag*imag);
	}
};

// Then, it becomes easier for us to deal with multiple complex numbers
std::vector<Complex> numbers;
std::vector<double> modulus;
for(Complex n : numbers){
	modulus.push_back(n.modulus());
}
```

- Or when you want to form a hierarchy in your program design, which enhances the readability and scalability of your code.

```cpp
class Brain{
public:
	// Define the function
	void think();
};

// Implement the function
void Brain::think(){
	// Blah Blah Blah...
	return;
}

class Human{
public:
	int age;
	Brain brain;
	void move(){
		// Think before moving
		brain.think();
		// Move now
			
	}
};

Human Jerry;
Jerry.age = 18;
Jerry.move();
Jerry.brain.think();
```

In general, it’s more like two styles of programming. However, it has become very common to use classes in modern programming, as well as in languages like Java, Python, and so on.

## Task 1: Complete the Problem On OJ

1. Use learned knowledge about classes and structs to finish problem 008L on OJ.
2. Submit it to the contest during the lab session.

## Task 2: Implement Your Own Class

1. Download the code for lab06 from Github.
2. Read the code and try to complete the functions in the code.
3. Think about how to get the intersection point of two lines. ([Line–line intersection - Wikipedia](https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection))
4. Test if you get the correct results (get the correct overlapped area)

## Thinking Time

- How to compare two variables of the same class, using `==` and other operators?
- Any fast way to complete
- After learning the usage of class, try to use classes to solve the recursion problems in lab 05.

## Additional Contents

### Object-oriented Programming

> Object-oriented programming (OOP) is a programming paradigm based on the concept of objects, which can contain data and code: data in the form of fields (often known as attributes or properties), and code in the form of procedures (often known as methods). — Wikipedia
> 

The class is one of the most important concepts in OOP, and also the major difference between C++ and C.

### Private v.s. Public

Sometimes, it’s not wise to keep everything in a class public. In the second example, for the class `Human` , it’s more reasonable to move `brain` to the private domain, otherwise, you can visit and modify the `brain` without calling the functions of the `Human` :

```cpp
Human Jerry;
Human Tom;
Jerry.brain = Tom.brain; // That's terrible!
```

That’s one of the reasons that we tend to put most of the variables in the private domain and use only public functions to operate with them. For example:

```cpp
class Brain{
private:
	string thoughts;
public:
	// Define the function
	void think();
	void print_thoughts(){ cout << thoughts << endl;};
};

class Human{
private:
	string name;
	int age;
	Brain brain;
public:
	void speak(){
		cout << name << "(" << age << ")" << " says: ";
		brain.print_thoughts();	
	}
};
```