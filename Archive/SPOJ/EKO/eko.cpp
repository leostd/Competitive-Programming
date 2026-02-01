#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int li;

int n;
li m;
vector<li> woods;

bool f(li x)
{
    li wood = 0;
    for (int i = 0; i < n; i++)
        if (woods[i] >= x)
            wood += woods[i] - x;   
    return wood >= m;
}

int main()
{
    scanf("%d %lli", &n, &m);
    woods = vector<li>(n, 0);
    for (int i = 0; i < n; i++)
        scanf("%lli", &woods[i]);
    sort(woods.begin(), woods.end());
    li hi = 2e9 + 1, lo = 1, mid;
    while(hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (f(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (f(hi))
        printf("%lli\n", hi);
    else
        printf("%lli\n", lo); 
    return 0;
}