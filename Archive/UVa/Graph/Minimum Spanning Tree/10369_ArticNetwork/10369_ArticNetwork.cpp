#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<int, int> ii;

struct edg{
    int x, y;
    double w;
    bool operator< (const edg &other) const {
        return w < other.w;
    }
};

class UF{
public:
    int components;
    int P[505];
    UF(int n){
        components = n;
        for (int i = 0; i < n; i++)
            P[i] = i;
    }
    int Find(int x)
    {
        if (x != P[x])
            return P[x] = Find(P[x]);
        return x;
    }
    int Union(int x, int y)
    {
        int xroot, yroot;
        xroot = Find(x);
        yroot = Find(y);
        if (xroot != yroot)
        {
            components--;
            P[yroot] = xroot;
        }
    }
};

int s, p;
edg aristas[260000];
ii points[505];
int ans[505];
bool sat[505];

bool comp(int a, int b)
{
    return aristas[a].w > aristas[b].w;
}



int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &s, &p);
        UF uf(p);
        memset(sat, false, sizeof(sat));
        for (int i = 0; i < p; i++)
            scanf("%d %d", &points[i].first, &points[i].second);
        int k = 0;
        for (int i = 0; i < p; i++)
            for (int j = i+1; j < p; j++)
                if (i != j)
                {
                    aristas[k].x = i;
                    aristas[k].y = j;
                    double a, b;
                    ii c, d;
                    a = points[i].first - points[j].first;
                    b = points[i].second - points[j].second;
                    aristas[k++].w = hypot(a, b);
                }
        sort(aristas, aristas+k);
        double cost = 0;
        int l = 0, i;
        for (i = 0; i < k && uf.components > max(1, s); i++)
        {
            int a, b;
            a = aristas[i].x;
            b = aristas[i].y;
            if (uf.Find(a) == uf.Find(b))
                continue;
            uf.Union(a, b);
            cost += aristas[i].w;
            ans[l++] = i;
        }
        printf("%.2lf\n", aristas[i-1].w);
    }
    return 0;
}