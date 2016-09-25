#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int x1,y1,r;
  cin >> x1 >> y1 >> r;
  int x2,y2,x3,y3;
  cin >> x2 >> y2 >> x3 >> y3;
  int y12 = sqrt(pow(r,2) - pow(x1-x2,2));
  int y13 = sqrt(pow(r,2) - pow(x1-x3,2));
  if((y2 < y13 && y13< y3 && y13 != y1) || (y2 < y12 && y12 < y3 && y12 != y1)){
    cout << "YES" << endl;
    cout << "YES" << endl;
  }else{
    int rx1 = x1+r;
    int rx2 = x1-r;
    int ry1 = y1+r;
    int ry2 = y1-r;
    if(x2 <= rx2 && rx1 <= x3 && y2 <= ry2 && ry1 <= y3){
      cout << "NO" << endl;
      cout << "YES" << endl;
    }else if(rx2 < x2 && x3 < rx1 && ry2 < y2 && y3 < ry1){
      cout << "YES" << endl;
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      cout << "YES" << endl;
    }
  }
  return 0;
}
