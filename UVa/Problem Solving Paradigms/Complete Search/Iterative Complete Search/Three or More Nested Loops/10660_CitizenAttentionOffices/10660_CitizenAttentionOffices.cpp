#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
struct area{
    int r, c, p;
};
int main() {
    //freopen("in", "r", stdin);
    int t, pos[5], s, smin, pmin, dist[25][25];
    area ps[25];
    scanf("%d", &t);
    ii a, b;
    for (int i = 0; i < 25; ++i) {
        a.first = i/5;
        a.second = i%5;
        for (int j = 0; j < 25; ++j) {
            b.first = j/5;
            b.second = j%5;
            dist[i][j] = abs(a.first-b.first) + abs(a.second-b.second);
        }
    }
    while(t--){
        int a,b,c,p;
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) 
            scanf("%d %d %d", &ps[i].r, &ps[i].c, &ps[i].p);
        smin = 0x3f3f3f3f;
        for (int i = 0; i < 25-4; ++i) {
            for (int j = i+1; j < 25-3; ++j) {
                for (int k = j+1; k < 25-2; ++k) {
                    for (int l = k+1; l < 25-1; ++l) {
                        for (int m = l+1; m < 25; ++m) {
                            s = 0;
                            for (int n = 0; n < p; ++n){
                                a = ps[n].r;
                                b = ps[n].c;
                                c = a*5+b;
                                pmin = min(min(dist[c][i], min(dist[c][j], min(dist[c][k], dist[c][l]))), dist[c][m]);
                                s += pmin*ps[n].p;
                            }
                            if (s < smin) {
                                smin = s;
                                pos[0] = i;
                                pos[1] = j;
                                pos[2] = k;
                                pos[3] = l;
                                pos[4] = m;
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d\n", pos[0], pos[1], pos[2], pos[3], pos[4]);
    }
    return 0;
}