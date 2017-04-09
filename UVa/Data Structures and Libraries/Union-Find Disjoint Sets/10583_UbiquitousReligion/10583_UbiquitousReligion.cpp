#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

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
    if(subsets[a].parent != a)
    {
        subsets[a].parent = ds_find(subsets, subsets[a].parent);
    }
    return subsets[a].parent;
}

void ds_union(vds &subsets, ui a, ui b, ui &ncomp)
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
            subsets[aroot].drank++;
        }
        ncomp--;
    }
}

void initialize(vds &subsets, ui n)
{
    for(int i = 0; i <= n; ++i)
    {
        dset aux(i,0);
        subsets.push_back(aux);
    }
}
int main()
{
    freopen("UbiquitousReligion.in", "r", stdin);
    ui m,n, a, b, ncase = 1;
    while(scanf("%u %u", &n, &m), n != 0 || m != 0)
    {
        vds students;
        initialize(students, n);
        for(int i = 0; i < m; ++i)
        {
            scanf("%u %u", &a, &b);
            ds_union(students, a, b, n);
        }
        printf("Case %u: %u\n", ncase++, n);
        students.clear();
    }
    return 0;
}
