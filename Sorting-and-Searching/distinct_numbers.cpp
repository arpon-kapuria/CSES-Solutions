// Distinct numbers


#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> numbers;

  for(int i=0; i<n; i++) {
    int num;
    cin >> num;
    numbers.insert(num);
  }

  cout << numbers.size() << endl;
}
