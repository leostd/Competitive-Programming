#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    double x, y;
    bool operator <(const point &other) const {
        return x > other.x;
    }
};

struct line{
    double a,b,c;
};

double dist(point a, point b)
{
    return hypot((a.x-b.x), (a.y-b.y));
}

void points2Line(point p1, point p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS) {              
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
    } 
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

double getX(double y, line l)
{
    return (-(y+l.c)/(l.a));
}

int tc;
point ps[101];

int main()
{
    //freopen("in", "r", stdin);
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf %lf", &ps[i].x, &ps[i].y);
        sort(ps, ps+n);
        double acum = dist(ps[0], ps[1]);
        int maxh = ps[1].y;
        for (int i = 1; i < n-1; ++i)
        {
            if (ps[i+1].y <= maxh)
                continue;
            line l;
            point p;
            points2Line(ps[i], ps[i+1], l);
            double x = getX(maxh, l);
            p.x = x;
            p.y = maxh;
            acum += dist(ps[i+1], p);
            maxh = ps[i+1].y;
        }
        printf("%.2lf\n", acum);
    }
    return 0;
}