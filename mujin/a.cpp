#include <iostream>

using namespace std;

int main(){
  char c;
  cin >> c;
  if(c != 'O' && c != 'L' && c != 'K' && c != 'P')
    cout << "Left" << endl;
  else
    cout << "Right" << endl;
  return 0;
}
