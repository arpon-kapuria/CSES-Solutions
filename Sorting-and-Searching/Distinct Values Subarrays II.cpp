/*
Problem Link: https://cses.fi/problemset/task/2428/

Intuition:
This problem is an extension of the classic “all distinct subarrays” problem. In the standard problem, we count subarrays where every element is distinct (k = number of distinct elements allowed = window size). Here, we generalize it to at most k distinct elements, so we use a sliding window and a frequency map to dynamically maintain the valid window. The idea of counting all subarrays ending at right by right - left + 1 naturally extends from the all-distinct approach.

Approach:
- Use two pointers left and right to define the current window and an unordered_map freq to track the frequency of elements in the window.
- Iterate right from 0 to n−1, adding nums[right] to the frequency map.
- While the window contains more than k distinct elements, shrink it from the left by decrementing freq[nums[left]] and erasing it if its count becomes 0, then increment left.
- After adjusting the window, all subarrays ending at right and starting from left to right are valid. Add right - left + 1 to the total count.
- Continue until the end of the array and print the total count.

Time Complexity: O(n) - each element is added and removed at most once
Space Complexity: O(k) — the map stores at most k distinct elements
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void distinct_values_subarrays_ii() {
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    unordered_map<ll, ll> freq;
    ll left = 0, count = 0;

    for (ll right = 0; right < n; ++right) {
        cin >> nums[right];

        freq[nums[right]]++;

        while ((ll)freq.size() > k && left < n) {
            freq[nums[left]]--;
            left++;

            if (freq[nums[left - 1]] == 0) {
                freq.erase(nums[left - 1]);
            }
        }

        count += right - left + 1;
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    distinct_values_subarrays_ii();
    return 0;
}