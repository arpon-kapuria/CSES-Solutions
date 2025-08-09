/*
Problem Link: https://cses.fi/problemset/task/3420/

Approach:

- Use two pointers (left and right) to represent a sliding window of distinct elements in the array.
- Track the last occurrence of each element with a map; when a duplicate is encountered, move left forward to exclude the previous occurrence.
- At each step, count all distinct subarrays ending at right by adding right - left + 1 to the total count.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void distinct_value_subarrays() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    unordered_map<ll, ll> map;

    ll left = 0, count = 0;

    for (ll right = 0; right < n; right++) {
        cin >> arr[right];

        if (map.find(arr[right]) != map.end()) {
            left = max(left, map[arr[right]] + 1);
        } 

        count += right - left + 1;
        map[arr[right]] = right;
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    distinct_value_subarrays();
    return 0;
}