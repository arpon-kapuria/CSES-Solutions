/*
Problem Link: https://cses.fi/problemset/task/1632/

Approach:

- Sort movies by end time so earlier-finishing movies leave more room for others.
- Maintain a multiset of members current end times and size shouldnt's cross k.
- For each movie, find the member who finishes latest but still before the movie starts (upper_bound then step back).
- If found, update their end time, else assign to a free member or skip if all are busy.
- The answer is total movies minus skipped ones.

Time Complexity: O(n log n)
Space Complexity: O(k)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void movie_festival_ii() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;

        movies.push_back({s, e});
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int skip = 0;
    multiset<int> endTime;

    for (auto m : movies) {
        auto it = endTime.upper_bound(m.first);

        if (it != endTime.begin()) {
            it--;
            endTime.erase(it);
            endTime.insert(m.second);
        } 
        else if ((int)endTime.size() < k){
            endTime.insert(m.second);
        } 
        else {
            skip++;
        }
    }

    cout << n - skip << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    movie_festival_ii();
    return 0;
}