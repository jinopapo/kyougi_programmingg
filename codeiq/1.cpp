#include <iostream>

using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  for (int i = 0; i < y; i++) {
    for (int j= 0; j < x; j++) {
      char c;
      cin >> c;
      if(c == '*'){
        cout << j+1 << " " << i+1 << endl;
      }
    }
  }
  return 0;
}
