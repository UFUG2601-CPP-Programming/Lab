## Our Goal in Lab 03
1. Review the basic of `Makefile``.
2. Learn the usage of **`for` Loops**.
3. Solve problems with **`for` Loops**.

## Task 0: Setup Your Github Repo on the Computer again

(This part will not be repeated in the next lab)

### If you want to clone a new directory directly

```bash
git clone https://github.com/UFUG2601-CPP-Programming/Lab.git
```

### If you ALREADY HAVE the repo

```bash
cd <path-to-your-repo>
git stash
git pull
(optional) git pull origin main
```

This time we only use the code here to review the usage of Makefile again:
1. Enter the `lab03` directory using `cd`.
2. Try to use `make` to compile directly.
3. Run the output program using `./lab03` or `make run`.
4. Read the contents in the `Makefile`, try to modify it to compile `lab03_2.cpp` instead of `lab03_1.cpp`.
5. Compile and run the program agagin to see if you successfully changed the source file.
6. (Optional) Try to modify the `Makefile` to generate different executables for different source files.

## A For Loop Code Example

Here is an example exercise to write a C++ program that prints out a 9*9 multiplication table

```cpp
#include <iostream>
using namespace std;

int main() {
  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) {
      cout << i*j << "\t";
    }
    cout << "\n";
  }
  return 0;
}
```

# Finish Problems in Online Judge

## Task 1: A new 9 * 9 Multiplication Table

- This is a very simple task that requires you to print a 9*9 multiplication table using the `for` loops.
- You only need to use 2-level `for` loops.
- Kindly please mind the range of data.
- Please use `\t` for aligned outputs.

## Task 2: **Perfect Square Checker**
- Firstly, Try to use `<math>` header and `sqrt` function to solve the problem.
- Then, try to solve the problem without `sqrt`.
- Just simply write a for loop to check every square of the number.
- A template for solving this problem is shown as follows:

```cpp
int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;++i){
      int A;
      cin>>A;
      //Write your code
    }
    return 0;
}
```

## Thinking Time: How to improve the solving time of Task 2?

A very important and basic algorithm in programming is the binary searching. You can try to learn the idea of this algorithm.

![Binary Search](./img/binary%20search.png)

Example code of binary search in Task 2.

```cpp
bool isPerfectSquare(int num) {
    if (num < 2)
        return true;
    long left = 2, right = num / 2, mid, guess;
    while (left <= right) {
        mid = left + (right - left) / 2;
        guess = mid * mid;
        if (guess == num)
            return true;
        if (guess > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}
```

## Additional Contents
To practice C++ programming, there are many public platforms besides our Online Judge.

Here are some recommendations:
+ https://leetcode.com/
+ https://uoj.ac/
+ http://poj.org/
+ https://www.luogu.com.cn/
+ https://codeforces.com/
+ https://vjudge.net/
