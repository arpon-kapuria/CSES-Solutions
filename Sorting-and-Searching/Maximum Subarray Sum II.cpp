/*
Problem Link: https://cses.fi/problemset/task/1644/

Approach:

- We want the maximum subarray sum with length in [a, b]. If a subarray ends at index i, its start index j must satisfy :
    a ≤ (i - j) ≤ b, i.e., j ∈ [i-b, i-a].
- Using prefix sums, the sum from j to i is prefix_sum[i] - prefix_sum[j]. 
- For a fixed i, to maximize this difference/sum, we need the smallest possible prefix_sum[j] in that range.
- The deque is used to efficiently maintain candidates for j in the range [i-b, i-a] in increasing order of prefix sum value.
    - The front of the deque always holds the index with the smallest prefix sum in the current valid range.
    - We pop from the front when an index goes out of [i-b, i-a] / below [i - b] i.e., i = 10, a = 5, b = 7 | value of j can be between [3, 5].
    - We pop from the back to maintain increasing order when adding a new candidate.
- This ensures we can find the optimal j for each i in O(1) while moving i forward, making the overall complexity O(n).


Time Complexity: O(n) — each index is pushed and popped from the deque at most once.
Space Complexity: O(n) — for storing the prefix sum array and deque.

N.B: We can't use Kadane's Algorithm, because Kadane's algorithm can't shrink or expand array size.
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void maximum_subarray_sum_with_range() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }

    ll maxSum = LLONG_MIN;
    deque<ll> dq;   // will store indices of prefix sums

    for (ll i = a; i <= n; i++) {
        // Remove indices out of window [i-b, i-a]
        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }
        
        // Add prefix index i - a to deque maintaining increasing prefix sums
        int newIndex = i - a;
        while (!dq.empty() && prefix_sum[dq.back()] >= prefix_sum[newIndex]) {
            dq.pop_back();
        }
        dq.push_back(newIndex);
        
        // Now prefix[dq.front()] is minimum prefix sum in range [i-b, i-a]
        maxSum = max(maxSum, prefix_sum[i] - prefix_sum[dq.front()]);
    }

    cout << maxSum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    maximum_subarray_sum_with_range();
    return 0;
}