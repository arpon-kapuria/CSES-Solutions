// sum of two values


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> values(n);

  for(int i=0; i<n; i++) {
    cin >> values[i];
  }

  map<int, int> map;

  for(int i = 0; i < n; i++) {
    if(map.count(x - values[i])) {
      cout << i+1 << " " << map[x - values[i]] << endl;
      return 0;
    }
    map[values[i]] = i+1;
  }

  cout << "IMPOSSIBLE" << endl;
}
