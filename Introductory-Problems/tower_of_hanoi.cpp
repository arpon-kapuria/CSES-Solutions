#include <bits/stdc++.h>
using namespace std;

void moves(int n, int start, int aux, int end) {
  if(n == 0)
    return;

  moves(n-1, start, end, aux);
  cout << start << " " << end << endl;
  moves(n-1, aux, start, end);
}

int main() {
  int n;
  cin >> n;

  cout << (1 << n) -1 << endl;
  moves(n, 1, 2, 3);
}
