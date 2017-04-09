#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("snowmen.in");
    std::ofstream cout("snowmen.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif

#include <stdio.h>

typedef long long int lli;

int main()
{
    lli *top, *rest, *mass, accum = 0;
    int n;
    int t, m;
    FILE *infile = fopen("snowmen.in", "r");
    FILE *outfile = fopen("snowmen.out", "w");
    fscanf(infile, "%d", &n);
    top = new lli[n+1];
    rest = new lli[n+1];
    mass = new lli[n+1];
    top[0] = rest[0] = mass[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        fscanf(infile, "%d %d", &t, &m);
        if (m != 0)
        {
            top[i] = m;
            rest[i] = t;
            mass[i] = mass[t] + m;
        }
        else
        {
            top[i] = top[rest[t]];
            rest[i] = rest[rest[t]];
            mass[i] = mass[rest[t]];
        }
        accum += mass[i];
    }
    fprintf(outfile, "%lld", accum);
    return 0;
}