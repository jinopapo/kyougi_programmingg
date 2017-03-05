#include <iostream>

using namespace std;

int main(){
  string s;
  int y_count = 0;
  int a_count = 0;
  int h_count = 0;
  int o_count = 0;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(s[i] == 'y'){
      y_count++;
    }
    if(s[i] == 'a'){
      a_count++;
    }
    if(s[i] == 'h'){
      h_count++;
    }
    if(s[i] == 'o'){
      o_count++;
    }
  }
  if(y_count == 1
     && a_count == 1
     && h_count == 1
     && o_count == 2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
