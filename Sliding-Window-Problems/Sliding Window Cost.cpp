/*
Problem Link: https://cses.fi/problemset/task/PROBLEM_ID/

Intuition:


Approach:
- 

Time Complexity: 
Space Complexity: 
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    multiset<ll> low, high;
    ll lowSum = 0, highSum = 0;

    for (ll i = 0; i < n; i++) {
        if (i >= k) {
            if (low.find(arr[i - k]) != low.end()) {
                lowSum -= arr[i - k];
                low.erase(low.find(arr[i - k]));
            } else {
                highSum -= arr[i - k];
                high.erase(high.find(arr[i - k]));
            }
        }

        ll size1 = low.size(), size2 = high.size();
        if (size1 <= size2) {
            low.insert(arr[i]);
            lowSum += arr[i];
        } else {
            high.insert(arr[i]);
            highSum += arr[i];
        }

        size1 = low.size(), size2 = high.size();
        if (size1 > 0 && size2 > 0) {
            auto lowMax = low.rbegin();
            auto highMin = high.begin();

            if (*lowMax > *highMin) {
                lowSum = lowSum - *lowMax + *highMin;
                highSum = highSum - *highMin + *lowMax;
                low.insert(*highMin);
                high.insert(*lowMax);
                low.erase(low.find(*lowMax));
                high.erase(high.find(*highMin));
            }
        }

        if (i >= k - 1) {
            ll median = *low.rbegin();
            cout << (size1 * median - lowSum) + (highSum - size2 * median) << " ";
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}