#include <iostream>
using namespace std;

int main() {
    long long a = INT32_MAX-1282, b = INT32_MAX-8;
    cin >> a >> b;
    for(long long i=a; i<=a+8; i++) {
        for(long long j=b; j<=b+8; j++) {
        cout << i*j << "\t";
        }
    cout << "\n";
  }
  return 0;
}