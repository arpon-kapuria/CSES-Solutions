/*
Problem Link: https://cses.fi/problemset/task/1623/

Approach:

- The problem is essentially a partition problem, where we split apples into two groups with minimum weight difference. 
- This can be reframed as: choose a subset of apples whose total weight is as close as possible to half of the total sum.
- We simulate this choice using recursion: at each index, we decide whether to include the current apple in the first group (currentSum) or not. This naturally explores all possible subsets.
- Once all apples are processed, the other group’s sum is total_sum - currentSum, so the weight difference is abs(total_sum - 2 * currentSum). In this way, space is saved by tracking only one sum instead of two.
- We return the smallest difference across all subsets by taking the min() of both choices at each step.

Time Complexity: O(2^n) - two choices per apple
Space Complexity: O(n) - maximum recursion depth
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMinimumDifference(int index, vector<int>& arr, ll currentSum, ll total_sum) {
    if (index == arr.size()) {
        return abs(total_sum - 2 * currentSum);
        // return abs((total_sum - currentSum) - currentSum);   // Difference between two groups sum
    }

    ll include = getMinimumDifference(index + 1, arr, currentSum + arr[index], total_sum);
    ll exclude = getMinimumDifference(index + 1, arr, currentSum, total_sum);

    return min(include, exclude);
}

void solve() {
    int n;
    cin >> n; 

    vector<int> arr(n);
    ll total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    ll difference = getMinimumDifference(0, arr, 0, total_sum);
    cout << difference << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}