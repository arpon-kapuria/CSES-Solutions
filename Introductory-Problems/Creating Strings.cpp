/*
Problem Link: https://cses.fi/problemset/task/1622/

Approach:

- This is a classic backtracking problem focused on generating all unique permutations of a string.
- Start by sorting the input string to ensure the output permutations are produced in alphabetical order.
- Maintain a `used` boolean array to keep track of which characters have been included in the current permutation path.
- To avoid duplicates, skip recursive calls where the current character is the same as the previous character and the previous character has not yet been used in the current recursion path.
- Once the current permutation reaches the same length as the input string, add it to the `results` list.
- After generating all permutations, print the total count followed by the sorted unique permutations.

Time Complexity: O(n! * n) where n! = the number of unique permutations and n = length of string
Space Complexity: O(n) - auxilary space, O(n! * n) - to store results
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void backtrack(string s, vector<bool>& used, string &path, vector<string>& results) {
    if (path.size() == s.size()) {
        results.push_back(path);
        return;
    }

    for (size_t i = 0; i < s.size(); i++) {
        if (used[i]) continue;

        if (i > 0 && s[i - 1] == s[i] && !used[i - 1]) continue;

        used[i] = true;
        path.push_back(s[i]);

        backtrack(s, used, path, results);

        used[i] = false;
        path.pop_back();
    }
}

void creating_strings() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector<bool> used(s.size(), false);
    string path;
    vector<string> results;

    backtrack(s, used, path, results);

    cout << results.size() << endl;
    for (auto it : results) {
        cout << it << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    creating_strings();
    return 0;
}