#include <iostream>
#include <vector>

using namespace std;

int main(){
  int x,y,z,n;
  cin >> x >> y >> z >> n;
  //int d[100];
  //int a[100];
  vector<int> cx;
  vector<int> cy;

  for(int i=0;i<n;i++){
    int d;
    int a;
    cin >> d >> a;
    if(d == 1){
      cy.push_back(a);
    }else{
      cx.push_back(a);
    }
  }
  cy.push_back(y);
  cx.push_back(x);
  sort(cy.begin(),cy.end());
  sort(cx.begin(),cx.end());

  int prey=0;
  int minArea=1000000;
  for(auto iy:cy){
    int prex=0;
    for(auto ix:cx){
      int area = (ix-prex)*(iy-prey);
      if(area != 0){
        minArea = min(minArea,area);
      }
      prex=ix;
    }
    prey=iy;
  }
  cout << minArea*z << endl;
  return 0;
}
