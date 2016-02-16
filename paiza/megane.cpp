#include<iostream>

using namespace std;

int main(){
  int n,m;
  int q[100][100];
  int p[10][10];
  int maskx[100];
  int masky[100];
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> q[i][j];
    }
  }
  cin >> m;
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cin >> p[i][j];
    }
  }
  for(int y=0;y<m;y++){
    for(int x=0;x<m;x++){
      maskx[y*m+x] = x;
      masky[y*m+x] = y;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      bool match = true;
      for(int k=0;k<m*m;k++){
        if(q[i+masky[k]][j+maskx[k]] != p[masky[k]][maskx[k]]) match = false;
      }
      if(match){
        cout << i << " " << j << endl;
      }
    }
  }

  return 0;
}
