/*
Problem Link: https://cses.fi/problemset/task/PROBLEM_ID/

Intuition:
This problem is similar to the previous one, except we cannot simply loop and alternate the numbers. Simulating the circle with a queue costs O(k) per elimination (rotating k steps), leading to O(nk). 
An order-statistics tree (GNU PBDS tree a.k.a. indexed_set) avoids rotation. It keeps the people in sorted order and augments each node with subtree sizes, so you can:
    - fetch the element by rank (find_by_order(i): i-th smallest) in O(log n),
    - delete it in O(log n).
That lets us “jump” directly to the next victim’s index using modular arithmetic on the current size, turning the process into O(n log n) while preserving the circle behavior.

Approach:
- Insert 1..n into an indexed_set<int>. The set stores them sorted and supports rank queries.
- Start with the index as k+1 (since we want to eliminate the k-th step in a 1-based cycle).
- At each step:
    - Wrap index around using modulo to keep it within the current size.
    - If modulo gives 0, set it to the last element (size).
    - Use find_by_order(index-1) to directly access the person to eliminate.
- Print and remove this person from the set.
- Increase index by k to move k steps forward for the next elimination.
- Continue until only one person remains, then print them.

Time Complexity: O(n log n)
Space Complexity: O(n)

Sources: 
- https://codeforces.com/blog/entry/5631 
- https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/ 
- https://www.nirlep.dev/adventures/cses/sorting-and-searching/josephus-problem-2

*/


#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds; 

template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void josephus_problem_ii() {
    int n, k;
    cin >> n >> k;

    indexed_set<int> children;
    for (int i = 1; i <= n; i++) {
        children.insert(i);
    }

    int index = k + 1;
    while (children.size() > 1) {
        index %= children.size();
        if (index == 0) {
            index = children.size();
        }

        auto it = children.find_by_order(index - 1);
        cout << *it << " ";
        children.erase(it);
        index += k;
    }
    cout << *children.begin() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    josephus_problem_ii();
    return 0;
}