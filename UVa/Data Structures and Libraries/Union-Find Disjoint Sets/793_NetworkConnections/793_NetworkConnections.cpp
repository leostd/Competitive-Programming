#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

typedef unsigned int ui;

struct dset
{
    ui parent;
    ui drank;
    dset(ui p, ui r)
    {
        parent = p;
        drank = r;
    }
};

typedef vector< dset > vds;

ui ds_find(vds &subsets, ui a)
{
    //Path Compression
    if(subsets[a].parent != a)
        subsets[a].parent = ds_find(subsets, subsets[a].parent);
    return subsets[a].parent;
}

void ds_union(vds &subsets, ui a, ui b)
{
    ui aroot = ds_find(subsets, a);
    ui broot = ds_find(subsets, b);
    if(aroot != broot)
    {
        if(subsets[aroot].drank > subsets[broot].drank)
            subsets[broot].parent = aroot;
        else if(subsets[broot].drank > subsets[aroot].drank)
            subsets[aroot].parent = broot;
        else
        {
            subsets[broot].parent = aroot;
            ++subsets[aroot].drank;
        }
    }
}

void initialize(vds &subsets, int n)
{
    for(int i = 0; i <= n; ++i)
    {
        dset a(i,0);
        subsets.push_back(a);
    }
}
int main()
{
    freopen("NetworkConnections.in", "r", stdin);
    int tc, n;
    vds computers;
    scanf("%d", &tc);
    for(int i = 0; i < tc; ++i)
    {
        scanf("%d\n", &n);
        initialize(computers, n);
        string line;
        int s, u;
        s = u = 0;
        getline(cin, line);
        while(line != "")
        {
            char ch;
            int a, b;
            stringstream sstr(line);
            sstr >> ch >> a >> b;
            if(ch == 'q')
            {
                if(ds_find(computers, a) == ds_find(computers, b))
                    ++s;
                else
                    ++u;
            }
            else if(ch == 'c')
                ds_union(computers, a, b);
            getline(cin, line);
        }
        printf("%d,%d\n\n", s, u);
        computers.clear();
    }
    return 0;
}
