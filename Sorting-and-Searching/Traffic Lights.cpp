/*
Problem Link: https://cses.fi/problemset/task/1163/

Approach:

- Start with a street of length x with traffic lights only at the ends (0 and x).
- For each new traffic light at position p, find the segment it splits by identifying the nearest lights to the left and right.
- Remove the old segment length from a multiset and insert the two new segment lengths.
- The longest passage without traffic lights is always the maximum element in the multiset after each insertion. 

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void traffic_lights() {
    int x, n;
    cin >> x >> n;
    
    set<int> lights = {0, x};
    multiset<int> lengths = {x};

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto right = lights.upper_bound(p);
        auto left = prev(right);

        lengths.erase(lengths.find(*right - *left));
        lengths.insert(p - *left);
        lengths.insert(*right - p);

        lights.insert(p);

        cout << *lengths.rbegin() << endl; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    traffic_lights();
    return 0;
}