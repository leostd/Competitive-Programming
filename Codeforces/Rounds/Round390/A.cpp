#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
int k;
vi ns;
vi zs;
vii ps;

bool check(int i)
{
    return (i >= 0 && i < n);
}
int main()
{
    scanf("%d", &n);
    ns = vi(n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ns[i]);
        if (ns[i] == 0)
            zs.push_back(i);
        if (zs.empty())
        {
            printf("YES\n %d", n);
            for (int i = 0; i < n; i++)
                printf("%d %d\n", i+1, i+1);
        }
        else
        {
            if (zs.size() == n)
                printf("NO\n");
            bool flag = true;
            vecctor<bool> bs(n, false);
            for (int i = 0; i < zs.size(); i++)

        }
    }  

    return 0;
}