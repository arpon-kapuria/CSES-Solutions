/*
Problem Link: https://cses.fi/problemset/task/2217/

Approach:

- Maintain two arrays :
    1. nums[i] - original array
    2. pos[i] - stores the current position (index) of the value from the nums array, for a fast lookup of a value's position.
- Initially, count total_rounds by finding how many "breaks" exist in the sequence - a break occurs when pos[i] < pos[i-1], meaning the natural increasing order is disrupted and an additional round is needed.
- When swapping two elements at position a and b, the only affected breaks are those involving the swapped values and their neighbors (i.e., x - 1, x + 1, y - 1, y + 1, where, x = val[a], y = val[b]). To cover all possibilities, we gather these affected values (x, x + 1, y, y + 1) into a unique set.
- Before swapping, subtract from total_rounds the breaks caused by these affected values by checking if pos[val] < pos[val-1] for each affected val. 
- After swapping and updating positions in num and pos, add back the breaks caused by the same affected values. This approach avoids recomputing breaks for the whole array.

Time Complexity: O(n + m)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getTotalRounds(int n, vector<int>& pos) {
    int rounds = 1;

    for (int i = 2; i <= n; i++) {
        if (pos[i-1] > pos[i]) {
            rounds++;
        }
    }
    return rounds;
}

int checkBreak(int num, vector<int>& pos) {
    if (num <= 1) 
        return 0;
    return (pos[num - 1] > pos[num]) ? 1 : 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int total_rounds = getTotalRounds(n, pos);

    while (m--) {
        int a, b;
        cin >> a >> b;

        int x = nums[a], y = nums[b];
        unordered_set<int> affected = {x, x + 1, y, y + 1};

        for (auto val : affected) {
            if (val >= 1 && val <= n) {
                total_rounds -= checkBreak(val, pos);
            }
        }

        swap(nums[a], nums[b]);
        pos[x] = b;
        pos[y] = a;

        for (auto val : affected) {
            if (val >= 1 && val <= n) {
                total_rounds += checkBreak(val, pos);
            }
        }

        cout << total_rounds << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}