#include <iostream>

using namespace std;

char map[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int dict[2] = {1,0};
int H,W;

void Reflect(int now[2],int* dict){
  if(map[now[1]][now[0]] == '/'){
    int tmp = dict[0];
    dict[0] = -dict[1];
    dict[1] = -tmp;
  }
  if(map[now[1]][now[0]] == '\\'){
    int tmp = dict[0];
    dict[0] = dict[1];
    dict[1] = tmp;
  }
}

bool End(int now[2],int dict[2]){
  if(now[0] + dict[0] >= W || now[1] + dict[1] >= H || now[0]+dict[0] < 0 || now[1]+dict[1] < 0)
    return false;
  return true;
}

int Ans(){
  int ans = 1;
  int now[2] = {0,0};
  Reflect(now,dict);
  while(End(now,dict)){
    now[0] += dict[0];
    now[1] += dict[1];
    ans++;
    Reflect(now,dict);
  }
  return ans;
}

int main(){
  cin >> H >> W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> map[i][j];
    }
  }
  cout << Ans() <<endl;;
  return 0;
}
