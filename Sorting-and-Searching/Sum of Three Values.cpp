/*
Problem Link: https://cses.fi/problemset/task/1641/

Intuition:
Brute force checking all triplets is slow (O(n^3)), especially for large n. By sorting the array, we can use a two-pointer technique to find two numbers that complement a fixed number, making the search much faster. Using pairs (value, original_index) preserves the original positions so you can report correct indices.

Approach:
- Store values with original indices where each element stores (value, index). This allows reporting the original indices after sorting.
- Sort the array by values. Makes it possible to apply the two-pointer technique efficiently.
- Loop over the first element (index i):
    - Optional: skip duplicates to avoid checking same value multiple times.
    - Two-pointer search for remaining two elements:
    - Set j = i + 1 (left pointer)
    - Set k = n - 1 (right pointer)
    - While j < k:
        - Compute sum = a[i].first + a[j].first + a[k].first
        - If sum > x, move k left (k--) to decrease sum
        - If sum < x, move j right (j++) to increase sum
        - If sum == x, print the original indices (a[i].second+1, etc.) and return
- If loop finishes without finding a triplet → print "IMPOSSIBLE"

Time Complexity: O(n^2)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sum_of_three_values() {
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a.push_back({num, i});
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].first == a[i - 1].first)
            continue;

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = a[i].first + a[j].first + a[k].first;

            if (sum > x) {
                k--;
            } else if (sum < x) {
                j++;
            } else {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1 << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sum_of_three_values();
    return 0;
}