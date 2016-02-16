#include <iostream>

using namespace std;

int main(){
  int h,w,n;
  int cards[10] = {0};
  int player = 0;
  cin >> h >> w >> n;
  int t[13][13];
  for(int y=0;y<h;y++){
    for(int x=0;x<w;x++){
      cin >> t[y][x];
    }
  }
  int l;
  cin >> l;
  for(int i=0;i<l;i++){
    int ai,bi,Ai,Bi;
    cin >> ai >> bi >> Ai >> Bi;
    if(t[ai-1][bi-1] == t[Ai-1][Bi-1]){
      cards[player] += 2;
    }else{
      player = (player+1)%n;
    }
  }
  for(int i=0;i<n;i++){
    cout << cards[i] << endl;
  }
  return 0;
}
