/*
Problem Link: https://cses.fi/problemset/task/1617/

Approach:

- There can be 2^n bit strings for length n. We need to calculate 2^n under modulo 10^9+7 to avoid overflow.
- Start with answer = 1 and repeatedly multiply it by 2 for n iterations.
- After each multiplication, take the modulo to keep the value within bounds.
- 

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
  int n, answer = 1;
  cin >> n;

  for(int i=0; i<n; i++) {
    answer *= 2;
    answer %= MOD;
  }

  cout << answer;
} 
