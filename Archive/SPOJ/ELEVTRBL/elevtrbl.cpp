#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;
int f, s, g, u, d;
int ans = 0;
vector<int> v; // visited/counter of pressed buttons

void bfs()
{
    int a, uf, df;
    v = vector<int>(f+1, 0); // indexing from 1
    queue<int> q;
    if (s == g)
        return; // 0 pressed buttons
    q.push(s);
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        uf = a + u;
        df = a - d;
        if (df >= 1 && v[df] == 0 && df != s) // not visited yet
        {
            v[df] = v[a] + 1;
            q.push(df);
        } 
        if (uf <= f && v[uf] == 0 && uf != s) // not visited yet
        {
            v[uf] = (v[a] + 1);
            q.push(uf);
        }
        if (v[g] > 0) // done
        {
            ans = v[g];
            return;
        }
    }
    if (!v[g])
        ans = -1;
}
int main()
{
    
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    bfs();
    if (ans >= 0)
        printf("%d\n", ans);
    else
        printf("use the stairs\n");
    return 0;
}