/*
Problem Link: https://cses.fi/problemset/task/3220/

Intuition:
We need to compute the XOR of sums of all contiguous subarrays (windows) of size k. Instead of recalculating the sum of each window from scratch (O(k) per window), we maintain the current window sum and update it efficiently as the window slides.

Approach:
- Use two pointers (left, right) to represent the sliding window.
- Maintain a running sum curr_sum of the current window.
- Expand the window by adding arr[right].
- When the window reaches size k:
    - XOR the result with curr_sum.
    - Slide the window by removing arr[left] and incrementing left.
- Continue until all windows are processed.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> generateInput(ll n, ll x, ll a, ll b, ll c) {
    vector<ll> arr(n);
    arr[0] = x;
    for (ll i = 1; i < n; i++) {
        arr[i] = ((a * arr[i - 1]) + b) % c;
    }
    return arr;
}

void sliding_window_sum() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr = generateInput(n, x, a, b, c);

    ll left = 0, curr_sum = 0, sum = 0;

    for (ll right = 0; right < n; right++) {
        curr_sum += arr[right];

        if (right - left + 1 == k) {
            sum ^= curr_sum;
            curr_sum -= arr[left];
            left++;
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_sum();
    return 0;
}