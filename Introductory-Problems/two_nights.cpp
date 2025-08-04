#include <bits/stdc++.h>
using namespace std;

int main() {
  long long t;
  cin >> t;

  for(long long i=1; i<=t; i++) {
    long long total_ways = ((i*i) * ((i*i)-1))/2;
    long long attack = 4 * (i-1) * (i-2);
    long sol = total_ways - attack;
    cout << sol << endl;
  }
  return 0;
}


