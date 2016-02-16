#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct field{
  int score;
  float dist;
  bool operator<(const field& a) const{
    return dist < a.dist;
  }
};

int main(){
  int ax,ay;
  int k,n;
  float sum = 0;
  priority_queue<field> near_field;
  cin >> ax >> ay;
  cin >> k >> n;
  for(int i=0;i<n;i++){
    field f;
    int x,y,p;
    cin >> x >> y >> p;
    f.dist = sqrt(pow(x-ax,2)+pow(y-ay,2));
    f.score = p;
    sum += p;
    near_field.push(f);
    if((int)near_field.size() > k){
      sum -= near_field.top().score;
      near_field.pop();
    }
  }
  cout << floor(sum/k+0.5) << endl;
}
