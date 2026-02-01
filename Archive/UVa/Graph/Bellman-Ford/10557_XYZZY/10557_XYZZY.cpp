#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

typedef vector<int> vi;

struct edg{
    int x, y, w;
};

edg aristas[10002];
int dist[1002];
int n, k;
queue<int> q;
vi g[1002];

void bf(int src)
{
    memset(dist, inf, sizeof(dist));
    dist[src] = -100;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int x = aristas[j].x;
            int y = aristas[j].y;
            int c = aristas[j].w;
            // if the energy >= 0, we are death so the node is unreachable
            if (dist[x] != inf && dist[x] + c < dist[y] && dist[x] + c < 0)
                dist[y] = dist[x] + c;
        }
    }
}

bool bfs(){
    bool m[1002];
    memset(m, false, sizeof(m));
    while(!q.empty()){
        int s = q.size();
        for (int i = 0; i < s; i++){
            int a = q.front();
            vi b = g[a];
            q.pop();
            for (int j = 0; j < b.size(); j++)
            {
                int c = b[j];
                if (c == n-1)
                    return true;
                if (!m[c]){
                    q.push(c);
                    m[c] = true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int a, b, c;
    while(scanf("%d", &n), n != -1)
    {
        k = 0;
        fill(g, g+n, vi());
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            for (int j = 0; j < b; j++)
            {
                scanf("%d", &c);
                aristas[k].x = i;
                if (c != 0)
                    aristas[k].y = c-1; 
                else
                    aristas[k].y = c;
                aristas[k++].w = -a; // change sign
                if(c != 0)
                    g[i].push_back(c-1);
                else 
                    g[i].push_back(c);
            }
        }
        bf(0);
        if (dist[n-1] != inf){
            printf("winnable\n");
            continue;
        }
        // find every node in a infinite energy cycle
        for (int i = 0; i < n; i++)
        {
            int x = aristas[i].x;
            int y = aristas[i].y;
            int w = aristas[i].w;
            if (dist[x] != inf && dist[x] + w < dist[y] && dist[x] + w < 0)
                q.push(y);
        }
        bool flag = bfs();
        if (flag)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}