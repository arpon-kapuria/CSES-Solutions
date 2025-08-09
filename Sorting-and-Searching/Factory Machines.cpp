/*
Problem Link: https://cses.fi/problemset/task/1620/

Approach:

- Use binary search on the answer (time) to find the minimum time required to produce k products.
- For a given time mid, compute how many products can be made by all machines using mid / product making time for each machine.
- If the total products ≥ t, it’s a valid solution. Then try smaller time, else, increase time.
- Continue until the smallest possible valid time is found.

Time Complexity: O(n * log(max_time)), where max_time can be upto 1e18
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool enough_time(vector<int>& times, ll time_limit, ll target_products) {
    ll total = 0;
    for (auto t : times) {
        total += time_limit / t;
        if (total >= target_products) return true; 
    }
    return false;
}

void factory_machines() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ll low = 1, high = 1e18, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (enough_time(times, mid, k)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factory_machines();
    return 0;
}