#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL unsigned long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
inline void fastInt(int &a){
    char c;
    int s = 1;
    a = 0;
	while(true){
		c = getchar_unlocked();
		if(c=='-') s = -1;
		if(c>='0' && c<='9') break;
	}
	while(true){
		a = a*10 + c-'0';
		c = getchar_unlocked();
		if(c<'0' || c>'9') break;
	}
	a *= s;
}
int t, x, a, d, m;
int A[40], B[40], C[40];
set<pair<pii,int> > s;
int main(){
	fastInt(t);
	while(t--){
		fastInt(x); fastInt(a); fastInt(d); fastInt(m);
		for(int i = 0; i < m; i++){
			scanf("%*s"); fastInt(A[i]);fastInt(B[i]);fastInt(C[i]);
		}
		int n = m/2;
		for(int i = 0; i < (1<<n); i++){
			pair<pii,int> P;
			P = mp(mp(0,0),0);
			for(int j = 0; j < n; j++){
				if(i & (1<<j)){
					P.first.first += A[j];
					P.first.second += B[j];
					P.second += C[j];
				}
			}
			s.insert(P);
		}
		bool ok = false;
		for(int i = 0; i < (1<<(n + (m&1))) && !ok; i++){
			pair<pii,int> P;
			P = mp(mp(0,0),0);
			for(int j = 0; j < n + (m&1); j++){
				if(i & (1<<j)){
					P.first.first += A[j+n];
					P.first.second += B[j+n];
					P.second += C[j+n];
				}
			}
			P.first.first = x - P.first.first;
			P.first.second = a -P.first.second;
			P.second = d - P.second;
			ok = s.count(P);	
		}
		printf("%s\n", ok ? "POSSIBLE" : "IMPOSSIBLE");
		s.clear();
	}
	return 0;
}