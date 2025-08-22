/*
Problem Link: https://cses.fi/problemset/task/3222/

Intuition:
We want to count distinct values in every sliding window of size k. Using a frequency map lets us keep track of how many times each element appears inside the current window. As we slide, we add the new element and remove the leftmost one efficiently. So, the map size should give us the count of distinct elements for each window.

Approach:
- Use a frequency map to track occurrences of elements in the current window.
- Expand the window by adding arr[right] and increasing its frequency.
- Once the window reaches size k, the number of distinct values is simply freq_map.size().
- Before sliding the window, decrease the frequency of arr[left].
- If its frequency becomes zero, erase it from the map to keep only active elements.
- Slide the window by incrementing left.
- Repeat until the end of the array.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sliding_window_distinct_values() {
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<ll, ll> freq_map;
    ll left = 0;

    for (ll right = 0; right < n; right++) {
        freq_map[arr[right]]++;

        if (right - left + 1 == k) {
            cout << freq_map.size() << " ";

            freq_map[arr[left]]--;
            if (freq_map[arr[left]] == 0) {
                freq_map.erase(arr[left]);
            }
            left++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_distinct_values();
    return 0;
}