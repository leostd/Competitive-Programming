#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct Lamp {
    int x, y;
    int vl, vu; // vertical bounds
    int hl, hu; // horizontal bounds
    int t, f;
};

int n, r, l, k;
Lamp ls[1002];
vi g[2002], gt[2002], ord;
bool directions[2002], vis[2002], flag = false;
bool mark[2002];

bool conflict(int a, int b, int v)
{
    if (v)
    {
        bool ab = (ls[a].vl >= ls[b].vl && ls[a].vl <= ls[b].vu) || (ls[a].vu >= ls[b].vl && ls[a].vu <= ls[b].vu);
        return ab;
    }
    else
    {
        bool ab = (ls[a].hl >= ls[b].hl && ls[a].hl <= ls[b].hu) || (ls[a].hu >= ls[b].hl && ls[a].hu <= ls[b].hu);
        return ab;
    }
}

void buildImplicationGraph()
{
    for (int i = 0; i < l; ++i)
    {
        for (int j = i+1; j < l; ++j)
        {
            if (ls[i].y == ls[j].y && conflict(i, j, 1) && !mark[j]) // add (!i v !j)
            {
                g[ls[i].t].push_back(ls[j].f);
                g[ls[j].t].push_back(ls[i].f);
                gt[ls[j].f].push_back(ls[i].t);
                gt[ls[i].f].push_back(ls[j].t);
            }
            if (ls[i].x == ls[j].x && conflict(i, j, 0) && !mark[j]) // add (i v j)
            {
                g[ls[i].f].push_back(ls[j].t);
                g[ls[j].f].push_back(ls[i].t);
                gt[ls[j].t].push_back(ls[i].f);
                gt[ls[i].t].push_back(ls[j].f);
            }
        }
        mark[i] = true;
    }
}
void dfs(int s, int it)
{
    if (flag)
        return;
    vis[s] = true;
    vi al = it == 2 ? gt[s] : g[s];
    if (it == 2)
        directions[s] = true;
    if (it == 2 && directions[s] & directions[s^1])
    {
        flag = true; // can't satisfy
        return;
    }
    for (int i = 0; i < al.size(); ++i)
    {
        if (!vis[al[i]])
            dfs(al[i], it);
    }
    if (it == 1)
        ord.push_back(s);
    if (it == 2)
        directions[s] = false;
}

int main()
{
    k = 0;
    scanf("%d %d %d", &n, &r, &l);
    for (int i = 0; i < l; i++)
    {
        scanf("%d %d", &ls[i].x, &ls[i].y);
        //ls[i].x--; ls[i].y--;
        ls[i].vl = (ls[i].x - r >= 1 ? ls[i].x - r : 1);
        ls[i].vu = (ls[i].x + r < n ? ls[i].x + r : n);
        ls[i].hl = (ls[i].y - r >= 1 ? ls[i].y - r : 1);
        ls[i].hu = (ls[i].y + r < n ? ls[i].y + r : n);
        ls[i].t = k++;
        ls[i].f = k++;
    }
    memset(mark, false, sizeof(mark));
    buildImplicationGraph();
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < k; ++i)
    {
        if (!vis[i])
            dfs(i, 1);
    }
    memset(vis, false, sizeof(vis));
    for (int i = ord.size()-1; i >= 0; --i)
    {
        if (!vis[ord[i]])
            dfs(ord[i], 2);
    }
    if (!flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}