/*
Problem Link: https://cses.fi/problemset/task/1083/

Approach:

- Calculate the sum of the first n natural numbers using the formula (n(n+1)/2).
- Read n-1 numbers from the input, each representing a number present in the sequence.
- Subtract each input number from the total sum to find the missing number.
- The remaining value after subtraction is the missing number in the sequence.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = n * (n+1) / 2;
  
  vector<long long> nums(n);

  for(long long i=1; i < n; i++) {
    cin >> nums[i];
    sum -= nums[i];
  }
  
  cout << sum << endl; 
  return 0;
}
