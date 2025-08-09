/*
Problem Link: https://cses.fi/problemset/task/1619/

Approach:

- Store each customer's arrival and departure as pairs in an array, where:
    - arrivals are marked with +1
    - departures are marked with -1
- sorts all events by time, ensuring that departures are processed before arrivals if they occur at the same time.
- Finally, iterate through the sorted events, maintaining a running count of current customers and track the maximum number present at any time.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

void restaurant_customers() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;

        events.push_back({arrival, +1});
        events.push_back({departure, -1});
    }

    sort(events.begin(), events.end());

    int max_customers = 0, current_customers = 0;
    for (auto [time, type] : events) {
        current_customers += type;
        max_customers = max(current_customers, max_customers);
    }
    
    cout << max_customers << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    restaurant_customers();
    return 0;
}