/*
Problem Link: https://cses.fi/problemset/task/2162/

Intuition:
The idea is that the queue models people standing in a circle: each time, one person is spared (moved to the back) and the next is eliminated (printed). Repeating this alternation directly simulates the elimination order without needing complex math or indexing.

Approach:
- Declare a Queue q and push all the children into the queue.
- Also declare a flag to decide whether to remove the current child or not (Initially set to false).
- Now, one by one pop the element at the front of the queue.
    - If the element is supposed to be removed from the queue, we print the element.
    - Otherwise, we push the element back to the queue.
- All the elements will be printed in the order as they are deleted.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void josephus_problem_i() {
    ll n;
    cin >> n;

    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        q.push(i);
    }

    bool flag = false;
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (flag) {
            cout << num << " ";
        } else {
            q.push(num);
        }

        flag = !flag;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    josephus_problem_i();
    return 0;
}