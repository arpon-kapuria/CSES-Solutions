/*
Problem Link: https://cses.fi/problemset/task/2168/

Intuition:
A range [a, b] contains another range [c, d] if it starts earlier (or same) and ends later (or same). After sorting ranges by start ascending and end descending, longer ranges come first. This allows a linear sweep to detect containment relationships efficiently without checking all pairs. Tracking the maximum right endpoint (for “is contained”) and minimum right endpoint (for “contains”) lets us determine containment in one pass per direction.

Approach:
- Store each range along with its original index.
- Sort ranges by:
    - Start ascending.
    - End descending (for ties).
- Left -> Right sweep to mark ranges that are contained:
    - Maintain maxRight seen so far.
    - If current range ends ≤ maxRight, it is contained by some previous range.
- Right -> Left sweep to mark ranges that contain others:
    - Maintain minRight seen so far.
    - If current range ends ≥ minRight, it contains some later range.
- Print results in the original input order using stored indices.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i}; 
    }

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) 
            return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    int maxRight = INT_MIN;
    vector<int> is_contained(n, 0);
    for (auto &[l, r, idx] : ranges) {
        if (r <= maxRight) 
            is_contained[idx] = 1;
        maxRight = max(maxRight, r);
    }

    int minRight = INT_MAX;
    vector<int> contains(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        auto &[l, r, idx] = ranges[i];
        if (r >= minRight) 
            contains[idx] = 1;
        minRight = min(minRight, r);
    }

    for (auto x : contains) cout << x << " "; 
    cout << "\n";
    for (auto x : is_contained) cout << x << " "; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}