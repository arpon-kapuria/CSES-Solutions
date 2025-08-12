/*
Problem Link: https://cses.fi/problemset/task/2183/

Approach:

- Intuition: By sorting the coins and iteratively tracking the maximum continuous sum we can form, we identify gaps where the next coin’s value is too large to fill in. The smallest sum we cannot create is the first such gap.
- Sort the coins and Initialize `max_sum_possible` to 0, representing the largest continuous sum achievable so far.
- Iterate over each coin and check if `coin[i]` <= `max_sum_possible`, then update `max_sum_possible` by adding `coin[i]` to it.
- If `coin[i]` > `max_sum_possible` + 1, stop and return `max_sum_possible` + 1 because there’s a gap — you cannot create the `max_sum_possible` + 1 with the coins seen so far.
- For example, with coins {1, 3}:
    - After processing 1, `max_sum_possible` = 1 (you can make sums up to 1).
    - When coin[i] = 3, since 3 > `max_sum_possible` + 1 (which is 2), you can’t create the sum 2.
    - Therefore, 2 is the smallest sum you cannot form.
- After processing all coins, return `max_sum_possible` + 1 as the smallest unreachable sum.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void missing_coin_sum() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    ll max_sum_possible = 0;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= max_sum_possible + 1) {
            max_sum_possible += coins[i];
        } else {
            break;
        }
    }
    cout << max_sum_possible + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    missing_coin_sum();
    return 0;
}