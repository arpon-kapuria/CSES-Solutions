/*
Problem Link: https://cses.fi/problemset/task/1754/

Approach:

- Focus on these conditions :
    - Each move removes exactly 3 coins in total, so (a + b) must be divisible by 3.
    - In any valid move, the larger pile can’t be more than double the smaller pile. Otherwise, we’ll run out of coins in the smaller pile first.
- If both conditions hold, it’s possible to empty both piles. Otherwise, it’s impossible.

Time Complexity: O(1)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void coin_piles() {
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        
        if ((a + b) % 3 != 0) cout << "NO" << endl;
        else if (max(a, b) > 2 * min(a, b)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    coin_piles();
    return 0;
}