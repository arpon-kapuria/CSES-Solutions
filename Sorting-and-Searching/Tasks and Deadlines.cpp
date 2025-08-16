/*
Problem Link: https://cses.fi/problemset/task/1630/

Intuition:
It's a classic scheduling optimization problem. The sum of finishing times is minimized if you always complete shorter tasks first (a.k.a. Shortest Processing Time First).
    - Every task’s reward = deadline – finishing time.
    - Total reward = sum(deadlines) – sum(finishing times).
    - The sum of deadlines is fixed (doesn’t depend on order).
    - So maximizing reward = minimizing the sum of finishing times.

Approach:
- Sort all tasks by duration a ascending.
- Process them in that order.
- Compute finishing times and rewards.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void tasks_and_deadlines() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), [](const pair<ll, ll>& a, const pair<ll, ll>&b){
        return a.first < b.first;
    });

    ll finishing_time = 0;
    ll reward = 0;
    for (auto task : tasks) {
        finishing_time += task.first;
        reward += task.second - finishing_time;
    }

    cout << reward << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tasks_and_deadlines();
    return 0;
}