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
int fpow(int a, int e){
	int x = 1, y = a;
	while(e){
		if(e & 1) x = (x*y)%100;
		y = (y*y)%100;
		e >>= 1;
	}
	return x;
}
char P[1010];
int V[10];
int main(){
	int t;
	fastInt(t);
	V[0] = 1;
	for(int i = 1; i < 10; i++) V[i] = (V[i-1]*66)%100;
	while(t--){
		scanf("%s", P);
		int N = strlen(P);
		if(N == 1) printf("%d\n", V[atoi(P)]);
		else{
			int s = 0;
			for(int i = 0; i< N; i++){
				s = (s*10 + P[i]-'0')%5;
			}
			printf("%d\n", V[s+5]);
		}
	}
	return 0;
}