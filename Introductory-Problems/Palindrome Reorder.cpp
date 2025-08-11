/*
Problem Link: https://cses.fi/problemset/task/1755/

Approach:

- First, Check if it can form a palindrome sequence by :
    - Count the frequency of each character in the input string
    - Check if the string can form a palindrome: at most one character can have an odd count.
    - Print “NO SOLUTION” if more than one odd count is found.
- Second, Build the palindrome sequence by :
    - Construct the palindrome by placing half of each character’s occurrences from the start and the other half symmetrically from the end.
    - If there is a character with an odd count, place it exactly in the middle of the palindrome.
    - Output the constructed palindrome.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkPalindrome(string s, unordered_map<char, int>& map) {
    for (auto ch : s) {
        map[ch]++;
    }

    bool found = false;
    for (auto it : map) {
        if (it.second % 2 != 0) {
            if (found) return false;
            found = true;
        }
    }
    return true;
}

void palindrome_reorder() {
    string s;
    cin >> s;

    unordered_map<char, int> map;

    if (!checkPalindrome(s, map)) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    int left = 0, right = s.length() - 1, mid = s.length()/2;

    for (auto it : map) {
        char ch = it.first;
        int count = it.second;

        if (count % 2 == 0) {
            for (int i = 0; i < count / 2; i++) {
                s[left++] = ch;
                s[right--] = ch;
            }
        } else {
            for (int i = 0; i < count / 2; i++) {
                s[left++] = ch;
                s[right--] = ch;
            }
            s[mid] = ch;
        }
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    palindrome_reorder();
    return 0;
}