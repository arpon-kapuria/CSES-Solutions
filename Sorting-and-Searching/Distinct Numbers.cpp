/*
Problem Link: https://cses.fi/problemset/task/1621/

Approach:

- Insert each number into a set to automatically remove duplicates.
- Output the size of the set as the count of unique numbers.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> numbers;

  for(int i=0; i<n; i++) {
    int num;
    cin >> num;
    numbers.insert(num);
  }

  cout << numbers.size() << endl;
}
