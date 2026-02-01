#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

typedef long long int lli;

struct jewel {
    int w;
    int v;
    double s;
    int index;
    jewel(int we, int va, int i)
    {
        w = we;
        v = va;
        index = i;
        s = (double) v / (double) w;
    }
};

std::vector<jewel> jewels;

bool comp(jewel a, jewel b)
{
    if (a.s >= 1)
    {
        if (b.s >= 1)
            return a.s > b.s;
        else
            return true;
    }
    else
    {
        if (b.s >= 1)
            return false;
        else
        {
            if (a.w != b.w)
                return a.w < b.w;
            else
                return a.s > b.s;
        }
    }
}

bool comp2(jewel a, jewel b)
{
    return a.s > b.s;
}
int main()
{
    FILE *infile = fopen("k.in", "r");
    FILE *outfile = fopen("k.out", "w");
    int n, k;
    lli a, b;
    fscanf(infile, "%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        fscanf(infile, "%lli %lli", &a, &b);
        jewels.push_back(jewel(b, a, i));
    }
    if (k > 1)
        std::sort(jewels.begin(), jewels.end(), comp);
    else
        std::sort(jewels.begin(), jewels.end(), comp2);
    for (int i = 0; i < k; i++)
    {
        fprintf(outfile, "%d ", jewels[i].index);
    }
    fprintf(outfile, "\n");
    return 0;
}