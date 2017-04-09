#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector< vector < ii > > vii;
typedef unsigned int ui;

vii smTranspose(vii sm, int m, int n)
{
    vii smt;
    vector<ii> vp;
    for(int i = 0; i <= n; ++i)
        smt.push_back(vp);
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 0; j < sm[i].size(); ++j)
        {
            int row = sm[i][j].first;
            int col = i;
            int val = sm[i][j].second;
            ii p(i,val);
            smt[row].push_back(p);
        }
    }
    return smt;
}

void printSparseMatrix(vii sm, int m, int n)
{
    printf("%d %d\n", m, n);
    for(int i = 1; i <= m; ++i)
    {
        int r = sm[i].size();
        printf("%d ", r);
        for(int j = 0; j < r; ++j)
        {
            printf("%d ", sm[i][j].first);
        }
        printf("\n");
        if(r != 0)
        {
            for(int j = 0; j < r; ++j)
            {
                printf("%d ", sm[i][j].second);
            }
        }
        printf("\n");
    }
}
int main()
{
    freopen("MatrixTranspose.in", "r", stdin);
    vii sm;
    int n, m,r;
    scanf("%d %d", &m, &n);
    vector<ii> ve;
    sm.push_back(ve);
    for(ui i = 0; i < m; ++i)
    {
        scanf("%d", &r);
        if(r == 0)
        {
            vector<ii> vp;
            sm.push_back(vp);
        }
        else
        {
            vector<ii> vp;
            int col, val;
            for(ui j = 0; j < r; ++j)
            {
                scanf("%d", &col);
                vp.push_back(pair<int, int>(col,0));
            }
            for(ui j = 0; j < r; ++j)
            {
                scanf("%d", &val);
                vp[j].second = val;
            }
            sm.push_back(vp);

        }
    }
    printSparseMatrix(sm, m, n);
    cout << endl;
    vii smt = smTranspose(sm,m,n);
    printSparseMatrix(smt,n,m);
    return 0;
}
