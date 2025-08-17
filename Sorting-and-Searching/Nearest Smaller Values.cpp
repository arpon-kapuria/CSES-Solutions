/*
Problem Link: https://cses.fi/problemset/task/1645/

Intuition:
For each element in the array, we want the index of the nearest element to its left that is smaller. A stack helps keep track of potential candidates efficiently while maintaining order. As we move from left to right, we can discard elements that are larger or equal because they cannot be the nearest smaller for future elements.

Approach:
- Initialize an empty stack to store pairs (value, index).
- Iterate through the array from left to right:
    - Pop from the stack all elements ≥ current value.
    - If stack is empty -> no smaller element to the left -> print 0.
    - Else -> top of stack is the nearest smaller element -> print its index.
- Push the current (value, index) onto the stack.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void nearest_smaller_values() {
    int n;
    cin >> n;

    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        while (!st.empty() && st.top().first >= val) {
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top().second << " ";
        }

        st.push({val, i + 1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nearest_smaller_values();
    return 0;
}