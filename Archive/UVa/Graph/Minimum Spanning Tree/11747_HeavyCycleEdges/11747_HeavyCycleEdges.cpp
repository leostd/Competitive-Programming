#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct edg{
    int x, y;
    long long int w;

    bool operator < (const edg &other) const {
        return w < other.w;
    }
};

class UF{
    public:
        int parent[1005];
        int components;
        UF(int n){
            for (int i = 0; i < n; i++)
                parent[i] = i;
            components = n;
        }
        int find(int x){
            if (parent[x] == x)
                return x;
            else
                return parent[x] = find(parent[x]);
        }
        void Union(int x, int y){
            int xroot, yroot;
            xroot = find(x);
            yroot = find(y);
            if (xroot != yroot)
            {
                parent[yroot] = xroot;
                components--;
            }
        }
};

edg aristas[26000];
long long int ans[1005];
int n, m;

int main()
{
    int a, b, c;
    while(scanf("%d %d", &n, &m), n || m)
    {
        UF uf(n);
        for (int i = 0; i < m; i++)
            scanf("%d %d %lli", &aristas[i].x, &aristas[i].y, &aristas[i].w);
        sort(aristas, aristas+m);
        int k = 0;
        long long int cost = 0;
        for (int i = 0; i < m; ++i)
        {
            a = aristas[i].x;
            b = aristas[i].y;
            if (uf.find(a) == uf.find(b))
                ans[k++] = aristas[i].w;
            else
                uf.Union(a, b);
        }
        if (!k)
            printf("forest\n");
        else
        {
            sort(ans, ans+k);
            for (int i = 0; i < k; i++){
                if (i < k-1)
                    printf("%lli ", ans[i]);
                else
                    printf("%lli", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}