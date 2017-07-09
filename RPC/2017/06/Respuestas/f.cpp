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
map<string,int> M;
char buf[110]; string str;
set<int> N[2010], G[2010];
string S[2010];
set<int> ans;
bool D[2010];
int main(){
	int t, n, m;
	fastInt(t);
	while(t--){
		fastInt(n); fastInt(m);
		for(int i = 0; i < n; i++){
			scanf("%s", buf); str = buf;
			S[i] = str;
		}
		sort(S, S + n);
		for(int i = 0; i < n; i++){
			M[S[i]] = i;
		}
		for(int i = 0; i < m; i++){
			int a;
			fastInt(a);
			for(int j = 0; j < a; j++){
				int ti;
				fastInt(ti);
				scanf("%s", buf); str = buf;
				if(ti == 1) G[i].insert(M[str]);
				else N[i].insert(M[str]);
			}
		}
		memset(D, false, sizeof(D));
		int req = 0;
		int s;
		while(true){
			s = 0;
			for(int i = 0; i < m; i++){
				if((int)G[i].size() + (int)N[i].size() == 0){
					s = -1;
					break;
				}else if(N[i].empty() && !D[i]){
					for(int j = 0; j < m; j++){
						if(i == j) continue;
						N[j].erase(*G[i].begin());
					}
					ans.insert(*G[i].begin());
					s = 1;
					D[i] = true;
					break;
				}
			}
			if(s <= 0) break;
		}
		if(s < 0) printf("Impossible\n");
		else{
			printf("%d\n", (int)ans.size());
			for(set<int>::iterator i = ans.begin(); i != ans.end(); i++) printf("%s\n", S[*i].c_str());
		}
		ans.clear();
		for(int i = 0; i < m; i++){
			G[i].clear();
			N[i].clear();
		}
		M.clear();
	}
	return 0;
}