#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int s,d;
    int ans=0;
    int train=2;
    cin >> s >> d;
    while(s != d){
      if(s%train){
        ans++;
        s++;
      }
      if(d%train){
        ans++;
        d--;
      }
      s /= 2;
      d /= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
