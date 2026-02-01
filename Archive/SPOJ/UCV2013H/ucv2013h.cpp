#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
int cslick; //slick counter
vvi g; // grid
vvi vis; // visited
map<int, int> counter; // size counters
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

bool check(ii pos)
{
    return (pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m);
}

void bfs(ii s)
{
    ii a, b;
    int sz;
    int cs = 1;
    queue<ii> q;
    q.push(s);
    vis[s.first][s.second] = 1;
    while(!q.empty())
    {
        sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            a = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                b = ii(a.first + mx[j], a.second + my[j]);
                if (check(b) && !vis[b.first][b.second] && g[b.first][b.second])
                {
                    vis[b.first][b.second] = 1;
                    cs++;
                    q.push(b);
                }
            }
        }
    }
    counter[cs]++;
    cslick++;
}


int main()
{
    while(scanf("%d %d", &n, &m), n && m)
    {
        g = vvi(n, vi(m, 0));
        vis = vvi(n, vi(m, 0));
        counter.clear();
        cslick = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%1d", &g[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 1 && !vis[i][j])
                    bfs(ii(i,j));
            }
        printf("%d\n", cslick);
        for (auto it = counter.begin(); it != counter.end(); ++it)
        {
            printf("%d %d\n", it->first, it->second);
        }
    }
    return 0;
}

