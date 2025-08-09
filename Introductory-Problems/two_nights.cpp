/*
Problem Link: https://cses.fi/problemset/task/1072/

Approach:

- For each i from 1 to t, calculate the total ways to place two knights on an i x i chessboard:
    (i^2 * (i^2 - 1))/2
- Calculate the number of ways two knights attack each other: 4×(i−1)×(i−2).
- Subtract attacking pairs from total pairs to get the count of safe placements.
- Print the result for each board size.

Time Complexity: O(t)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t;
  cin >> t;

  for(long long i=1; i<=t; i++) {
    long long total_ways = ((i*i) * ((i*i)-1))/2;
    long long attack = 4 * (i-1) * (i-2);
    long sol = total_ways - attack;
    cout << sol << endl;
  }
  return 0;
}


