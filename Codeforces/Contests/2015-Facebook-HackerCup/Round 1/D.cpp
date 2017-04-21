#include <bits/stdc++.h>
#define MAXN 200005
#define MAXC 12
using namespace std;

typedef vector<int> vi;
int memo[MAXN][MAXC], n, t;
vi g[MAXN];

int dp(int cur, int col)
{
    int &best = memo[cur][col];
    if (best != -1) return best;
    int ans = col;
    
    vi &child = g[cur];
    for (int i = 0; i < child.size(); ++i){
        int aux = 0x3f3f3f3f;
        for (int j = 1; j < MAXC; ++j){
            if (j == col) continue;
            aux = min(dp(child[i], j), aux);
        }
        ans += aux;
    }
    return best = ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int a;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d", &n);
        for (int j = 0; j <= n; ++j)
            g[j].clear();
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a);
            g[a].push_back(j);
        }
        memset(memo, -1, sizeof(memo));
        int ans = 0x3f3f3f3f;
        for (int j = 1; j < MAXC; ++j)
            ans = min(dp(1,j), ans);
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}