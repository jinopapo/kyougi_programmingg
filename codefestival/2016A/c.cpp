#include <iostream>

using namespace std;

int main(){
  string ans = "";
  string s;
  long long k;
  cin >> s;
  cin >> k;
  for(int i=0;i<(int)s.size();i++){
    int ind = s[i]-'a';
    if(k >= 26-ind && ind != 0 && i != (int)s.size()-1){
      k -= 26-ind;
      ans += 'a';
    }else if(i != (int)s.size()-1){
      ans += s[i];
    }else{
      char a = 'a' + (s[i]-'a'+k)%26;
      ans += a;
    }
  }
  cout << ans << endl;
  return 0;
}
