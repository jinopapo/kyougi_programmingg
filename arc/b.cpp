#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int minx,maxx;
  int miny,maxy;
  int ansx,ansy;
  int mindist;
  if(n > 1){
    int x1,y1;
    int x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if(y1 > y2 || (y1 == y2 && x1 > x2)){
      minx = x2;
      miny = y2;
      maxx = x1;
      maxy = y1;
    }else{
      minx = x1;
      miny = y1;
      maxx = x2;
      maxy = y2;
    }
    mindist = abs(x1-x2)+abs(y1-y2);
    ansx = (maxx+minx)/2;
    ansy = (maxy+miny)/2;
  }else{
    ansx = 0;
    ansy = 0;
  }
  for(int i=2;i<n;i++){
    int x,y;
    cin >> x >> y;
    int dist1 = abs(minx-x)+abs(miny-y);
    int dist2 = abs(maxx-x)+abs(maxy-y);
    int dist = max(dist1,dist2);
    if(mindist > dist){
      if(dist1 < dist2){
        minx = x;
        miny = y;
      }else{
        maxx = x;
        maxy = y;
      }
    }
  }
  cout << ansx << " " << ansy << endl;
  return 0;
}
