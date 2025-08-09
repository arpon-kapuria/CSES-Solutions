/*
Problem Link: https://cses.fi/problemset/task/1070/

Approach:

- The task is to arrange numbers from 1 to n so that no two adjacent numbers differ by 1.
- If n is 1, print 1; if n is 2 or 3, print "NO SOLUTION" since no valid arrangement exists.
- For larger n, separate even and odd numbers.
- Print all odd numbers first in descending order, then even numbers in descending order, and if n is odd, print n at the end.
- This arrangement ensures no adjacent numbers differ by 1.

Time Complexity: O(n) 
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n == 1) {
    cout << n << endl;
    return 0;
  }

  if(n <= 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  int start = (n & 1) ? n-1:n;
  for(int i = start-1; i > 0; i-=2)
    cout << i << " ";
  for(int i = start; i > 0; i-=2)
    cout << i << " ";

  if(n & 1)
    cout << n << endl;

}



