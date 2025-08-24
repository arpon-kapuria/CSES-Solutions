/*
Problem Link: https://cses.fi/problemset/task/1076/


=== USING ONE MULTISET  ===

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


=== USING TWO MULTISET  ===

Intuition:
Another approach is using a two-heap approach (or two multisets here), which allows us to maintain the lower half and upper half of the current window. The median is always the maximum of the lower half if the window size is odd or even (as asked, lower median for even k).

Approach:
- Maintain two multisets:
    - low -> stores the smaller half of elements (max at end)
    - high -> stores the larger half of elements (min at beginning)
- For each incoming element in the sliding window:
    - Remove the outgoing element from its respective set.
    - Insert the new element into the correct set (low or high) based on current sizes to maintain balance.
- Rebalance sets if the largest in low is greater than the smallest in high (swap them).
- Once the window is formed (i ≥ k-1), return:
        median = max(low) / low.rbegin().
- Slide the window by repeating the above steps for each new element.
- Print the median for each window.

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

void sliding_window_median2() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    multiset<ll> low, high;

    for (int i = 0; i < n; i++) {
        if  (i >= k) {
            if (low.find(arr[i - k]) != low.end()) {
                low.erase(low.find(arr[i - k]));
            } else {
                high.erase(high.find(arr[i - k]));
            }
        }

        ll size1 = low.size(), size2 = high.size();
        if (size1 <= size2) {
            low.insert(arr[i]);
        } else {
            high.insert(arr[i]);
        }

        size1 = low.size(), size2 = high.size();
        if (size1 > 0 && size2 > 0) {
            auto lowMax = low.rbegin();
            auto highMin = high.begin();

            if (*lowMax > *highMin) {
                low.insert(*highMin);
                high.insert(*lowMax);

                low.erase(low.find(*lowMax));
                high.erase(high.find(*highMin));
            }
        }

        if (i >= k - 1) {
            cout << *low.rbegin() << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_median2();
    return 0;
}