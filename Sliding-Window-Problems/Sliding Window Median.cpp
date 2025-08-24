/*
Problem Link: https://cses.fi/problemset/task/1076/

Intuition:
We need to maintain a sliding window of size k and quickly compute the median as the window moves. Sorting the window every time would be too slow. Instead, we can use a balanced multiset (like a BST) to keep numbers ordered and adjust a pointer (mid) that tracks the median efficiently as we slide.

Approach:
- Use a multiset to maintain the current window in sorted order.
- Keep an iterator mid pointing to the middle of the window.
- For each window, record the median using mid (it will always point to the lower median for even k).
- For each new element added:
    - Insert the new element, adjust mid if needed (if new element <= mid, mid pointer decreases).
- For each outgoing element (from the left of the window):
    - Before removing it from the multiset, adjust mid (if `to be deleted` element <= mid, mid pointer increases).
- Lower bound is used to remove elements to handle duplicates correctly.
- Repeat until all windows are processed.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sliding_window_median() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<ll> window(arr.begin(), arr.begin() + k);
    auto mid = next(begin(window), (k - 1) / 2);

    for (ll i = k; ; i++) {
        cout << *mid << " ";

        if (i == n) break;

        window.insert(arr[i]);

        if (arr[i] < *mid) {
            mid--;
        }

        if (arr[i - k] <= *mid) {
            mid++;
        }

        window.erase(window.lower_bound(arr[i - k]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_median();
    return 0;
}