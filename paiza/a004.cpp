#include<iostream>
#include<queue>

using namespace std;

struct line{
  int next;
  int high;
  int nhigh;
  bool operator<(const line& a) const{
    return high < a.high;
  }
};

int main(){
  int L,n,m;
  priority_queue<line> lines[10001];
  cin >> L >> n >> m;
  for(int i=0;i<m;i++){
    line l1,l2;
    int num;
    cin >> num >> l1.high >> l2.high;
    l1.nhigh = l2.high;
    l2.nhigh = l1.high;
    l1.next = num;
    lines[num-1].push(l1);
    l2.next = num-1;
    lines[num].push(l2);
  }
  bool end = false;
  int high=L;
  int index = 0;
  while(!end){
    while(!lines[index].empty() && high <= lines[index].top().high){
      lines[index].pop();
    }
    if(lines[index].empty()){
      cout << index+1 << endl;
      end = true;
    }else{
      int i = lines[index].top().next;
      high = lines[index].top().nhigh;
      lines[index].pop();
      index = i;
    }
  }
  return 0;
}
