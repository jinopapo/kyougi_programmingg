#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int n,m,k;
  double items[100];
  long long ranks[1000];
  double param[1000];
  cin >> n >> m >> k;
  for(int i=0;i<n;i++){
    cin >> param[i];
  }
  for(int i=0;i<m;i++){
    float score = 0;
    for(int j=0;j<n;j++){
      cin >> items[j];
      score += items[j]*param[j];
    }
    if((long long)(score*10) % 10 > 4){
      ranks[i] = (long long)floor(score)+1;
    }else{
      ranks[i] = score;
    }
  }
  sort(ranks,ranks+m,[](const long long& x, const long long& y) { return x > y;});
  for(int i=0;i<k;i++){
    cout << ranks[i] << endl;
  }
  return 0;
}
