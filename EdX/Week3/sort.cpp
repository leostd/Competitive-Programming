#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

typedef long long int lli;
typedef unsigned int ui;
typedef std::pair<int, int> ii;
typedef std::vector<lli> vlli;

FILE *infile;
FILE *outfile;

vlli mymerge(vlli l, vlli r)
{
    vlli res;
    ui a, b, c;
    ui li, ri;
    a = l.size();
    b = r.size();
    c = a + b;
    res = vlli(c, 0);
    li = ri = 0;
    for (int i = 0; i < c; i++)
    {
        if (li < a && ri == b)
            res[i] = l[li++];
        else if (ri < b && li == a)
            res[i] = r[ri++];
        else if (li < a && b > ri && l[li] <= r[ri])
            res[i] = l[li++];
        else if (li < a && b > ri && r[ri] <= l[li])
            res[i] = r[ri++];
    }
    return res;
}

vlli msort(ui a, ui b, vlli numbers, ui li, ui ri)
{
    if (a == b)
    {
        fprintf(outfile, "%u %u %lli %lli\n", li, ri, numbers[a], numbers[b]);
        return numbers;
    }
    else
    {
        ui mid = floor((a+b+1)/2);
        ui aux = floor((li+ri-1)/2);
        vlli lhalf(numbers.begin(), numbers.begin()+mid);
        vlli rhalf(numbers.begin()+mid, numbers.end());
        lhalf = msort(0, mid-1, lhalf, li, aux);
        if ((a+b+1) % 2 == 0)
        {
            rhalf = msort(0, mid-1, rhalf, aux+1, ri);
        }
        else
        {   
            rhalf = msort(0, mid, rhalf, aux+1, ri);
        }
        vlli r = mymerge(lhalf, rhalf);
        fprintf(outfile, "%u %u %lli %lli\n", li, ri, r[a], r[b]);
        return r;
    } 
}

int main()
{
    infile = fopen("sort.in", "r");
    outfile = fopen("sort.out", "w");
    int n;
    fscanf(infile, "%d", &n);
    vlli numbers(n, 0);
    for (int i = 0; i < n; i++)
        fscanf(infile, "%lld", &numbers[i]);
    numbers = msort(0, n-1, numbers, 1, n);
    for (int i = 0; i < n; i++)
        fprintf(outfile, "%lld ", numbers[i]);
    return 0;
}