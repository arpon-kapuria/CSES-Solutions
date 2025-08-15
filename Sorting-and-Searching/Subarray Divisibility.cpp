/*
Problem Link: https://cses.fi/problemset/task/1662/

Intuition:
When you compute the prefix sum of an array, the sum of a subarray from index i+1 to j can be represented as prefixSum[j] - prefixSum[i]. If this difference is divisible by n, then (prefixSum[j] - prefixSum[i]) % n == 0. Rearranging, we get prefixSum[j] % n == prefixSum[i] % n. This means that any two prefix sums with the same remainder modulo n define a subarray whose sum is divisible by n.

Approach:
- Compute the prefix sum while iterating through the array.
- Calculate the modulo n of the prefix sum, adjusted to always be non-negative.
- Maintain a map of counts of each modulo encountered so far.
- For each new prefix sum modulo, add the count of that modulo from the map to the answer. This is because each previous occurrence of the same modulo forms a subarray with a sum divisible by n.
- Increment the count of the current modulo in the map and continue.

Time Complexity: O(nlogn) if using map, O(n) if using unordered_map
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void subarray_divisibility() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll count = 0, prefixSum = 0;
    map<ll, ll> modCount = {{0, 1}};

    for (ll i = 0; i < n; i++) {
        prefixSum += arr[i];
        ll mod = ((prefixSum % n) + n) % n;
        count += modCount[mod];
        modCount[mod]++;

    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    subarray_divisibility();
    return 0;
}