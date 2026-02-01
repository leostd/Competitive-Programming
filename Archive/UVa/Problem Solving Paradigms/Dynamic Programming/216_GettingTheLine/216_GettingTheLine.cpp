#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

double memo[11][1 << 11];
bool check[11][1 << 11];

int ncomputers;
ii  computers[11], tid[11][1 << 11], mintid[11][1 << 11];
double dist[11][11];

double euclidean(ii a, ii b)
{
    int t1 = (b.first - a.first) * (b.first - a.first);
    int t2 = (b.second - a.second) * (b.second - a.second);
    return (double)sqrt(t1 + t2); 
}

double dp(int pos, int bitmask)
{
    if (bitmask == ((1 << (ncomputers))-1))
        return 0;
    if (check[pos][bitmask])
        return memo[pos][bitmask];
    double ans = 200000000.0f;
    for (int nxt = 0; nxt < ncomputers; nxt++)
    {
        if (nxt != pos && !(bitmask & (1 << nxt)))
            if (ans > dist[pos][nxt] + dp(nxt, bitmask | (1 << nxt)))
            {
                ans = dist[pos][nxt] + dp(nxt, bitmask | (1 << nxt));
                tid[pos][bitmask] = ii(pos, nxt);
            }
    }
    check[pos][bitmask] = true;
    return memo[pos][bitmask] = ans;
}

int main()
{
    int tc = 1;
    while(scanf("%d", &ncomputers), ncomputers > 0)
    {
        for (int i = 0; i < ncomputers; i++)
            scanf("%d %d", &computers[i].first, &computers[i].second);
        for (int i = 0; i < ncomputers; i++)
            for (int j = 0; j < ncomputers; j++)
                dist[i][j] = euclidean(computers[i], computers[j]) + 16.0;
        double ans = 200000000.0f;
        ii minp;
        for (int i = 0; i < ncomputers; i++)
        {
            memset(check, 0, sizeof(check));
            if (dp(i, (1 << i)) < ans)
            {
                ans = dp(i, (1 << i));
                memcpy(mintid, tid, sizeof(mintid));
                minp = ii(i, 1 << i);
            }
        }
        printf("**********************************************************\n");
        printf("Network #%d\n", tc++);
        int nxt, pos = minp.first;
        ii a;
        for (int bitmask = minp.second; bitmask < (1 << ncomputers) - 1; bitmask = bitmask | (1 << nxt))
        {
            a = mintid[pos][bitmask];
            nxt = a.second;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", computers[pos].first, computers[pos].second, computers[nxt].first, computers[nxt].second, dist[pos][nxt]);
            pos = nxt;
        }
        printf("Number of feet of cable required is %.2lf.\n", ans);
    }
    return 0;
}