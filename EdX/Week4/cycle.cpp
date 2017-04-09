#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

int c1, c2;
bool cycle = false;
std::bitset<100000> mark;

void dfs(vvi g, int i)
{
    std::bitset<100000> visited;
    mark[i] = true;
    for(int j = 1; j < g[i].size(); j++)
    {
        if (!visited[g[i][j]])
        {
            if (mark[g[i][j]])
            {
                c1 = i;
                c2 = g[i][j];
                cycle = true;
                return;
            }
            else
            {
                dfs(g, g[i][j]);
            }
            visited[g[i][j]] = true;
        }
        
    }
}

int main()
{
    FILE *infile = fopen("cycle.in", "r");
    FILE *outfile = fopen("cycle.out", "w");
    vvi g;
    int n, m;
    int s, d;
    fscanf(infile, "%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        g.push_back(vi(1,0));
    for (int i = 0; i < m; i++)
    {
        fscanf(infile, "%d %d", &s, &d);

        g[s].push_back(d);
    }
    dfs(g,1);
    if (cycle)
        fprintf(outfile, "YES\n%d %d", c1, c2);
    else
        fprintf(outfile, "NO\n");
    return 0;
}