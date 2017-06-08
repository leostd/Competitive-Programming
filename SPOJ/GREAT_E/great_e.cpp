#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

viii g[100005];
int n, r, m, st, en;
 



int solve(int k) {
    vi dist(n, INF);
    dist[st] = k;
    priority_queue<iii, viii, greater<iii>> pq;
    pq.push(iii(k,st, 0));
    while(!pq.empty()) {
        iii a = pq.top(); pq.pop();
        int w = get<0>(a), d = get<1>(a), b = get<2>(a);
        if (dist[d] < w) continue;
        for (int i = 0; i < g[d].size(); ++i) {
            a = g[d][i];
            int w1 = get<0>(a), d1 = get<1>(a), b1 = get<2>(a);
            int aux = dist[d], aux1 = dist[d1];
            if (dist[d] + w1 < dist[d1] && dist[d] + w1 < b1) {
                dist[d1] = dist[d]+w1;
                pq.push(iii(dist[d1], d1, b1));
            }
        }
    }
    return dist[en];
}

int main() {
    //freopen("in", "r", stdin);
    int t, sc=1;
    char str[100];
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d: ", sc++);
        int s, d, w, b;
        scanf("%d %d %d", &n, &r, &m);
        for (int i = 0; i < n; i++)
            g[i].clear();
        for (int i = 0; i < r; ++i) {
            scanf("%d %d %d %s", &s, &d, &w, &str);
            if (strcmp(str, "INF") == 0)
                b = INF + 100;
            else
                b = atoi(str);
            iii a1 = make_tuple(w,d,b);
            iii a2 = make_tuple(w,s,b);
            g[s].push_back(a1);
            g[d].push_back(a2);
        }
        scanf("%d %d", &st, &en);
        int a = 1, mid, sol = -1;
        b = m;
        while(b > a) {
            mid = (b-a+1)/2 + a;
            d = solve(mid);
            if(d == INF)
                b = mid-1;
            else if (d > sol){
                sol = d;
                a = mid;
            }
        }
        if (sol == -1)
            printf("Primo can't escape\n");
        else
            printf("Primo can escape in %d minute(s)\n", a);
    }
    return 0;
}