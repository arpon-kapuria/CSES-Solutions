// Missing Number

#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = n * (n+1) / 2;
  
  vector<long long> nums(n);

  for(long long i=1; i < n; i++) {
    cin >> nums[i];
    sum -= nums[i];
  }
  
  cout << sum;
  return 0;
}
