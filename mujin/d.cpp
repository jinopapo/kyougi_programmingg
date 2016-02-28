#include <iostream>
#include <stack>

using namespace std;

const int SIZE = 16384;
string S;

struct SegTree{
  int node[SIZE*2-1];
  int n;

  void update(int i,int x){
    i += n-1;
    node[i] = x;
    while(i > 0){
      i = (i-1)/2;
      node[i] = min(node[i*2+1],node[i*2+2]);
    }
  }

  int query(int s,int e,int k=0,int l=0,int r=-1){
    if(r == -1) r=n;
    if(r <= s || e <= l) return 20000;
    if(s <= l && r <= e){
      return node[k];
    }else{
      int vl = query(s,e,k*2+1,l,(l+r)/2);
      int vr = query(s,e,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
};

SegTree segl;
SegTree segr;
int no[10001];
int nc[10001];
int nq[10001];

void initSeg(int n){
  int l=0;
  int r=0;
  segr.n = n;
  segl.n = n;
  for(int i=0;i<SIZE*2-1;i++){
    segl.node[i]=20000;
    segr.node[i]=20000;
  }
  for(int i=0;i<n;i++){
    if(S[i] == '('){
      l++;
      r++;
      segl.update(i,l);
      segr.update(i,r);
      no[i]++;
    }
    if(S[i] == ')'){
      l--;
      r--;
      segl.update(i,l);
      segr.update(i,r);
      nc[i]++;
    }
    if(S[i] == '?'){
      l++;
      r--;
      segl.update(i,l);
      segr.update(i,r);
      nq[i]++;
    }
    no[i+1]=no[i];
    nc[i+1]=nc[i];
    nq[i+1]=nq[i];
  }
}

bool isYes(int s,int e){
  s--;
  e--;
  if((s+e+1)%2) return false;
  int l = segl.node[s+segl.n-1];
  int r = segr.node[e+segr.n-1];
  int o,c,q;
  if(s!=0){
    o = no[e]-no[s-1];
    c = nc[e]-nc[s-1];
    q = nq[e]-nq[s-1];
  }else{
    o = no[e]-no[s];
    c = nc[e]-nc[s];
    q = nq[e]-nq[s];
  }
  if(abs(o-c) > q) return false;
  cout << l << " " << segl.query(s,s+(e-s)/2+1) << endl;
  if(segl.query(s,s+(e-s)/2+1) < l) return false;
  cout << r << " " << segr.query(e-(e-s)/2-1,e) << endl;
  if(segr.query(e-(e-s)/2-1,e) < r) return false;
  return true;
}



int main(){
  int N,Q;
  cin >> N >> S >> Q;
  initSeg(N);
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
