#include <iostream>

using namespace std;

int t[50000];
int s[50000];

int change(string s){
  if(s == "A"){
    return 1;
  }else if(s == "A#"){
    return 2;
  }else if(s == "B"){
    return 3;
  }else if(s == "C"){
    return 4;
  }else if(s == "C#"){
    return 5;
  }else if(s == "D"){
    return 6;
  }else if(s == "D#"){
    return 7;
  }else if(s == "E"){
    return 8;
  }else if(s == "F"){
    return 9;
  }else if(s == "F#"){
    return 10;
  }else if(s == "G"){
    return 11;
  }else{
    return 12;
  }
}

int main(){
  int num;
  cin >> num;
  for(int i=0;i<num;i++){
    int m,n;
    cin >> n >> m;
    string str;
    for(int j=0;j<n;j++){
      cin >> str;
      t[j] = change(str);
    }
    for(int j=0;j<m;j++){
      cin >> str;
      s[j] = change(str);
    }
    int now = n-1;
    for(int index=m-1;index != 0;index--){
      cout << t[now] << " " << s[index] << endl;
      if(t[now] - s[index] == 0){
        now--;
      }else if((t[now] - s[index])%10 == 1 && now+1 != n){
        now++;
      }else if((t[now]-s[now])%10 == -1){
        now -= 2;
      }else{
        break;
      }
    }
    if(now == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
