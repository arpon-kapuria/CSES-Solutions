// Increasing Array

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> in(n);

  for(auto i=0; i<n; i++)
    cin >> in[i];

  long long count = 0;
  long long max = in[0];
  
  for(auto it=1; it < n; it++){
    if (in[it] > max)
      max = in[it];

    if(in[it] < max){
      count = count + (max - in[it]);
    }

  }

  cout << count;

}


