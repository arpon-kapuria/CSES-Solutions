/*
Problem Link: https://cses.fi/problemset/task/PROBLEM_ID/

Approach:

- Sort the weights array.
- Use two points to check if the heaviest (right) weight and lightest (left) weight < weight_limit (x).
  Idea should be how we fill a gondola (Either one / two child) :
    1. If the sum <= x, increase count and move both left and right pointers. [Two child]
    2. If the sum > x, increase count and move only right. [Once child]
    3. Loop runs as long as left < right.
    4. In case of odd numbers, if two pointers come to the same position then increase the count for that remaining child.


Time Complexity: O(nlogn)
*/


#include <bits/stdc++.h>
using namespace std;

void ferris_wheel() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int left = 0, right = n - 1, count = 0;
    while (left < right) {
        if (weights[left] + weights[right] <= x) {
            left++;
            right--;
        } else {
            right--;
        }
        count++;
    }

    if (left == right)
        count++;
    
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ferris_wheel();
    return 0;
}