/*
Problem Link: https://cses.fi/problemset/task/1073/

Approach:

- Intuition: A cube can go on top of a tower only if the tower's top cube is strictly larger than the new cube. Among all valid towers, it’s best to pick the one whose top is the smallest possible that is still larger than the new cube.
- Keep a sorted structure (multiset) of current tower tops.
- For each incoming cube:
    - Find the smallest tower top that is greater than the cube.
    - If found -> replace that tower’s top with the cube size.
    - If not found -> start a new tower (insert the cube).
- The size of the multiset at the end = number of towers.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void towers() {
    int n;
    cin >> n;
    
    multiset<int> towers;
    for (int i = 0; i < n; i++) {
        int cube_size;
        cin >> cube_size;

        auto it = towers.upper_bound(cube_size);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(cube_size);
    }

    cout << towers.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    towers();
    return 0;
}