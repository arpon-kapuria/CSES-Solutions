/*
Problem Link: https://cses.fi/problemset/task/1629/

Approach:

- Sort all movie intervals (start, end) in ascending order of their end times.
- Iterate through sorted intervals and Count non-overlapping intervals.
- Keep track of the end time of the last selected movie.

Time Complexity: O(nlogn)
Space Complexity: O(n) [Input storage]
*/


#include <bits/stdc++.h>
using namespace std;

void movie_festival() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({start, end});
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0, endTime = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= endTime) {
            endTime = movies[i].second;
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    movie_festival();
    return 0;
}