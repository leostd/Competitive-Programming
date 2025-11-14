#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+77;
 
void O_o()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> a(n+7);
	map<set<int>,int> _2;
	map<int,int> _1;
	set<int> s;
	for(int i=1; i<=m; i++)
	{
		int l,r;
		cin>>l>>r;
		a[l].push_back(i); a[r+1].push_back(-i);
	}
	int ans=0,ass=0;
	for(int i=1; i<=n; i++)
	{
		for(auto j:a[i])
		{
			if(j>0) s.insert(j);
			else s.erase(-j);
		}
		if(s.empty()) ass++;
		else if(s.size()==1) _1[*s.begin()]++;
		else if(s.size()==2) _2[s]++;
	}
	int mx1=0,mx2=0;
	for(auto [x,y]:_1)
	{
		if(y>=mx1)
		{
			mx2=mx1; mx1=y;
		}
		else mx2=max(mx2,y);
	}
	ans=max(ans,mx1+mx2);
	for(auto [st,y]:_2)
	{
		ans=max(ans,y+_1[*st.begin()]+_1[*(--st.end())]);
	}
	cout<<ans+ass<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout<<fixed<<setprecision(2);
	int T=1;
	cin>>T;
	while(T--)
	{
		O_o();
	}
}
