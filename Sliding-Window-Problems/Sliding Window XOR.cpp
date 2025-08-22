/*
Problem Link: https://cses.fi/problemset/task/3426/

Intuition:
We need to compute the XOR of xor of all contiguous subarrays (windows) of size k. Instead of recalculating the xor of each window from scratch (O(k) per window), we maintain the current window xor and update it efficiently as the window slides.

Approach:
- Use two pointers (left, right) to represent the sliding window.
- Maintain a running xor `curr_xor` of the current window.
- Expand the window by adding arr[right].
- When the window reaches size k:
    - XOR the result with curr_sum.
    - Slide the window by removing arr[left]. We remove the left element by xoring it again with curr_xor (since x ^ x = 0). 
    - Then increment left.
- Continue until all windows are processed.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sliding_window_xor() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    ll left = 0, curr_xor = 0, result = 0;

    for (ll right = 0; right < n; right++) {
        if (right > 0) {
            arr[right] = ((a * arr[right - 1]) + b) % c;
        }

        curr_xor ^= arr[right];

        if (right - left + 1 == k) {
            result ^= curr_xor;
            curr_xor ^= arr[left];
            left++;
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_xor();
    return 0;
}