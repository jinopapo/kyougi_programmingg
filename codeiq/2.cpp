#include <iostream>

using namespace std;

int main(){
  int perl[10] = {24,9,21,21,17,21,24,13,27,24};
  int n;
  long long ans=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    int num=i;
    long sum = 10000;
    while(num != 0){
      sum += perl[num%10]*1000;
      num /= 10;
    }
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}
