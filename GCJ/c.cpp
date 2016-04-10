#include <iostream>

using namespace std;

int main(){
    int t;
  cin >> t;
  for(int it=0;it<t;it++){
    cout << "Case #" << it+1 << ": " << endl;
    int J,K;
    cin >> J >> K;
    int n = 1;
    for(int i=0;i<J;i++){
      n = n << 1;
    }
    cout << n << endl;
    int acount = 0;
    for(int i=n-1;i>=0;i--){
      if(i%2 == 0) continue;
      if(acount == K) continue;
      int ans[9] = {0};
      bool flag = true;
      for(int j=2;j<=10;j++){
        if(!flag) continue;
        int num = i;
        int sum = 1;
        int count = 1;
        for(int k=1;k<J;k++){
          count *= j;
          if(num%2 == 1)
            sum += count;
          num = num >> 1;
        }
        for(int k=2;k<sum;k++){
          if(sum%k == 0)
            ans[j-2] = sum/k;
        }
        if(!ans[j-2])
          flag = false;
      }
      if(flag){
        int num = i;
        for(int k=J;k>0;k--){
          cout << (num >> (k-1))%2;
        }
        for(int j=0;j<8;j++){
          cout << " " << ans[j];
        }
        cout << endl;
        acount++;
      }
    }
  }
}
