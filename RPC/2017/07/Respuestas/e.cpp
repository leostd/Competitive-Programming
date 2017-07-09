#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;
string A;
int n, m;
bool mark[110];
int memo[110];
bool app[110];
int dp(int pos, int& n, int& m){
	if(pos == n) return 0;
	int& ans = memo[pos];
	if(mark[pos]) return ans;
	mark[pos] = true;
	int d1 = INF, d2 = INF;
	if(app[pos]) d1 = dp(pos+m, n, m) + 1;
	d2 = dp(pos+1, n, m)+1;
	return ans=min(d1,d2);
}
int f(string B){
	size_t p = -1;
	m = (int)B.length();
	memset(app, 0, sizeof(app));
	memset(mark, 0, sizeof(mark));
	while((p = A.find(B,p+1)) != string::npos){
		app[p] = true;
	}
	return dp(0,n,m) + m;
}
int main(){
	cin>>A;
	n = (int)A.length();
	int ans = n;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			ans = min(ans, f(A.substr(i, j-i+1)));
		}
	}
	printf("%d\n", ans);
	return 0;
}