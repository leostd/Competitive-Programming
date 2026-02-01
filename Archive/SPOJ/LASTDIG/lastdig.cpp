#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
int t;
int a;
lli b;
scanf("%d", &t);
while(t--)
{
scanf("%d %lli", &a, &b);
if (b==0)
{
    printf("1\n");
    continue;
}
set<int> lds;
vector<int> ds;
int ld = a % 10;
lli idx = 2;
ds.push_back(ld);
lds.insert(ld);
ld = (ld * a) % 10;
while(!lds.count(ld) && idx < b)
{
    idx++;
    lds.insert(ld);
    ds.push_back(ld);
    ld = (ld * a) % 10;
}
if (idx == b)
{
    printf("%d\n", ld);
    continue;
}
idx = b % ds.size();
if (idx == 0)
    printf("%d\n", ds[ds.size()-1]);
else
    printf("%d\n", ds[idx-1]);
}
return 0;
}