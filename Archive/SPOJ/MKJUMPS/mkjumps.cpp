#include <stdio.h>
#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int mx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}; // x moves
int my[8] = {-1, 1, -2, 2, -2, 2, -1, 1}; // y moves
int r; // rows
vvi g; // grid
vvi vis; // visited
int a, b; // pairs
int vs; // valid square counter
int maxCount;

bool check(ii ps)
{
	bool flag;
	// is it on the 10x10 grid?
	flag = (ps.first >= 0 && ps.first < 10 && ps.second >= 0 && ps.second < 10);
	// is it on a valid square?
	return (flag && g[ps.first][ps.second]);
}

void dfs(ii s, int count)
{
	ii a;
	vis[s.first][s.second] = 1;
	for (int i = 0; i < 8; i++)
	{
		a = ii(s.first + mx[i], s.second + my[i]);
		if (check(a) && !vis[a.first][a.second])
		{
			dfs(a, count+1);

		}
	}
	vis[s.first][s.second] = 0;
	if (count > maxCount)
		maxCount = count;
}

int main()
{
	int sc = 1; // case
	ii ulc; // upper left corner coords
	while(scanf("%d", &r), r != 0)
	{
		g = vvi(10, vi(10, 0));
		vis = g;
		vs = maxCount = 0;
		// 1 is a valid square, 0 invalid square
		for (int i = 0; i < r; i++)
		{
			scanf("%d %d", &a, &b);
			if (i == 0)
				ulc = ii(0, a);
			for (int j = 0; j < b; j++)
			{
				g[i][a+j] = 1;
				vs++;
			}
		}
		dfs(ulc, 1);
		if (vs - maxCount == 1)
			printf("Case %d, 1 square can not be reached.", sc++);
		else
			printf("Case %d, %d squares can not be reached.", sc++, vs - maxCount);
		printf("\n");
	}
	return 0;
}

