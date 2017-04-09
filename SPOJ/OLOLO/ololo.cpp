#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef unsigned int lli;

map<lli, int> ns;
set<lli> ot;

int main()
{
    int n;
    lli a, result = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%u", &a);
        result = result ^ a;
    }
    printf("%u\n", result);
    return 0;
}
