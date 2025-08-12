/*
Problem Link: https://cses.fi/problemset/task/1074/

Approach:

- Intuition: To minimize total adjustment cost, all sticks should be made equal to the median length.
- If we sort the stick lengths, pick the median, and sum absolute differences from it, we will get minimum cost.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void stick_lengths() {
    int n;
    cin >> n; 
    
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    int median = sticks[n / 2];

    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(median - sticks[i]);
    }

    cout << cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stick_lengths();
    return 0;
}