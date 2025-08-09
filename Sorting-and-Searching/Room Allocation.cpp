/*
Problem Link: https://cses.fi/problemset/task/1164/

Approach:

- Sort all customers by their arrival time to handle bookings in order.
- Use a min-heap (priority queue) to keep track of rooms and their earliest departure times.
- For each customer:
    1. If the top room in the heap is free before the current arrival, reuse it.
    2. Otherwise, allocate a new room.
- Store each customer's room assignment based on their original input order.

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;

void room_allocation() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers;
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;

        customers.push_back({arrival, departure, i});
    }

    sort(customers.begin(), customers.end());

    int room_count = 0;
    vector<int> room_assignments(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minh;
    
    for (auto [arrival, departure, idx] : customers) {
        if (!minh.empty() && minh.top().first < arrival) {
            auto [_, room_no] = minh.top();
            minh.pop();
            minh.push({departure, room_no});
            room_assignments[idx] = room_no;
        } else {
            room_count++;
            minh.push({departure, room_count});
            room_assignments[idx] = room_count;
        }
    }

    cout << room_count << endl;
    for (auto it : room_assignments)
        cout << it << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    room_allocation();
    return 0;
}