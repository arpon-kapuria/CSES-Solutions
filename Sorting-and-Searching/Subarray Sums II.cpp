/*
Problem Link: https://cses.fi/problemset/task/1661/

> Intuition: 
- We use a prefix sum to keep track of the sum of elements up to the current index.
- If at index i the prefix sum is S, then any earlier index j with prefix sum S - k indicates that the subarray (j+1 ... i) sums to k.
- Instead of scanning backwards each time (which is O(n^2)), we store counts of each prefix sum in a hash map so we can instantly know how many earlier subarrays match.
- This works even with negative numbers because prefix sums naturally handle offset overlaps.

> Approach:
- Maintain a running prefix sum as you iterate over the array.
- Keep a hash map storing (prefixSumValue, countOfOccurrences). Initialize with (0, 1) so subarrays starting at index 0 are counted.
- For each prefix sum S, the number of subarrays ending at the current index with sum k is map[S - k].
- Increment count by map[S - k], then increment map[S] for the current prefix sum.

> Example:
Array: 3 4 7 -2 2 1 4 2, k = 7
Prefix sums: 3 7 14 12 14 15 19 21
Map evolution: (0,1), (3,1), (7,1), (14,2), (12,1), (15,1), (19,1), (21,1)
When prefixSum = 21:
    21 - 7 = 14 -> map[14] = 2 means there are two earlier positions (indices 2 and 4) that produce subarrays summing to 7:
Index 3 -> 7: -2 2 1 4 2
Index 5 -> 7: 1 4 2
This is why we add map[S - k] (not just 1) to the count.

Time Complexity: O(n)
Space Complexity: O(n)

Time Complexity: 
Space Complexity: 
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    ll k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll count = 0, prefixSum = 0;
    map<ll, ll> map;
    map[0] = 1;

    for (ll i = 0; i < n; i++) {
        prefixSum += nums[i];
        if (map.find(prefixSum - k) != map.end()) {
            count += map[prefixSum - k];
        }
        map[prefixSum]++;
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}