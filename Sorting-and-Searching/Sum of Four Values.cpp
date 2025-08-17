/*
Problem Link: https://cses.fi/problemset/task/1642/

Intuition:
Brute force checking all is slow (O(n^4)), especially for large n. By sorting the array, we can use a two-pointer technique to find two numbers that complement a fixed number, making the search much faster. Using pairs (value, original_index) preserves the original positions so you can report correct indices. We are extending the same logic used in the "Sum of Three Values" problem to four values.

Approach:
- Store values with original indices where each element stores (value, index). This allows reporting the original indices after sorting.
- Sort the array by values. Makes it possible to apply the two-pointer technique efficiently.
- Loop over the first element (index i):
    - Optional: skip duplicates to avoid checking same value multiple times.
    - Loop over the second element (index j):
        - Optional: skip duplicates to avoid checking same value multiple times.
        - Two-pointer search for remaining two elements:
        - Set k = j + 1 (left pointer)
        - Set l = n - 1 (right pointer)
        - While l < k:
            - Compute sum = a[i].first + a[j].first + a[k].first + a[l].first
            - If sum > x, move k left (l--) to decrease sum
            - If sum < x, move j right (k++) to increase sum
            - If sum == x, print the original indices (a[i].second, etc.) and return
- If loop finishes without finding a triplet -> print "IMPOSSIBLE"

Time Complexity: O(n^3)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sum_of_four_values() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        a.push_back({val, i + 1});
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        while (i > 0 && a[i].first == a[i - 1].first) {
            i++;
        }

        for (int j = i + 1; j < n; j++) {
            while (j > i + 1 && a[j].first == a[j - 1].first) {
                j++;
            }

            int k = j + 1, l = n - 1;
            while (k < l) {
                ll sum = (ll) a[i].first + a[j].first + a[k].first + a[l].first; 
                
                if (sum > x) {
                    l--;
                } else if (sum < x) {
                    k++;
                } else {
                    cout << a[i].second << " " << a[j].second << " " << a[k].second << " " << a[l].second << "\n";
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sum_of_four_values();
    return 0;
}