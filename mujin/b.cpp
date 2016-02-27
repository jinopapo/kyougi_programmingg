#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
  double a,b,c;
  cin >> a >> b >> c;
  double ans = (a+b+c)*(a+b+c)*M_PI;
  if(a - (b+c) > 0)
    ans -= (a-(b+c))*(a-(b+c))*M_PI;
  if(c - (a+b) > 0)
    ans -= (c-(a+b))*(c-(b+a))*M_PI;
  if(b-(a+c) > 0){
    ans -= (b-(a+c))*(b-(c+a))*M_PI;
  }
  cout << fixed << setprecision(7) << ans << endl;
  return 0;
}
