#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

typedef long long int lli;
typedef std::vector<lli> vlli;

vlli friends;
lli m;
lli k;
int n;

bool can(lli num)
{
    lli count = k; // blank planks
    lli prev = 0;  // how many blank planks previously painted
    lli aux;       // how many blank planks will be painted
    lli needed; 
    for (int i = 1; i <= n; i++)
    {
        aux = friends[i] - prev; // repaint the prev planks, from the start and the rest are blanks
        if (aux < num)   // more blank planks needed
        {
            needed = num - aux;
            aux += needed;
        }
        count -= aux;   // painting aux blank planks
        prev = k - count;
        if (count < 0)
            return false;
    }
    return true;
}

lli bs(lli l, lli r)
{
    lli s, e, mid;
    s = l;
    e = r;
    if (can(e))
        return e;
    else if (!can(s))
        return 0;
    while(e - s > 1)
    {
        mid = s + (e - s) / 2;
        if (can(mid))
            s = mid;
        else
            e = mid;
    }
    return s;
}

int main()
{
    FILE *infile = fopen("fence.in", "r");
    FILE *outfile = fopen("fence.out", "w");

    fscanf(infile, "%d %lli", &n, &k);
    friends = vlli(n+1, 0);
    for (int i = 1; i <= n; i++)
        fscanf(infile, "%lli", &friends[i]);
    std::sort(friends.begin(), friends.end());
    m = friends[1];
    lli r  = bs(1, m);
    fprintf(outfile, "%lli", r);
    return 0;
}