#include <iostream>

using namespace std;

bool IsNico(long num,long niko){
  long nownico = 25;
  while(niko > nownico){
    if(num%nownico == 0) return false;
      nownico *= 100;
      nownico += 25;
  }
  return true;
}

int main(){
  long n;
  cin >> n;
  long niko = 25;
  int ans = 0;
  while(niko <= n){
    for(int i=1;i*niko<=n;i++){
      if(IsNico(i*niko,niko))ans++;
    }
    niko *= 100;
    niko += 25;
  }
  cout << ans << endl;
  return 0;
}
