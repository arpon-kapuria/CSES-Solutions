/*
Problem Link: https://cses.fi/problemset/task/1631/

Intuition:
When two readers share the workload optimally, the minimum total time depends on balancing the largest book against the rest. If the largest book is smaller than or equal to the sum of all other books, the readers can “split” the workload such that neither waits too long, and the total time is simply the sum of all books. If the largest book is bigger than the sum of the others, the second reader will finish earlier and wait, so the total time is dominated by twice the largest book.

Approach:
- Sort the books to identify the largest book.
- Compute the sum of all remaining (smaller) books.
- If the largest book’s time ≤ sum of smaller books, total time = sum of all books.
- Otherwise, total time = 2 × largest book (since one reader will have to wait).

Time Complexity: O(n log n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void reading_books() {
    int n;
    cin >> n;
    vector<ll> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i];
    }

    sort(books.begin(), books.end());
    ll largest = books[n - 1];
    ll sumOfSmaller = accumulate(books.begin(), books.end() - 1, 0LL);

    if (largest <= sumOfSmaller) {
        cout << largest + sumOfSmaller << '\n';
    } else {
        cout << 2 * largest << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    reading_books();
    return 0;
}

