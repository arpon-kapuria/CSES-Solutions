/*
Problem Link: https://cses.fi/problemset/task/1640/

Approach:

- The goal is to find two numbers whose sum equals x.
- Iterate over the array while maintaining a map of previously seen numbers and their indices.
- For each element, check if (x - current_value) exists in the map; if yes, we found the pair else store it in map.
- If no such pair is found after traversal, print "IMPOSSIBLE".

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> values(n);

  for(int i=0; i<n; i++) {
    cin >> values[i];
  }

  map<int, int> map;

  for(int i = 0; i < n; i++) {
    if(map.count(x - values[i])) {
      cout << i+1 << " " << map[x - values[i]] << endl;
      return 0;
    }
    map[values[i]] = i+1;
  }

  cout << "IMPOSSIBLE" << endl;
}
