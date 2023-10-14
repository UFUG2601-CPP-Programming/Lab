# Lab 05 - The challenges from recurssion

## Our goal in Lab 05
1. Learn to debug your code using vscode.
2. Get an basic inspection of a recursion program.
3. Finish the problem in OJ.

## Fibonacci Series in Recursion
```cpp
#include <iostream>

int fib(int n) {
  if(n <= 1)
    return n;
  return fib(n-1) + fib(n-2);
}

int main() {

  int n;
  std::cout << "Enter number of terms: ";
  std::cin >> n;
  
  std::cout << "Fibonacci Series: ";
  std::cout << fib(n) << std::endl;
  return 0;

}

```

## Task 0:
1. Get the Lab code from Github, and open the Lab folder in VS Code or your favorite editor.
2. Create a folder call `.vscode` in the root directory of your Lab folder.
3. Copy `launch.json` and `tasks.json` into `.vscode` folder.


## Task 1: Debug lab05.cpp
1. Run code and try to debug the lab05.cpp .
2. Try to set breakpoint and press `continue`.
3. Try to press `step over`, `step into` and `step out`.
4. Try to debug lab05.cpp with input 5 step by step.


## Task 2: Complete Problem 1 - Small Robot Walks Big Maze in Recursion
1. Please try to complete this task by recursion.
2. You may use the approach you learned in this lab to debug your program. (Directly modify lab05.cpp is fine.)
3. You `must` set a visited array to remember the location that robot visited in case for huge search space.


## Additional Contents (VERY IMPORTANT)
1. Please carefully read file `tasks.json` and `launch.json`. Try to understand every single parameter in this two files. (You may ask GPT to learn)
2. A reading material for understanding vscode debug is here: https://code.visualstudio.com/docs/cpp/launch-json-reference.