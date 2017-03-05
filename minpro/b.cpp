#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  int K;
  long long ans=0;
  vector<int> A;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }
  sort(A.begin(),A.end());
  for(int i=0;i<K;i++){
    ans += i;
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}
