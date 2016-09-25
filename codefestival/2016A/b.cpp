#include <iostream>

using namespace std;

int a[100000];

int main(){
  int N;
  int ans = 0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  for(int i=0;i<N;i++){
    if(i==a[a[i]-1]-1)
      ans++;
  }
  cout << ans/2 << endl;;
  return 0;
}
