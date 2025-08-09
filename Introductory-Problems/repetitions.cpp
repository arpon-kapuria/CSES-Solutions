/*
Problem Link: https://cses.fi/problemset/task/1069/

Approach:

- Iterate through the string while tracking the length of the current sequence of identical consecutive characters.
- Update the maximum length found whenever the current character changes.
- After the loop, compare the last tracked sequence length with the maximum and print the greater value.
- This efficiently finds the longest run of identical consecutive characters in one pass.

Time Complexity: O(n) 
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  string input;
  cin >> input;

  int max = 1;
  int cur_max = 1;
  char cur = input[0];

  for(auto i=1; i < int(input.size()); i++) {
    if (input[i] == cur) {
      cur_max++;
    } else {
      cur = input[i];
      if(cur_max > max) {
        max = cur_max;
      }
      cur_max = 1;
    }
  }
  
  if (cur_max > max) cout << cur_max;
  else cout << max;
}



