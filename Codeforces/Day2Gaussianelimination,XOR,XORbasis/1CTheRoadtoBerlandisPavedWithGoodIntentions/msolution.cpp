#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

void reduce(vector<vector<int> >& x){ // returns determinant
	int n=x.size(),m=x[0].size();
	int i=0,j=0;
	while(i<n&&j<m){
		int l=i;
		fore(k,i+1,n)if(x[k][j]) l=k;
		if(!x[l][j]){j++;continue;}
		if(l!=i) swap(x[i],x[l]);
		fore(k,0,n) if(k!=i&&x[k][j]) fore(l,j,m) x[k][l]^=x[i][l];
		i++;j++;
	}
}

int main(){FIN;
	int n,m; cin>>n>>m;
	vector<vector<int>> a;
	
	fore(i,0,m){
		int x,y,w; cin>>x>>y>>w; x--; y--;
		vector<int> now(n+1);
		now[x]=now[y]=1;
		now[n]=1-w;
		a.pb(now);
	}
	
	reduce(a);
	
	int bad=0;
	fore(i,0,SZ(a)) if(a[i][n]){
		int all=1;
		fore(j,0,n) all&=!a[i][j];
		bad|=all;
	}
	
	if(bad)cout<<"Impossible\n",exit(0);
	
	vector<int> ans;
	fore(i,0,SZ(a)) fore(j,0,n) if(a[i][j]){
		if(a[i][n]) ans.pb(j);
		break;
	}
	
	cout<<SZ(ans)<<"\n";
	for(auto x:ans)cout<<x+1<<" ";cout<<"\n";
}
