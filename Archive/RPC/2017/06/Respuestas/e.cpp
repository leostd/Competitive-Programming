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
bool mark[100010];
int main(){
	int t, n;
	fastInt(t);
	while(t--){
		fastInt(n);
		memset(mark, false, sizeof(mark));
		printf("0.");
		int m = 1;
		while(true){
			int s = (m*10)/n;
			m = (m*10)%n;
			if(mark[m]) break;
			mark[m] = true;
			printf("%d", s);
		}
		printf("\n");
	}
	return 0;
}