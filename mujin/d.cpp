#include <iostream>
#include <stack>

using namespace std;

string S;

bool isYes(int s,int e){
  stack<char> kakko;
  for(int i=s-1;i<e;i++){
    if(S[i] == '(')
      kakko.push('(');
    if(S[i] == ')'){
      if(kakko.empty()){
        return false;
      }else{
        kakko.pop();
      }
    }
    if(S[i] == '?'){
      if(kakko.empty())
        kakko.push('?');
    }
  }
  if(kakko.empty())
    return true;
  else
    return false;
}


int main(){
  int N,Q;
  cin >> N >> S >> Q;
  for(int i=0;i<Q;i++){
    int s,e;
    cin >> s >> e;
    if(isYes(s,e))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
