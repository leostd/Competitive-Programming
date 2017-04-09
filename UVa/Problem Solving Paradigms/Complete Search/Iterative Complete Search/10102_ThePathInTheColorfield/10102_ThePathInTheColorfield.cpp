#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int mdist(ii a, ii b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

int main()
{
    int m, a;
    
    while(scanf("%d", &m) != EOF)
    {
        vector<vi> g(m, vi(m, 0));
        vector<vector<ii>> cs(2, vector<ii>());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%1d", &g[i][j]);
                if (g[i][j] == 1)
                    cs[0].push_back(ii(i, j));
                else if (g[i][j] == 3)
                    cs[1].push_back(ii(i, j));
            }
        vector<int> ds;
        int d;
        for (int i = 0; i < cs[0].size(); i++)
        {
            int dmin = m*m+1;
            for (int j = 0; j < cs[1].size(); j++)
            {
                d = mdist(cs[0][i], cs[1][j]);
                if (d < dmin)
                    dmin = d;
            }
            ds.push_back(dmin);
        }
        printf("%d\n", *max_element(ds.begin(), ds.end()));

    }
    return 0;
}