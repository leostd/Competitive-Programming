#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector < vi > vvi;

vi numbers[1000007];

int main()
{
    //freopen("in", "r", stdin);
    int m, n, num, rep;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        set<int> ns;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            ns.insert(num);
            numbers[num].push_back(i);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &rep, &num);
            if(numbers[num].size() < rep)
                printf("0");
            else
                printf("%d", numbers[num][rep-1]);
            printf("\n");
        }
        for (auto it = ns.begin(); it != ns.end(); ++it)
            numbers[*it].clear();

    }
    return 0;
}
