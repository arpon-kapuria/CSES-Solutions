/*
Problem Link: https://cses.fi/problemset/task/1660/

Intuition: 
We use a sliding window because all numbers are assumed to be non-negative, so expanding the right pointer always increases the sum and shrinking the left pointer always decreases it. This lets us find subarrays with sum exactly k in linear time without backtracking.

Approach:
- Maintain two pointers (start, end) and a running sum of the current window.
- Expand the end pointer until the sum is at least k.
- If the sum exceeds k, move start forward while reducing the sum.
- When the sum equals k, increment the count and move start forward to search for the next subarray.
- Continue until the right pointer passes the last element.

N.B: Main drawback of this sliding window approach is that it only works correctly when all array elements are non-negative.
Prefix-sum + hashmap method is generally preferred for mixed integers. (Subarray Sums II)

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void subarray_sums() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll start = 0, end = -1, sum = 0, count = 0;

    while (end < n) {
        while (end < n && sum < k) {
            end += 1;
            sum += nums[end];
        }
        while (start <= end && sum > k) {
            sum -= nums[start];
            start += 1;
        }
        if (sum == k) {
            count += 1;
            sum -= nums[start];
            start += 1;
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    subarray_sums();
    return 0;
}