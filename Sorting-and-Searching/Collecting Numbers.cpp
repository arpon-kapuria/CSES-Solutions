/*
Problem Link: https://cses.fi/problemset/task/2216/

Approach:

- Map each number from 1 to n to its position (index) in the given array.
- Iterate through numbers 1 to n in order and count how many times the position of the next number is less than the position of the current number, as each such case indicates the start of a new round.
- The total number of rounds is 1 plus the count of these position drops, as the first round starts with number 1.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void collecting_numbers() {
    ll n;
    cin >> n;

    unordered_map<ll, ll> map;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        map[num] = i;
    }

    ll count = 1;
    for (int i = 2; i <= n; i++) {
        if (map[i] < map[i - 1])
            count++;
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    collecting_numbers();
    return 0;
}