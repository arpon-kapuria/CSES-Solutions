/*
Problem Link: https://cses.fi/problemset/task/1071/

Approach:

- Identify the maximum of the two coordinates (row or col) to determine the "layer" or "square" in the number spiral.
- Calculate the base number for this layer using (maximum - 1)^2.
- For even layers, numbers increase vertically first; for odd layers, numbers increase horizontally first.
- Use conditions based on parity of maximum and comparison between row and col to calculate the exact number at the given position.

Time Complexity: O(t) — where t is the number of test cases
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t;
  cin >> t;

  while(t--) {
    long long row, col;
    cin >> row >> col;
    
    long long maxi = max(row, col);
    long long square = (maxi-1) * (maxi-1);

    if(maxi % 2 == 0) {
      if(col > row)
        cout << square + row << endl;
      else {
        cout << (maxi*maxi) - (col-1) << endl;
      }
    } 
    else {
      if(col > row)
        cout << (maxi*maxi) - (row-1) << endl;
      else {
        cout << square + col << endl;
      }
    }
  }
  return 0;
}






/*

examples

a) 2, 4 = 11  H
  when max = even and inc
                                formula: square + row

b) 4, 2 = 15  V
  when max = even and dec
                                formula: max*max - col-1

c) 3, 5 = 23  H
  when max = odd and dec
                                fomula: max*max - row-1

d) 5, 3 = 19  V
  when max = odd and inc
                                formula: square + col


1   2   9   10  25  26
4   3   8   11  24  27
5   6   7   12  23  28
16  15  14  13  22  29
17  18  19  20  21  30
36  35  34  33  32  31


*/
