#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int m,n; // matrix size
int lp; // longest path;
int cp; // current path
vector<string> matrix; // grid
vector<vector<bool>>chk; // visited
int xmov[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int ymov[8] = {1, -1, 0, 0, 1, 1, -1, -1};

void dfs(int i, int j, char c, int ac)
{
    if (i >= 0 && i < m && j >= 0 && j < n && !chk[i][j] && matrix[i][j] == c)
    {
        chk[i][j] = true;
        ac++;
        if (ac > lp)
            lp = ac;
        for (int it = 0; it < 8; it++)
            dfs(i + xmov[it], j + ymov[it], c+1, ac);
    }
}

int main()
{
    int tc = 1;
    while(scanf("%d %d", &m, &n), m || n)
    {
        matrix = vector<string>(m, "");
        chk = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            cin >> matrix[i];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 'A')
                    dfs(i, j, 'A', 0);
        chk.clear();
        printf("Case %d: %d\n", tc++, lp);
        matrix.clear();
        lp = cp = 0;
    }
    return 0;
}