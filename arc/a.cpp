#include<iostream>

using namespace std;

int main(){
  int n,l;
  cin >> n >> l;
  string s;
  cin >> s;
  int tab = 1;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(s[i] == '+'){
      tab++;
      if(tab > l){
        tab = 1;
        ans++;
      }
    }else{
      tab--;
    }
  }
  cout << ans << endl;
  return 0;
}
