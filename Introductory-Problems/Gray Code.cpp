/*
Problem Link: https://cses.fi/problemset/task/2205/

Approach:

- Intuition: Gray code works by ensuring each consecutive binary string differs in exactly one bit. We can achieve this by reflecting the previous sequence and flipping the first bit in the reflection.
- Start with the smallest case, n = 1 -> {"0", "1"} which already satisfies the property.
- For each higher n, take the (n-1) bit Gray code and prefix "0" to all codes in order.
- Then take the same (n-1) bit Gray code in reverse order and prefix "1" to ensure only one bit changes between halves.
- Repeat this recursively until we build up to n bits, giving 2^n valid codes.

Time Complexity: O(2^n)
Space Complexity: O(n) - recursion depth, O(n * 2^n) - storing all code
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> gray_code(int n) {
    if (n == 1) {
        return {"0", "1"};
    }

    vector<string> prev = gray_code(n - 1);
    vector<string> results;

    for (int i = 0; i < prev.size(); i++) {
        results.push_back("0" + prev[i]);
    }

    for (int i = prev.size() - 1; i >= 0; i--) {
        results.push_back("1" + prev[i]);
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> results = gray_code(n);
    for (auto it : results) {
        cout << it << endl;
    }

    return 0;
}