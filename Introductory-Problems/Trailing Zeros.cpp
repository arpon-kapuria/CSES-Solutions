/*
Problem Link: https://cses.fi/problemset/task/1618/

Approach:

- Count the number of trailing zeros in n! by counting factors of 5, since each zero is created by a pair of 2 and 5, and there are always more 2s than 5s.
- Repeatedly divide n by powers of 5 (5, 25, 125, ...) to count how many multiples contribute extra factors of 5.
- Sum these counts to get the total number of trailing zeros in n!.

Time Complexity: O(log n with base 5) 
Space Complexity: O(n) due to the recursion stack depth
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, count = 0;
  cin >> n;

  for (int i = 5; i <= n; i *= 5)
    count += n / i;

  cout << count;
}
