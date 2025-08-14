/*
Problem Link: https://cses.fi/problemset/task/1085/

Intuition: 
We want to split the array into k subarrays such that the largest subarray sum is minimized. By guessing a candidate maximum sum (mid), we can greedily check if the array can be split without exceeding it.

Approach:
- Use binary search between max(array) (smallest possible max sum) and sum(array) (largest possible max sum).
- For each candidate mid, iterate through the array and greedily form subarrays, starting a new subarray whenever the running sum exceeds mid.
- Count the number of subarrays formed. If ≤ k, the candidate is feasible, so try a smaller mid. Otherwise, increase mid.
- Repeat until binary search converges to the minimum feasible maximum sum.

Time Complexity: O(n * log(sum(array)))
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool canSplit(vector<ll>& nums, ll maxSum, ll k) {
    ll currSum = 0;
    ll chunks = 1;

    for (auto it : nums) {
        if (currSum + it > maxSum) {
            chunks++;
            currSum = it;
        } else {
            currSum += it;
        }
    }

    return chunks <= k;
}

void array_division() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll low = *max_element(nums.begin(), nums.end());
    ll high = accumulate(nums.begin(), nums.end(), 0LL);
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canSplit(nums, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array_division();
    return 0;
}