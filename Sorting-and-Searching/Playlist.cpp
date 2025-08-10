/*
Problem Link: https://cses.fi/problemset/task/1141/

Approach:

- The task is to find the length of the longest subarray with all distinct elements.
- Use a sliding window approach with two pointers: start and end to track the current subarray.
- Maintain a map storing each element's last seen index; when a duplicate is found within the current window, move start to the position after its last occurrence.
- Continuously update the maximum length found on each iteration.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  
  vector<ll> nums(n);
  for(ll i=0; i<n; i++){
    cin >> nums[i];
  }

  map<ll, ll> mp;
  ll start = 0, len = 0;

  for(ll end = 0; end < n; end++) {
    if(mp.find(nums[end]) == mp.end()){
      mp.insert(make_pair(nums[end], end));
    } else {
      if(mp[nums[end]] >= start)
        start = mp[nums[end]] + 1;
      mp[nums[end]] = end;
    }

    len = max(len, end-start+1);
  }

  cout << len << "\n";

}



