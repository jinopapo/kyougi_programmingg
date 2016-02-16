#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;

int edge[10][10];
int n;

int dfs(int s,bool flag[],int cost){
  flag[s] = true;
  int ans = INF;
  for(int i=0;i<n;i++){
    if(!flag[i]){
      flag[i] = true;
      ans = min(dfs(i,flag,cost+edge[s][i]),ans);
      flag[i] = false;
    }
  }
  if(ans == INF){
    ans = cost;
  }
  return ans;
}

int main(){
  bool flag[10] = {false};
  int ans = INF;
  cin >> n;
  for (int i=0; i < n; i++) {
    for (int j=0; j < n; j++) {
      cin >> edge[i][j];
    }
  }

  for(int i=0;i<n;i++){
    flag[i] = true;
    ans = min(ans,dfs(i,flag,0));
    flag[i] = false;
  }

  cout << ans << endl;
  return 0;
}
