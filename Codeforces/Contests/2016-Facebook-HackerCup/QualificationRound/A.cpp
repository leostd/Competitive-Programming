#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    bool operator == (const point &other) const {
        return (x == other.x && y == other.y);
    }
};

struct line{
    point a, b;
    int ln;
    bool operator <(const line &other) const {
        return ln < other.ln;
    }
};

typedef vector<line> vl;

bool boomerang(line l, line m)
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
int mp[500000000];

int main()
{
    scanf("%d", &t);
    for (int i=1; i <= t; ++i)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j)
            scanf("%d %d", &ps[j].x, &ps[j].y);
        int cons = 0;
        int nlines = 0;
        line a;
        for (int j = 0; j < n; ++j)
        {
            for (int k = j+1; k < n; ++k)
            {
                a.a = ps[j];
                a.b = ps[k];
                a.ln = sqr(a.a.x - a.b.x) + sqr(a.a.y - a.b.y);
                ls[nlines++] = a; 
            }
        }
        sort(ls, ls+nlines);
        for (int j = 0; j < nlines; ++j)
        {
            for (int k = j+1; k < nlines; ++k)
            {
                if (ls[j].ln < ls[k].ln)
                    break;
                if (ls[j].ln == ls[k].ln && boomerang(ls[j], ls[k]))
                    cons++;
            }
        }
        printf("Case #%d: %d\n", i, cons);
    }
    return 0;
}