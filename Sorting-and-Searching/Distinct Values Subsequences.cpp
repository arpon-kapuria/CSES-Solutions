/*
Problem Link: https://cses.fi/problemset/task/3421/

Intuition:
The core idea is a dynamic programming approach. Instead of generating all subsequences, we iterate through the input array and for each element arr[i], we calculate how many times it acts as a "new" distinct value in subsequences ending at that point. We maintain a running product that implicitly helps count these contributions, based on the frequencies of previously seen elements. Modular arithmetic ensures calculations stay within bounds.

Approach:
- Modular Inverse Calculation: Uses Fermat's Little Theorem and binary exponentiation to efficiently compute modular inverses, crucial for division in modular arithmetic.
- Initialization: answer stores the final sum, product is a running product (starts at 1) and frequency maps elements to their counts.
- Iterative Processing: Loop through each element arr[i] of the input array.
- Current Contribution: Calculate subsequences_ending_here. This represents the number of subsequences formed by elements processed before arr[i] where adding arr[i] introduces it as a distinct value. This is derived from the product value, scaled by the inverse of (frequency[arr[i]] + 1).
- Accumulation: Add subsequences_ending_here to the total answer.
- Update Frequencies: Increment frequency[arr[i]].
- Update Product: Adjust the product for the next iteration based on the new frequency of arr[i]. This update maintains the required cumulative value for subsequent calculations.

Time Complexity: O(n log MOD), mod_inverse takes O(log MOD) time, and we process each of the n elements once.
Space Complexity: O(n).
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

// fast modular exponentiation to compute modular inverse
ll mod_inverse(ll a) {
    ll result = 1;
    ll power = MOD - 2;  // fermat's little theorem: a^(p-2) ≡ a^(-1) (mod p)
    
    while (power > 0) {
        if (power & 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        power >>= 1;
    }
    return result;
}

void distinct_values_subsequences() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll answer = 0, product = 1;  
    map<int, int> frequency; 
    
    for (int i = 0; i < n; i++) {
        ll subsequences_ending_here = (product * mod_inverse(frequency[arr[i]] + 1)) % MOD;
        answer = (answer + subsequences_ending_here) % MOD;
        
        frequency[arr[i]]++;
        product = (product * (frequency[arr[i]] + 1)) % MOD;
        product = (product * mod_inverse(frequency[arr[i]])) % MOD;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    distinct_values_subsequences();
    return 0;
}