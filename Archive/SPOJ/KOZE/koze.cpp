#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int r, c; // row columns
int sc, slc = 0; // global sheep counter - local sheep counter
int wc, wlc = 0; // gloabal wolves counter - local wolves counter
int mx[4] = {0, 0, 1, -1}; // y axe moves
int my[4] = {1, -1, 0, 0}; // x axe moves
vector<string> g; // grid
vvi vis; // visited grid
vector<ii> s; // sheeps
vector<ii> w; // wolves

bool isBorder(ii ps)
{
	return (ps.first == 0 || ps.first == r-1 || ps.second == 0 || ps.second == c-1);
}

bool check(ii ps)
{
	return (ps.first >= 0 && ps.first < r && ps.second >= 0 && ps.second < c);
}

void bfs(ii st)
{
	queue<ii> q;
	ii b, t;
	bool flag = false; // can escape?
	vis[st.first][st.second] = 1;
	q.push(st);
	while(!q.empty())
	{
		b = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			t = ii(b.first + mx[i], b.second + my[i]);
			if (check(t) && !vis[t.first][t.second] && g[t.first][t.second] != '#')
			{
				vis[t.first][t.second] = 1;
				if(isBorder(t))
					flag = true;
				if(g[t.first][t.second] == 'k')
					slc++;
				else if (g[t.first][t.second] == 'v')
					wlc++;
				q.push(t);
			}
		}
	}
	if (flag)
		wlc = slc = 0; // if they can leave then no one dies
}

int main ()
{
	char ch;
	scanf("%d %d\n", &r, &c);
	g = vector<string>(r, "");
	vis = vvi(r, vi(c, 0));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%c", &ch);
			g[i].push_back(ch);
			if (ch == 'k')
				s.push_back(ii(i,j));
			if (ch == 'v')
				w.push_back(ii(i,j));
		}
		scanf("\n");
	}
	sc = s.size();
	wc = w.size();
	for (int i = 0; i < s.size(); i++)
	{
		ii a = s[i];
		if (!vis[a.first][a.second] && !isBorder(a))
		{
			slc = 1; // starting from all the sheep
			bfs(a);
			if (slc > wlc)
				wc -= wlc; // all wolves die
			else
				sc -= slc; // all sheep die
			wlc = slc = 0;
		}
	}
	printf("%d %d\n", sc, wc);
	return 0;
}