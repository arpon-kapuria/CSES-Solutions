// Repetitions

#include <iostream>
#include <vector>

using namespace std;

int main() {
  string input;
  cin >> input;

  int max = 1;
  int cur_max = 1;
  char cur = input[0];

  for(auto i=1; i < int(input.size()); i++) {
    if (input[i] == cur) {
      cur_max++;
    } else {
      cur = input[i];
      if(cur_max > max) {
        max = cur_max;
      }
      cur_max = 1;
    }
  }
  
  if (cur_max > max) cout << cur_max;
  else cout << max;
}



