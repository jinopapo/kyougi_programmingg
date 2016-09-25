#include <iostream>
#include <queue>

using namespace std;

struct Point{
  int x,y;
  int count;
};

char map[1000][1000];
bool done[1000][1000];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int main(){
  int n,m;
  cin >> n >> m;
  Point s,g;
  for(int y = 0;y<m;y++){
    for(int x=0;x<n;x++){
      cin >> map[y][x];
      done[y][x] = true;
      if(map[y][x] == '1'){
        done[y][x] = false;
      }
      if(map[y][x] == 's'){
        done[y][x] = false;
        s.x = x;
        s.y = y;
        s.count = 0;
      }
      if(map[y][x] == 'g'){
        g.x = x;
        g.y = y;
      }
    }
  }
  queue<Point> bfs;
  bfs.push(s);
  while(!bfs.empty()){
    Point now = bfs.front();
    bfs.pop();
    for(int i=0;i<4;i++){
      Point next = now;
      next.x += dx[i];
      next.y += dy[i];
      next.count++;
      if(next.x < n && next.x >= 0 && next.y < m && next.y >= 0){
        if(done[next.y][next.x]){
          done[next.y][next.x] = false;
          bfs.push(next);
        }
        if(map[next.y][next.x] == 'g'){
          cout << next.count << endl;
          return 0;
        }
      }
    }
  }
  cout << "Fail" << endl;
  return 0;
}
