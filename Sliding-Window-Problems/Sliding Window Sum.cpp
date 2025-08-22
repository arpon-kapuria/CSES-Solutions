/*
Problem Link: https://cses.fi/problemset/task/3220/

Intuition:


Approach:
- 

Time Complexity: 
Space Complexity: 
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

void sliding_window_sum() {
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr = generateInput(n, x, a, b, c);

    ll left = 0, curr_sum = 0, sum = 0;

    for (ll right = 0; right < n; right++) {
        curr_sum += arr[right];

        if (right - left + 1 == k) {
            sum ^= curr_sum;
            curr_sum -= arr[left];
            left++;
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_sum();
    return 0;
}