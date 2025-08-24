/*
Problem Link: https://cses.fi/problemset/task/PROBLEM_ID/

Intuition:
To minimize the total cost of making all elements in a window equal, we want to choose the median as the target value because the sum of absolute differences is minimized at the median. To efficiently compute this for every sliding window, we maintain two multisets: low for the smaller half (≤ median) and high for the larger half (> median). This allows us to track the median and sums incrementally as the window slides, avoiding recomputation over all k elements each time.

N.B: This is an extension of the "Sliding Window Median" problem. Here, we also maintain the sums of the two halves to compute the cost efficiently.

Approach:
- Maintain two multisets:
    - low -> stores the smaller half of elements (max at end)
    - high -> stores the larger half of elements (min at beginning)
    - Also maintain lowSum and highSum for the sums of these sets.
- For each incoming element in the sliding window:
    - Remove the outgoing element from its respective set and update the sum.
    - Insert the new element into the correct set based on current sizes to maintain balance and update the sum.
- Rebalance sets if the largest in low is greater than the smallest in high (swap them) and adjust the sums accordingly.
- Once the window is formed (i ≥ k-1), calculate the total cost as:
        cost = (median * size(low) - lowSum) + (highSum - median * size(high)), where median = max(low)
- Slide the window by repeating the above steps for each new element.
- Print the cost for each window.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    multiset<ll> low, high;
    ll lowSum = 0, highSum = 0;

    for (ll i = 0; i < n; i++) {
        if (i >= k) {
            if (low.find(arr[i - k]) != low.end()) {
                lowSum -= arr[i - k];
                low.erase(low.find(arr[i - k]));
            } else {
                highSum -= arr[i - k];
                high.erase(high.find(arr[i - k]));
            }
        }

        ll size1 = low.size(), size2 = high.size();
        if (size1 <= size2) {
            low.insert(arr[i]);
            lowSum += arr[i];
        } else {
            high.insert(arr[i]);
            highSum += arr[i];
        }

        size1 = low.size(), size2 = high.size();
        if (size1 > 0 && size2 > 0) {
            auto lowMax = low.rbegin();
            auto highMin = high.begin();

            if (*lowMax > *highMin) {
                lowSum = lowSum - *lowMax + *highMin;
                highSum = highSum - *highMin + *lowMax;
                low.insert(*highMin);
                high.insert(*lowMax);
                low.erase(low.find(*lowMax));
                high.erase(high.find(*highMin));
            }
        }

        if (i >= k - 1) {
            ll median = *low.rbegin();
            cout << (size1 * median - lowSum) + (highSum - size2 * median) << " ";
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}