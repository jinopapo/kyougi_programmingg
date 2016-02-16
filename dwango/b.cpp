#include <iostream>

using namespace std;
long k[100000];
long l[100001];


int main(){
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++){
    cin >> k[i];
  }
  for(int i=0;i<n;i++){
    l[i] = 1;
  }
  l[0] = k[0];
  for(int i=0;i<n;i++){
    if(k[i] != max(l[i],l[i+1])){
      if(i != 0 && k[i-1] == l[i]){
        l[i+1] = k[i];
      }else if(i != n-1 && k[i] > k[i+1]){
        l[i] = k[i];
      }else{
        l[i+1] = k[i];
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << l[i] << " ";
  }
  cout << endl;
}
