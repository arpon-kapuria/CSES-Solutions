/*
Problem Link: https://cses.fi/problemset/task/1643/

Approach:

- Use Kadane’s algorithm to find the maximum subarray sum by computing the maximum subarray sum ending at each position.
- For each element, choose between extending the previous subarray (if its sum is positive) or starting a new subarray from the current element (if the previous sum is negative).
- Update maxEnding as the maximum of maxEnding + current element and the current element itself.
- Throughout the traversal, maintain a global maximum (sum) to track the largest subarray sum found so far.

Time Complexity: O(n)
Space Complexity: O(1)

N.B: An extended version is written here to print the max sum, no of elements in the subarray and the elements in the subarray.
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void maximum_subarray_sum_extended(vector<ll>& arr, ll n) {
    int resStart = 0, resEnd = 0;
    int currStart = 0;

    int maxSum = arr[0], maxEnding = arr[0];

    for (int i = 1; i < n; i++) {
        if (maxEnding + arr[i] < arr[i]) {
            currStart = i;
            maxEnding = arr[i];
        } else {
            maxEnding += arr[i];
        }

        if (maxEnding > maxSum) {
            maxSum = maxEnding;

            resStart = currStart;
            resEnd = i;
        }
    }

    // Print maximum subarray sum
    cout << maxSum << endl;
    // Print the no of elements in the subarray with maximum sum
    cout << resEnd - resStart + 1 << endl;
    // Print subarray with maximum sum
    for (ll i = resStart; i <= resEnd; i++) {
        cout << arr[i] << endl;
    }
}

void maximum_subarray_sum(vector<ll>& arr, ll n) {
    ll maxEnding = arr[0], maxSum = arr[0];
    for (ll i = 1; i < n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        maxSum = max(maxSum, maxEnding);
    }

    cout << maxSum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    maximum_subarray_sum(arr, n);
    return 0;
}