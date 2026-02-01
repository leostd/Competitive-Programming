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
int f(string B){
	size_t p = -1;
	m = (int)B.length();
	int app = 0;
	while((p = A.find(B,p+1)) != string::npos){
		app++;
		p = p + m - 1;
	}
	return n - app*m + app + m;
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