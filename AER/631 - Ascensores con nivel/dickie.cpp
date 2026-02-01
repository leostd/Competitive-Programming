#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define SET(v,i) memset(v,i,sizeof(v));
#define FOR(i,n,k) for(int i=n;i<k;++i)
#define WHILE(i,n) while(i<n)
#define RI(i) scanf("%d",&i);
#define RS(i) scanf("%s",i);
#define RF(i) scanf("%lf",&i);
#define RL(i) scanf("%lld",&i);
#define OPEN(s) freopen(s,"r",stdin);
#define CLOSE(s) freopen(s,"w",stdout);

const int INF=0x3F3F3F3F; const int MAXN=100001; typedef long long int i64; typedef pair<int,int> pii; typedef pair<string,int> psi; struct lift{  int from, to, level;  lift(){}  lift(int a, int b, int c){   from = a; to = b; level = c;  }  bool operator<(const lift &other)const{   return from < other.from;  } }; 

vector<lift> arr(MAXN);
int n, max_height;
int memo[MAXN];
bool mark[MAXN];

int DP(int idx){
 if(arr[idx].to >= max_height){
  //fprintf(stderr,"found limit in %d, back with %d\n", idx, arr[idx].level);
  return arr[idx].level;
 }
 int &best = memo[idx];
 if(mark[idx]) return best;
 mark[idx] = true;
 best = INF;
 int bound_idx = idx+1;
 while(bound_idx < n && arr[bound_idx].from <= arr[idx].to){
  int next_call = DP(bound_idx);
  if(next_call != INF)
   best = min(best, max(arr[idx].level, next_call));
  bound_idx++;
 }
 return best;
}

int main(){
 #ifdef DM1_MACHINE
  OPEN("FILE.in");
  //CLOSE("FILE.out");
 #endif
 auto start = std::chrono::high_resolution_clock::now();
 while(scanf("%d", &n) != EOF && n){
  max_height = 0;
  FOR(i,0,n){
   mark[i] = false;
   memo[i] = INF;
   int f,t,l; RI(f); RI(t); RI(l);
   arr[i] = lift(f,t,l);
   max_height = max(max_height, t);
  }
  sort(arr.begin(), arr.begin()+n);
  int best_ans = INF, k = 0;
  while(k<n && arr[k].from == 0){ best_ans = min(best_ans, DP(k)); k++; }
  printf("%d\n", best_ans);
 }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  cout << duration.count() << endl;
 return 0;
}