#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;

int main()
{
    int t, a, b;
    scanf("%d", &t);
    int sc = 1;
    while(t--)
    {
        map<int, set<int>> stds; 
        bool possible = true;
        scanf("%d %d", &a, &b);
        int x, y;
        for (int i = 0; i < b; i++)
        {
            scanf("%d %d", &x, &y);
            if (stds[x].count(y))
                possible = false;
            else
                stds[x].insert(y);
        }
        if (possible)
            printf("Scenario #%d: possible\n", sc);
        else
            printf("Scenario #%d: impossible\n", sc);        
        sc++;
    }   
    return 0;
}