/*
Problem Link: https://cses.fi/problemset/task/2165/

Approach:

- Solve the Tower of Hanoi problem recursively by moving n-1 disks from the start peg to the auxiliary peg.
- Move the largest disk from the start peg to the end peg.
- Move the n-1 disks from the auxiliary peg to the end peg.
- The total moves required are 2^n - 1, which is printed before the sequence of moves.

Time Complexity: O(2^n) 
Space Complexity: O(n) due to the recursion stack depth
*/


#include <bits/stdc++.h>
using namespace std;

void moves(int n, int start, int aux, int end) {
  if(n == 0)
    return;

  moves(n-1, start, end, aux);
  cout << start << " " << end << endl;
  moves(n-1, aux, start, end);
}

int main() {
  int n;
  cin >> n;

  cout << (1 << n) -1 << endl;
  moves(n, 1, 2, 3);
}
