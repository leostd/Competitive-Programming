#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct cup {
    int id, a, m;
};

bool cmp (cup &a, cup &b){ return a.a > b.a; }
bool cmp2 (cup &a, cup &b) { return a.id < b.id; }
int n, w;
cup cs[200];

int main()
{
    //freopen("in", "r", stdin);
    scanf("%d %d", &n, &w);
    int acum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cs[i].a);
        cs[i].id = i;
        cs[i].m = ceil((double)cs[i].a/2);
        acum += cs[i].m;
    }
    if (acum > w)
        printf("-1\n");
    else {
        sort(cs, cs+n, cmp);
        for(int i = 0; i < n; ++i) {
            int rest = cs[i].a - cs[i].m;
            if (rest >= (w - acum) && acum < w)
            {
                cs[i].m += (w - acum);
                acum += (w - acum);
            }
            else if (rest < (w - acum) && acum < w)
            {
                cs[i].m += rest;
                acum += rest;
            }
        }
        if (acum == w)
        {
            sort(cs, cs+n, cmp2);
            for (int i = 0; i < n; i++)
                printf("%d ", cs[i].m);
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}