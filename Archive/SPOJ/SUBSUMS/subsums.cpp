#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

int n;
lli a, b;
vector<lli> ns, n1, n2;

void gsets(int s, int sz, vector<lli>& ss)
{
    lli sum;
    for (int mask = 0; mask < (1 << sz); mask++) // set a bitmask
    {
        sum = 0;
        for (int item = 0; item < sz; item++) // check what item is on and then add it to sum
            if (mask & (1 << item))
                sum += ns[s+item];
        ss.push_back(sum);
    }
}

int main()
{
    unsigned long long r = 0;
    vector<lli>::iterator lo, hi;
    scanf("%d %lli %lli", &n, &a, &b);
    ns = vector<lli>(n, 0);
    for (int i = 0; i < n; i++)
        scanf("%lli", &ns[i]);
    gsets(0, n/2, n1);
    gsets(n/2, n&1?n/2+1:n/2, n2);
    sort(n2.begin(), n2.end());
    for (int i = 0; i < n1.size(); i++)
    {
        lo = lower_bound(n2.begin(), n2.end(), a-n1[i]);
        hi = upper_bound(n2.begin(), n2.end(), b-n1[i]);
        r += (hi - n2.begin()) - (lo - n2.begin());
    }
    cout << r << "\n";
    return 0;
}