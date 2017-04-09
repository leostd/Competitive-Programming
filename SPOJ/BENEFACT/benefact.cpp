#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii g; // graph
int t; // test cases
int n; // nodes
int s,d, w; // src, dest, wgt
int idmax; // id of the max dist node
ll dmax; // max distance 
bool visited[50005];

void dfs(int a, int dist)
{
    visited[a] = true;
    vii al = g[a];
    if (dist > dmax)
    {
        dmax = dist;
        idmax = a;
    }
    for (int i = 0; i < al.size(); i++)
    {
        if (!visited[al[i].first])
            dfs(al[i].first, dist+al[i].second);
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        g = vvii(n+1, vii());
        dmax = -1;
        memset(visited, false, 50005 * sizeof(bool));
        for (int i = 0; i < n-1; i++)
        {
            scanf("%d %d %d", &s, &d, &w);
            g[s].push_back(ii(d,w));
            g[d].push_back(ii(s,w));
        }
        dfs(1,0);
        memset(visited, false, 50005 * sizeof(bool));
        dfs(idmax, 0);
        printf("%lli\n", dmax);
    }
    return 0;
}
