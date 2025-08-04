#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if(n == 1) {
    cout << n << endl;
    return 0;
  }

  if(n <= 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  int start = (n & 1) ? n-1:n;
  for(int i = start-1; i > 0; i-=2)
    cout << i << " ";
  for(int i = start; i > 0; i-=2)
    cout << i << " ";

  if(n & 1)
    cout << n << endl;

}



