/*
Problem Link: https://cses.fi/problemset/task/1082/

Intuition:
The goal is to compute the sum of divisors for all numbers from 1 to num. Instead of looping through every divisor for each number (which is too slow), we notice that the value of num / i only changes O(√num) times. Using this property, we can compute contributions in groups and avoid redundant work.

Approach:
- Each divisor i contributes to the sum multiple times: once for each number where it divides.
- For every i ≤ √num, split the contribution into two parts:
    - Direct contribution (t1): i contributes to numbers in [i, num/i].
    - Range contribution (t2): all divisors greater than i but equal to num/j are summed using arithmetic progression.
- Use prefix sum formula (x * (x+1)) / 2 under modulo to compute ranges efficiently.
- Handle modular arithmetic carefully (since numbers are large) using % MOD and modular inverse of 2.
- Accumulate contributions into the final answer.

Time Complexity: O(√num)
Space Complexity: O(1)

N.B: Refer to this gfg page for better understanding: https://www.geeksforgeeks.org/dsa/sum-divisors-1-n/
*/


#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

void sum_of_divisors() {
    long long num;
    cin >> num;

    long long sum = 0;
    for (long long i = 1; i <= sqrt(num); i++) {
        // (num / i - i + 1) can be large, so take mod at each step
        long long cnt = (num / i - i + 1) % MOD;
        long long t1 = (i % MOD) * cnt % MOD;

        // sum of numbers from i+1 to num/i
        long long hi = num / i;
        long long lo = i;

        // use formula safely with mod
        long long s_hi = hi % MOD * ((hi + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD; // (hi*(hi+1))/2
        long long s_lo = lo % MOD * ((lo + 1) % MOD) % MOD * ((MOD + 1) / 2) % MOD; // (lo*(lo+1))/2

        long long t2 = (s_hi - s_lo + MOD) % MOD;

        sum = (sum + t1 + t2) % MOD;
    }

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sum_of_divisors();
    return 0;
}