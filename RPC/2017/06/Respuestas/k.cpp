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
char T[2];
int S[6];
int main(){
	int t, n;
	int k;
	fastInt(t);
	while(t--){
		fastInt(n);
		int p = -1;
		S[0] = S[1] = S[2] = S[3] = 0;
		double total = 0.0;
		for(int i = 0; i < n; i++){
			scanf("%s %d", T, &k);
			if(T[0] == 'C' || T[0] == 'S'){
				total += k*k;
			}else{
				double s = 3*k/2.0;
				total += sqrt(s*(s-k)*(s-k)*(s-k));
			}
			if(T[0] == 'C') p++;
			S[p] += k;
			if(T[0] == 'C' && p) S[p-1] += k;
		}
		printf("%.4lf\n", S[0]*S[1] - total);
	}
	return 0;
}