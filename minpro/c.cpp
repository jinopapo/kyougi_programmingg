#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S[100000];

int main(){
  vector<int>A;
  int N;
  int K;
  cin >> N >> K;
  for(int i=0;i<K;i++){
    int tmp;
    cin >> tmp;
    A.push_back(tmp-1);
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    cin >> S[i];
  }
  if(N==K){
    cout << "" << endl;
    return 0;
  }
  string min_string = S[A[0]];
  for(int i=1;i<K;i++){
    if(min_string.size() > S[A[i]].size()){
      if(min_string.substr(0,S[A[i]].size()) != S[A[i]]){
        string tmp = "";
        for(int j=0;j<S[A[i]].size();j++){
          if(min_string.substr(0,j) == S[A[i]].substr(0,j)){
            tmp = S[A[i]].substr(0,j);
          }
        }
        if(tmp == ""){
          cout << -1 << endl;
          return 0;
        }else{
          min_string = tmp;
        }
      }else{
        min_string = S[A[i]];
      }
    }else{
      if(S[A[i]].substr(0,min_string.size()) != min_string){
        string tmp = "";
        for(int j=0;j<min_string.size();j++){
          if(min_string.substr(0,j) == S[A[i]].substr(0,j)){
            tmp = min_string.substr(0,j);
          }
        }
        if(tmp == ""){
          cout << -1 << endl;
          return 0;
        }else{
          min_string = tmp;
        }
      }
    }
  }
  bool flag = false;
  for(int k=0;k<=min_string.size();k++){
    flag = true;
    int j=0;
    for(int i=0;i<N;i++){
      if(!flag)
        continue;
      if(K > j && A[j] == i){
        j++;
        continue;
      }
      if(S[i].substr(0,k) == min_string.substr(0,k)){
        flag = false;
      }
    }
    if(flag)
      min_string = min_string.substr(0,k);
  }
  if(flag){
    cout << min_string << endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}
