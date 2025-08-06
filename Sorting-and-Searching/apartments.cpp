/*
Problem Link: https://cses.fi/problemset/task/1084/

Approach:

- Sort both the applicants' desired sizes and the apartment sizes array.
- Use two points to check if the current apartment is a valid match for the current applicant.
  Idea should be :
    1. If the apartment is too small, move to the next apartment.
    2. If it's too big, move to the next applicant.
    3. If it's a match (within k range), count it and move both pointers.
    4. Loop runs as long as i and j haven’t gone past the end of either the applicant list or the apartment list.

Time complexity: O(nlong + mlogm)
*/


#include <bits/stdc++.h>
using namespace std;

void apartments() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired_size(n), apartment_size(m);

    for (int i = 0; i < n; i++) {
        cin >> desired_size[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartment_size[i];
    }

    sort(desired_size.begin(), desired_size.end());
    sort(apartment_size.begin(), apartment_size.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (apartment_size[j] >= desired_size[i] - k && apartment_size[j] <= desired_size[i] + k) {
            count++;
            i++;
            j++;
        } 
        else if (apartment_size[j] < desired_size[i] - k) {
            j++;
        } else {
            i++;
        }
    }

    cout << count << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    apartments();
    return 0;
}