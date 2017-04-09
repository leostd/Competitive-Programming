#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef vector < vi > vvi;

int main()
{
    freopen("EasyProblemFrom.in", "r", stdin);
    vvi numbers;
    int m, n, num, rep;
    vi vp;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        numbers = vvi(n+1, vp);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
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
    }
    return 0;
}
