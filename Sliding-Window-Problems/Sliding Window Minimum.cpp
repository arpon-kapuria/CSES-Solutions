/*
Problem Link: https://cses.fi/problemset/task/3221/

Intuition:
We need the minimum of each sliding window of size k. A naive solution checks all k elements for every window → O(n*k). Too slow. Instead, we maintain a deque of indices such that: It always stores indices of useful elements (deque contains nums in asceding order). The front of deque is always the minimum for the current window. This gives us an O(n) solution.

Approach:
- Iterate through the array, process each element nums[i].
- Pop back from deque while nums[deque.back()] > arr[i] -> remove greater elements (deque contains nums in asceding order).
- Push current index i into deque.
- Pop front if deque.front() is out of the current window (index ≤ i-k).
- Once we reach at least the first k elements, record nums[deque.front()] as the window max.
- Finally, take the xor of all recorded minimums.

Time Complexity: O(n)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> generateInput(ll n, ll x, ll a, ll b, ll c) {
    vector<ll> arr(n);
    arr[0] = x;
    for (ll i = 1; i < n; i++) {
        arr[i] = ((a * arr[i - 1]) + b) % c;
    }
    return arr;
}

void sliding_window_minimum() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr = generateInput(n, x, a, b, c);

    ll result = 0;
    deque<ll> dq;

    for (ll i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] > arr[i]) {
            dq.pop_back();
        }

        dq.push_back(arr[i]);
        if (i >= k - 1) {
            result ^= dq.front();
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_minimum();
    return 0;
}