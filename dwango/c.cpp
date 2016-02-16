#include <iostream>

using namespace std;

int shuten[25252];
int ans[25252];
int line[25252];
int cost[25252];

int Noritugi(int g,int l,int sum){
  int ans = 100000;
  for(int i=g;i<l-1;i++){
    sum -= cost[i];
  }
  ans = min(ans,sum);
  for(int i=0;i<l;i++){
    int c=0;
    if(i < g){
      for(int j=0;j<g;j++){
        c += cost[j];
      }
    }else if(i > g){
      for(int j=l-1;j>g;j--){
        c += cost[j];
      }
    }
    if(c != 0){
      ans = min(shuten[line[i]]+c,ans);
    }
  }
  return ans;
}

int main(){
  int n,m;
  int s,g;
  for(int i=0;i<25252;i++){
    shuten[i] = 1000000;
    ans[i] = 1000000;
  }
  cin >> n >> m >> s >> g;
  for(int i=0;i<m;i++){
    int l;
    cin >> l;
    int sum = 0;
    for(int j=0;j<l;j++){
      cin >> line[j];
    }
    for(int j=0;j<l-1;j++){
      cin >> cost[j];
      sum+= cost[j];
    }
    for(int j=0;j<l;j++){
      shuten[line[j]] = min(shuten[line[j]],Noritugi(j,l,sum));
    }
  }
  cout << shuten[g] << endl;
}
