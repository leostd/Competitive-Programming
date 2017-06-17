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
int n;
int BIT[1000010];
int A[1000010];
pii B[1000010];
int id;
int query(int x){
	int s = 0;
	while(x){
		s += BIT[x];
		x -= x & -x;
	}
	return s;
}
void upd(int x){
	while(x <= id){
		BIT[x]++;
		x += x & -x;
	}
}
int main(){
	while(true){
		fastInt(n);
		if(!n) break;
		for(int i = 1; i <= n; i++){
			fastInt(A[i]);
			B[i] = mp(A[i], i);
		}
		id = 0;
		sort(B + 1, B + n + 1);
		for(int i = 1; i <= n; i++){
			if(i == 1 || B[i].first != B[i-1].first) ++id;
			A[B[i].second] = id;
		}
		for(int i = 0; i <= id; i++) BIT[i] = 0;
		LL inv = 0LL;
		for(int i = n; i > 0; i--){
			int s = A[i] - 1;
			inv += query(s);
			upd(A[i]);
		}
		printf("%lld\n", inv);
	}
	return 0;
}