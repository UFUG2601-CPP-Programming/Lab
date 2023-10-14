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
