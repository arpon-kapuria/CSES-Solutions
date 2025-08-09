/*
Problem Link: https://cses.fi/problemset/task/1094/

Approach:

- Traverse the array from left to right, checking if the current element is smaller than the previous one.
- If smaller, increase it to match the previous element and add the difference to the total count.
- Continue until the end to get the total increments required.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> input(n);

  for(auto i=0; i<n; i++)
    cin >> input[i];

  long long count = 0;
  
  for(auto i=1; i < n; i++){
    if (input[i - 1] > input[i]) {
      count += input[i - 1] - input[i];
      input[i] = input[i - 1];
    }
  }

  cout << count;

}


