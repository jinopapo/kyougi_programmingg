#include <iostream>

using namespace std;

long long amap[100000][100000];

int main(){
  int R,C;
  int N;
  cin >> R >> C;
  cin >> N;
  for(int i=0;i<N;i++){
    int r,c;
    cin >> r >> c;
    cin >> amap[r][c];
  }
  for(int i=0;i<R-1;i++){
    for(int j=0;j<C-1;j++){
      if(amap[i][j]+amap[i+1][j+1] != amap[i+1][j]+amap[i][j+1])
        cout << "No" << endl;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
