#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;

struct edg{
    int x, y, w;
};

edg aristas[2002];
int dist[1002];
int n, m;

void bf(int src)
{
    memset(dist, inf, sizeof(dist));
    dist[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = aristas[j].x;
            int y = aristas[j].y;
            int c = aristas[j].w;
            if (dist[x] != inf && dist[x] + c < dist[y])
                dist[y] = dist[x] + c;
        }
    }
}

int main()
{
    int a, b, c, t;
    scanf("%d", &t);
    while(t--)
    {
        bool flag = false;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &aristas[i].x, &aristas[i].y, &aristas[i].w);
        bf(0);
        for (int i = 0; i < m; i++)
        {
            int x = aristas[i].x;
            int y = aristas[i].y;
            int c = aristas[i].w;
            if (dist[x] != inf && dist[x] + c < dist[y]){
                flag = true;
                break;
            }
        }
        if (flag)
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}