#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  __int128 total_sum = (__int128)n * (__int128)(n+1) / 2;

  if(total_sum % 2 != 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;

    unordered_set<__int128> set;
    __int128 target = total_sum/2;
    __int128 sum = 0;
    __int128 i = n;


    while(sum < target) {
      set.insert(i);
      sum += i;
      i--;
    }

    if(sum > target){
      sum -= (i+1);
      set.erase(set.find(i+1));
      set.insert(target-sum);
    }
    
    cout << set.size() << endl;
    for(auto it:set)
      cout << it << " ";

    cout << endl << n - set.size() << endl;

    for(int j=1; j<=n; j++){
      if(set.find(j) == set.end())
        cout << j << " ";
    }
  }
  return 0;
}


