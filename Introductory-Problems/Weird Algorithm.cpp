/*
Problem Link: https://cses.fi/problemset/task/1068/

Approach:

- Implement the Collatz sequence (also known as the 3n + 1 problem) starting from a given number n.
- If n is even, divide it by 2; if odd, multiply by 3 and add 1.
- Repeat the process until n reaches 1.
- Print each number in the sequence to trace the steps.

Time Complexity: Depends on n but generally unknown, typically behaves like O(logn) in practice.
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  while (true) {
    cout << n << " ";
    if (n == 1)
      break;
    if (n % 2 == 0) n /= 2;
    else n = 3*n + 1;
  }

}
