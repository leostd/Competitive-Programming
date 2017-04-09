#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef unsigned int ui;

struct ds
{
    ui parent;
    ui drank;
    bool infected;
    ds(ui p, ui r, bool b)
    {
        parent = p;
        drank = r;
        infected = b;
    }
};

typedef vector< ds > vds;

ui ninfected;

ui ds_find(vds &subsets, ui a)
{
    if(subsets[a].parent != a)
        subsets[a].parent = ds_find(subsets, subsets[a].parent);
    if(subsets[subsets[a].parent].infected != subsets[a].infected)
    {
        subsets[a].infected = true;
        ninfected++;
    }

    return subsets[a].parent;
}

void ds_union(vds &subsets, ui a, ui b)
{
    ui aroot = ds_find(subsets,a);
    ui broot = ds_find(subsets, b);
    if(aroot != broot)
    {
        ds as(0,0,false), bs(0,0,false);
        as = subsets[aroot];
        bs = subsets[broot];
        if(as.drank > bs.drank)
            subsets[broot].parent = aroot;
        else if(bs.drank > as.drank)
            subsets[aroot].parent = broot;
        else
        {
            subsets[broot].parent = aroot;
            subsets[aroot].drank++;
        }
        if(as.infected || bs.infected)
        {
            subsets[aroot].infected = subsets[broot].infected = true;
            ninfected++;
        }
    }
}

void initialize(vds &subsets, ui n)
{
    ds aux(0,0,true);
    subsets.push_back(aux);
    for(int i = 1; i < n; i++)
    {
        aux  = ds(i,0,false);
        subsets.push_back(aux);
    }
}

int main()
{
    freopen("TheSuspects.in", "r", stdin);
    ui m, n;
    scanf("%ui", &n);
    scanf("%ui", &m);
    while(n != 0 || m != 0)
    {
        vds students;
        ninfected = 1;
        initialize(students, n);
        ui a, b, c;
        for(int h = 0; h < m; ++h)
        {
            scanf("%ui", &a);
            scanf("%ui", &b);
            for(ui i = 1; i < a; i++)
            {
                scanf("%ui", &c);
                ds_union(students, b, c);
            }
        }
        printf("%d\n", ninfected);
        students.clear();
        scanf("%ui", &n);
        scanf("%ui", &m);
    }
    return 0;
}
