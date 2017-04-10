#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vit;
typedef pair<vit, vit> bounds;

struct point{
    int x, y;
    bool operator == (const point &other) const {
        return (x == other.x && y == other.y);
    }
};

struct line{
    point a, b;
    int ln;
    bool operator < (const line &other) const{
        return ln < other.ln;
    }
};

typedef vector<line> vl;

bool bomerang(line l, line m)
{
    return (l.a == m.a || l.a == m.b || l.b == m.b || l.b == m.a);
}

int sqr(int x)
{
    return x*x;
}

int t, n;
point ps[2002];
line ls[4000007];

int main()
{
    scanf("%d", &t);
    for (int i=1; i <= t; ++i)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j)
            scanf("%d %d", &ps[j].x, &ps[j].y);
        int cons = 0;
        line a;
        int nlines = 0;
        for (int j = 0; j < n; ++j)
        {
            nlines = 0;
            for (int k = 0; k < n; ++k)
            {
                if (j == k)
                    continue;
                a.a = ps[j];
                a.b = ps[k];
                a.ln = sqr(a.a.x - a.b.x) + sqr(a.a.y - a.b.y);
                ls[nlines++] = a;
            }
            sort(ls, ls+nlines);
            int k = 0;
            while (k < nlines)
            {
                line d = ls[k];
                int l = lower_bound(ls+k, ls+nlines, d) - ls;
                int u = upper_bound(ls+k, ls+nlines, d) - ls;
                int rep = u - l;
                cons += rep * (rep-1) / 2;
                k = u;
            }
        }
        printf("Case #%d: %d\n", i, cons);
    }
    return 0;
}