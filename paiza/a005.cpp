#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct game{
  int first;
  int second;
};

int main(){
  int a,b,n;
  vector<game> games;
  string p[210];
  int score = 0;
  int end[210] = {0};
  cin >> a >> b >> n;
  for(int i=0;i<n;i++){
    cin >> p[i];
  }
  for(int i=0;i<n;i++){
    bool st = false;
    bool sp = false;
    int first = -1;
    int second = -1;
    if(p[i] == "G"){
      first = 0;
    }else{
      first = stoi(p[i]);
    }
    if(first != b && i+1 < n){
      if(p[i+1] == "G"){
        second = 0;
      }else{
        second = stoi(p[i+1]);
      }
      if(first + second == b){
        sp = true;
      }
    }else{
      st = true;
    }
    if(st){
      end[i+1]++;
      end[i+2]++;
    }
    if(sp){
      end[i+2]++;
    }
    score += first + (first * end[i]);
    if(second != -1){
      i++;
      score += second + (second * end[i]);
    }
  }
  cout << score << endl;
  return 0;
}
