#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
  int x;
  int y;
};

bool cmp(Point r,Point l){
  if(r.x == l.x && r.y == l.y)
    return true;
  else
    return false;
}

int map[500][500];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n;
  Point ps[100];
  int psDir[100] = {0};
  int psDist[100] = {0};
  int psNowDist[100] = {0};
  int count[100] = {0};
  bool end[100] = {false};
  bool allEnd = false;
  int ans = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> ps[i].x >> ps[i].y;
    ps[i].y *= -1;
    ps[i].y += 250;
    ps[i].x += 250;
    psDist[i] = 1;
  }
  for(int y=0;y<500;y++)for(int x=0;x<500;x++) map[y][x] = -1;
  while(!allEnd){
    bool flag = true;
    vector<Point> nps;
    vector<Point> deadlock;
    for(int i=0;i<n;i++){
      if(!end[i]){
        flag = false;
        int next = map[ps[i].y+dy[psDir[i]]][ps[i].x+dx[psDir[i]]];
        if(next == -1){
          Point p = ps[i];
          p.y += dy[psDir[i]];
          p.x += dx[psDir[i]];
          nps.push_back(p);
          if(find(nps.begin(),nps.end(),p,cmp) != nps.end()){
            deadlock.push_back(p);
          }
        }else{
          if(ans < count[i]) ans = count[i];
          end[i] = true;
        }
      }
    }
    for(Point p:deadlock){
      while(find(nps.begin(),nps.end(),p,cmp) != nps.end()){
        auto iter =find(nps.begin(),nps.end(),p,cmp);
        nps.erase(iter);
      }
    }
    for(int i=0;i<n;i++){
      if(end[i]) continue;
      if(find(nps.begin(),nps.end(),ps[i],cmp) != nps.end()){
        map[ps[i].y][ps[i].x] = 1;
        count[i]++;
        psNowDist[i]++;
        if(psDist[i] == psNowDist[i]){
          psNowDist[i] = 0;
          psDir[i] = (psDir[i]+1) % 4;
          if(!(psDir[i]%2))psDist[i]++;
        }
      }
    }
    if(!nps.size()){
      flag = false;
      for(int i=0;i<n;i++){
        if(ans < count[i]) ans = count[i];
      }
    }
    allEnd = flag;
  }
  cout << ans << endl;
  return 0;
}
