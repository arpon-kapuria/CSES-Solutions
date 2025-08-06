/*
Problem Link: https://cses.fi/problemset/task/PROBLEM_ID/

Approach:

- Use a multiset to store ticket price in a sorted manner since multiple tickets can have the same price.
- For each customer, find the first ticket price strictly greater than x, then choose the previous one (≤ x).
- Print the chosen price or -1 if none exists and remove it from the multiset to mark it as sold.

Time Complexity: O(nlogn + mlogn)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;

int get_closest_ticket(multiset<int>& ticket_price, int x) {
    auto it = ticket_price.upper_bound(x);
    // first element > x
    if (it == ticket_price.begin()) {
        return -1;
    }

    --it;
    int price = *it;
    ticket_price.erase(it); 
    return price;
}

void concert_tickets() {
    int n, m;
    cin >> n >> m;

    multiset<int> ticket_price;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ticket_price.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        
        int price = get_closest_ticket(ticket_price, x);
        cout << price << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    concert_tickets();
    return 0;
}