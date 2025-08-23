/*
Problem Link: https://cses.fi/problemset/task/3224/

Intuition:
The mode of a sliding window requires tracking frequencies efficiently as elements enter and leave the window. A simple frequency map tells us counts, but finding the highest frequency with ties (choose smallest value) is costly. By storing pairs { -frequency, value } in a multiset, we can always get the correct mode in O(1) from the beginning of the multiset. Negative frequency ensures that higher frequencies come first and ties are naturally broken by the smallest value.

Approach:
- Use a frequency map to store counts of each element in the current window.
- Use a multiset of { -frequency, value } to keep elements sorted by highest frequency and then by smallest value.
- When adding an element:
    - Remove its old pair from the multiset.
    - Update its frequency.
    - Insert the new pair with updated frequency.
- When removing an element:
    - Remove its current pair from the multiset.
    - Decrease frequency or erase completely if count becomes 0.
    - Reinsert with updated frequency if still present.
- After processing the first window, slide the window by removing the leftmost element and adding the new one at each step.
- The mode is always ms.begin()->second.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sliding_window_mode() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, ll> freq;
    multiset<pair<ll, ll>> ms;

    auto add = [&](ll x) {
        if (freq[x] > 0) {
            ms.erase(ms.find({-freq[x], x}));
        }
        freq[x]++;
        ms.insert({-freq[x], x});
    };

    auto remove = [&](ll x) {
        ms.erase(ms.find({-freq[x], x}));
        if (freq[x] == 1) {
            freq.erase(x);
        }
        else {
            freq[x]--;
            ms.insert({-freq[x], x});
        }
    };

    for (ll i = 0; i < k; i++) {
        add(a[i]);
    }
    cout << ms.begin()->second;

    for (ll i = k; i < n; i++) {
        remove(a[i - k]);
        add(a[i]);
        cout << " " << ms.begin()->second;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_mode();
    return 0;
}