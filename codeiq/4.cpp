#include <iostream>

using namespace std;

int main(){
  int n;
  int dp[100][100];
  for(int i=0;i<100;i++)for(int j=0;j<100;j++) dp[i][j] = -1;
  int ans = 0;
  dp[0][0] = 0;
  cin >> n;
  for (int i=0; i < n; i++) {
    int d,kd,md;
    bool flag[100][100];
    for(int j=0;j<100;j++)for(int k=0;k<100;k++) flag[j][k] = false;
    cin >> d >> kd >> md;
    for(int j=0;j<100;j++){
      for(int k=0;k<100;k++){
        if(j >= md  && k >= kd && dp[j-md][k-kd] != -1 && !flag[j-md][k-kd]){
          if(dp[j-md][k-kd]+ d > dp[j][k]){
            flag[j][k] = true;
          }
          dp[j][k] = max(dp[j-md][k-kd]+ d,dp[j][k]);
        }
      }
    }
  }


  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      ans = max(ans,dp[i][j]);
    }
  }

  cout << ans << endl;

  return 0;
}
