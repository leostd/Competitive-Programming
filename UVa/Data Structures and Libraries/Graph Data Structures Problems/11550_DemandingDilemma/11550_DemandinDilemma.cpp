#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef vector< int > vi;
typedef vector < vi > vvi;

int main()
{
    freopen("DemandingDilema.in", "r", stdin);
    int tc, n, m, edge;
    bool flag;
    int **im;
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++)
    {
        scanf("%d %d", &n, &m);
        im = new int*[n];
        for(int j = 0; j < n; ++j)
            im[j] = new int[m];
        flag = true;
        for(int j = 0; j < n; ++j)
        {
            int counter = 0;
            for(int k = 0; k < m; ++k)
            {
                scanf("%d", &edge);
                im[j][k] = edge;
                if(edge)
                    ++counter;
                if(counter > 2)
                    flag = false;
            }
        }
        if(flag)
            printf("Yes");
        else
            printf("No");
        printf("\n");
        free(im);
    }
    return 0;
}
