#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;
#define inf 8000000

typedef pair<int, int> ii;
map<int, string> parse;
int n, t, s, lferry;;
int cs[2000], sum[2000], memo[10005][2000];
int lid[10005][2000];
ii pre[10005][2000];

int dp(int l, int c)
{
    int r = c == 0 ? lferry : lferry - (sum[c-1] - (lferry - l));  
    if (l < 0 || r < 0 )
        return -1;
    if (c == s)
        return 0;
    if (memo[l][c] != -1)
        return memo[l][c];
    int a = dp(l-cs[c], c+1) + 1; // add to the left lane
    int b = dp(l, c+1) + 1; // implicitly added to the right lane
    memo[l][c] = max(a,b);
    lid[l][c] = (a > b) ? 1 : 2;
    pre[l][c] = (a > b) ? ii(l-cs[c], c+1) : ii(l, c+1);
    return memo[l][c];
}

int main()
{
    parse[2] = "port";
    parse[1] = "starboard";
    bool first = true;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &lferry);
        lferry *= 100;
        s = 0;
        while(scanf("%d", &n), n != 0){
            if (s == 0)
                sum[s] = n;
            else
                sum[s] = sum[s-1] + n;
            cs[s++] = n;
        }
        memset(memo, -1, sizeof(memo));
        memset(lid, -1, sizeof(lid));
        int ans = dp(lferry, 0);
        if (!first)
            cout << "\n";
        else
            first = false;
        printf("%d\n", ans);
        int aux;
        ii p1, p2;
        for (int i = 0; i < ans; i++)
        {
            if (i == 0)
            {
                p1 = ii(lferry, 0);
                aux = lid[lferry][0];
            }
            else
            {
                p1 = pre[p1.first][p1.second];
                aux = lid[p1.first][p1.second];
            }
            cout << parse[aux] << "\n";
        }

    }
    return 0;
}