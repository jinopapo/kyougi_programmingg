#include <iostream>

using namespace std;

int edge[16][16] = {{-1}};

int main(){
  int N,M;
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int s,e;
    cin >> s >> e;
    edge[s][e] = 0;
    edge[e][s] = 0;
  }
  while(){

  }
  return 0;
}
