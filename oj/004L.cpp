#include <iostream>
#include <vector>
#include <random>
#include <math.h>
using namespace std;

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

int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;++i){
      int A;
      cin>>A;
      if (isPerfectSquare(A)) {
          cout << "Yes" << endl;
      } else {
          cout << "No" << endl;
      }
    }

    return 0;
}