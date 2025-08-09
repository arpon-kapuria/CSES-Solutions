/*
Problem Link: https://cses.fi/problemset/task/1092/

Approach:

- Calculate the total sum of numbers from 1 to n and check if it is even; if not, print "NO" since equal partition is impossible.
- If the sum is even, set half = sum / 2 and build the first set greedily by picking numbers from n down to 1 that fit into half.
- Subtract chosen numbers from half until it reaches zero, forming the first set.
- The remaining numbers automatically form the second set.

Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printSets(ll n, ll sum) {
    ll half = sum / 2;
    vector<ll> set1, set2;

    for (ll i = n; i >= 1; i--) {
        if (i <= half) {
            set1.push_back(i);
            half -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (auto num : set1) cout << num << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (auto num : set2) cout << num << " ";
    cout << "\n";
}


void two_sets() {
	ll n;
	cin >> n;

	ll sum = (n * (n + 1))/2;
	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return;
	} else {
		cout << "YES" << endl;
		printSets(n, sum);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    two_sets();
    return 0;
}