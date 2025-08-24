/*
Problem Link: https://cses.fi/problemset/task/1077/

Intuition:
An inversion occurs when a larger element appears before a smaller element. If we naively check each window, it would take O(k²) time per window, leading to O(nk²) overall. We need an efficient way to:
    - Count inversions in the initial window
    - Update the inversion count as we slide the window (remove one element, add another)

Approach:
The approach uses coordinate compression and a Fenwick Tree to efficiently count inversions. For the initial window, we count inversions by finding larger elements to the left of each element. As we slide the window, we incrementally update by removing lost inversions and adding new ones, avoiding full recalculation.

1. Compression Purpose: Map all values of a to a dense range [1..n] so Fenwick Tree can be small.
- During compression:
    - Copy original array to temp
    - Sort the temp array and remove duplicates.
    - For each element in arr, replace it with its compressed value.
- Count inversions in the first window.

2. Fenwick Tree Purpose: Track frequency of elements and answer "how many elements ≤ x" queries efficiently.
    - Key operations:
        - Update(idx, delta): Add/remove elements
        - Query(idx): Count elements ≤ idx
    - During initialization:
        - Create Fenwick Tree of size n with all positions set to 0
        - Each index represents a compressed value
        - Value at each index represents count of that element
    - During update operation:
        - Add or remove elements by updating their frequency in the tree
        - Use delta +1 to add element, -1 to remove element
        - Tree automatically maintains prefix sum structure
    - During query operation:
        - Return count of all elements from 1 to given index
        - This tells us how many elements in current window are ≤ queried value

3. Sliding Window Inversion Processing: Count inversions in first k elements, then efficiently update count as window slides.
    - Initial window processing:
        - For each element i in first window:
            - Query Fenwick Tree to count elements ≤ current element processed so far
            - Subtract this from total elements processed (i) to get count of larger elements to the left
            - This count equals inversions formed by current element
            - Add current element to Fenwick Tree
            - Add inversion count to running total
    - Sliding window updates:
        - During element removal:
            - Query Fenwick Tree to count elements < leaving element in current window
            - Subtract this count from total inversions (these inversions are lost)
            - Remove leaving element from Fenwick Tree
        - During element addition:
            - Query Fenwick Tree to count elements ≤ new element in current window
            - Subtract from (k-1) to get count of elements > new element
            - Add this count to total inversions (new inversions formed)
            - Add new element to Fenwick Tree

Time Complexity: O(n log n)
    - Coordinate compression: O(n log n) for sorting
    - Initial window processing: O(k log n) for k Fenwick operations
    - Sliding window updates: O((n-k) log n) for (n-k) pairs of operations

Space Complexity: O(n)
    - Fenwick Tree: O(n) space
    - Compression arrays: O(n) space
    - Input array: O(n) space

N.B: This explanation is written using AI assistance.
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree {
    ll n;
    vector<ll> bit;

    FenwickTree(ll size) : n(size), bit(n + 1, 0) {}

    // Add delta to position idx
    void update(ll idx, ll delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Get sum of elements from 1 to idx (prefix sum)
    ll query(ll idx) const {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

// Compress values to range [1, unique_count] to optimize Fenwick Tree
void compression(vector<ll>& arr) {
    vector<ll> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end()); // Remove duplicates

    // Map each original value to its compressed index
    for (ll& x : arr) {
        x = ll(lower_bound(temp.begin(), temp.end(), x) - temp.begin()) + 1;
    }
}

void sliding_window_inversions() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll& x : arr) cin >> x;

    compression(arr); // Compress coordinates
    FenwickTree bit(n); // Create Fenwick Tree

    // Process initial window of size k
    ll inversions = 0;
    for (ll i = 0; i < k; i++) {
        // Count elements greater than arr[i] to the left
        // i = total elements processed, bit.query(arr[i]) = elements ≤ arr[i]
        inversions += i - bit.query(arr[i]);
        bit.update(arr[i], 1); // Add current element to tree
    }

    cout << inversions << " ";

    // Slide window from position k to n-1
    for (int i = k; i < n; i++) {
        int remove = arr[i - k]; // Element leaving the window
        int add = arr[i];        // Element entering the window

        // Remove inversions caused by the leaving element
        inversions -= bit.query(remove - 1); // Count of smaller elements
        bit.update(remove, -1); // Remove from tree

        // Add inversions caused by the entering element
        inversions += (k - 1) - bit.query(add); // Count of larger elements
        bit.update(add, 1); // Add to tree

        cout << " " << inversions;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sliding_window_inversions();
    return 0;
}