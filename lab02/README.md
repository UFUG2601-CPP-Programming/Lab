# Lab 02 - I Come! I Compute! I Control!

## Our Goal in Lab 02

1. Learn how to use Online Judge to submit your C++ code and see the results
2. Recap the operators and use them to compute
3. Use control syntax (e.g. `if-else`) to control the program

## Task 1: Learn to use Online Judge (OJ)

1. Open the OJ ([http://10.5.178.148/](http://10.5.178.148)) in your web browser. 
2. Log in with your **username** (**username**@connect.hkust-gz.edu.cn) and default **password** (the same as your username).
    1. (Optional) It is recommended to change your password after the first login, but make sure you can remember it.
3. Enter the **contest** tab and enter the first problem - **Red Bird Symbol**.
4. Edit your code on the website (remember to select **"Language: C++"**)
    1. (Optional) If you don’t want to edit the code on the website, you can write it on your computer, and then **upload it** to the website.
5. Submit your code and check the status of your submissions.
6. Complete two problems and try to get **accepted (AC)**. 
7. We will use it to check your sign-up.

> P.S. It is suggested to test your code using the sample inputs and outputs locally before uploading it to the OJ.
### More about the input and the output

On the Online Judge, no matter what language you are using, the input and the output are set to the **Standard IO**, a.k.a. `stdin` and `stdout`. You can look them up if you want to know more about them, or just use `man stdin` and `man stdout` in your Ubuntu terminal to check the manual.

In C++, you can input and output through standard IO using the `std::cin` and `std::cout` from the header `<iostream>`, as you have learned in the previous Lab - “Hello, World!”. 

Moreover, you need to put the `\n` or `std::endl` at the end of your output to start a new line, it is required for some problems to output multiple lines of answers.

### P.S. If you encounter any technical problems on the OJ

The OJ is actually running on one of the TA’s computers, which means that you may encounter:

- Slow responses when there are too many users at the same time.
- Sudden crashes or network issues.
- URL or IP of the OJ changes from time to time. (depending on the network conditions of our campus)
- Can’t access it for certain periods of time. (For example, when my computer “blows up” because I spill my K coffee on my machine)
- …

We will try to keep the OJ as stable as possible, at least during the lab sessions.

## Example: Compute A+B with integer variables
```cpp
#include <iostream>

int main(){
	
	int a, b;
	
	// Input the variables
	std::cin >> a >> b;
	
	// Output the result of a+b
	std::cout << a+b << std::endl;
	return 0;
}
```

## Task 2: Learn the operators for integers

1. Clone or update our GitHub folder using the knowledge you’ve learned.
2. Open the folder with VS Code or your favorite editor, then edit the code in `lab02.cpp`
3. Use `make` or `g++` commands to compile and run the program.
    1. This time, compiling and running are separated in the makefile. `make lab02` to compile, and `make run` to run. You can also use the latter one directly.
4. Try different operators you learned from the lecture last week, and observe the results.
5. (Optional) Check the Makefile and learn the format.

## Example: Using the `if-else` branches to get absolute values

```cpp
#include <iostream>

int main(){
	
	int a;

	std::cin >> a;
	// Start an if-else block
	if (a >= 0){
		std::cout << a << std::endl;
	}
	else{
		std::cout << -a << std::endl;
	}

	return 0;
}
```

## Task 3: Try to finish the problem 002L on the OJ

1. Open the online judge and find the problem **002L -** **Arithmetic Logic Unit (ALU).**
2. Try to solve the problem using `if-else` branches and operators.

## Thinking Time

- Observe the samples of 002L. Why do we always get `-1` when applying right shifting on `-1`?
- What is the difference between `integer` and `unsigned integer` when applying right shifting?

## Additional Contents
### What is the lazy evaluation?
**Lazy evaluation** is a technique where expressions are not evaluated until they are actually needed. This can save computation time and resources, especially in cases where the expressions are complex or time-consuming to evaluate.

Here is a simple example in C++ that demonstrates lazy evaluation:
```CPP
#include <iostream>

int main() {
  int x = 5;
  int y = 10;
  bool result = (x > 3) && (y < 5);
  
  std::cout << "Result: " << result << std::endl;
  
  return 0;
}
```

In this example, we have two integer variables `x` and `y`, and a boolean variable result. We also have an expression that checks if `x` is greater than `3` and if `y` is less than `5`. However, because of lazy evaluation, the second part of the expression `y < 5` is never evaluated. This is because the first part of the expression `x > 3` is already `false`.

Another complex example is demonstrated as follows:
```CPP
int a = 0, b = 1, c = 1;
if (a++ && (c=b+a)){
	++b;
}
```
In this example, we decalure and initialize three variables `a = 0`, `b = 1` and `c = 1`

We use an if statement with a compound condition. The compound condition consists of two expressions connected with the logical AND operator.

The first expression in the compound condition is `a++`. This uses the post-increment operator, which increments the value of `a` by 1 after the expression is evaluated. Since the initial value of `a` is 0, the expression evaluates to `false`, and `a` is incremented to 1.

Due to the **lazy evaluation,** the compound condition in the if statement directly evaluates to `false`.

After the code snippet has executed, the value of the variables are: `a = 1`, `b = 1`, `c = 1`