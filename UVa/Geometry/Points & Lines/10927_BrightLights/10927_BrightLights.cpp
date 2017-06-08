#include <bits/stdc++.h>
#define INF 1e9
#define EPS 1e-11
using namespace std;

struct point {
    double x, y;
    point() {x = y = 0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator < (const point &other) const;
};

point O = point();

double dist(point p1, point p2)
{
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

struct vec2 {
    double x, y;
    vec2() {x = y = 0;}
    vec2(double _x, double _y): x(_x), y(_y) {}
};

vec2 toVec2(point p1, point p2) {
    return vec2(p2.x-p1.x, p2.y-p1.y);
}

double dot (vec2 a, vec2 b){
    return (a.x *b.x + a.y*b.y);
}

double norm_sq(vec2 v){
    return (v.x*v.x + v.y*v.y);
}

double angle(point a, point o, point b)
{
    vec2 oa = toVec2(o, a), ob = toVec2(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec2 a, vec2 b)
{
    return a.x * b.y - a.y * b.x;
}

bool ccw (point p, point q, point r){
    return cross(toVec2(p, q), toVec2(p, r)) > 0;
}

bool point::operator<(const point &other) const {
    double ta = angle(*this, O, point(1, 0));
    double oa = angle(other, O, point(1, 0));
    if (fabs(ta-oa) > EPS)
        return ta < oa;
    return dist(*this, O) < dist(other, O);
}

bool comp(point a, point b)
{
    if (fabs(a.x - b.x) < EPS)
        return a.y < b.y;
    return a.x < b.x;
}

pair<point, int> p[100007];

int main()
{
    //freopen("in", "r", stdin);
    int n, ds = 1;
    while(scanf("%d", &n), n)
    {
        vector<point> nv;
        for (int i = 0; i < n; ++i)
            scanf("%lf %lf %d", &p[i].first.x, &p[i].first.y, &p[i].second);
        printf("Data set %d:\n", ds++);
        sort(p, p+n);
        double ca = angle(p[0].first, O, point(INF, 0));
        int maxH = p[0].second;
        for (int i = 1; i < n; ++i)
        {
            double ta = angle(p[i].first, O, point(INF, 0));
            ta *= ccw(p[i].first, O, point(INF, 0))? 1 : -1;
            if (fabs(ta-ca) < EPS)
            {
                if (p[i].second <= maxH)
                    nv.push_back(p[i].first);
                else
                    maxH = p[i].second;
            }
            else
            {
                ca = ta;
                maxH = p[i].second;
            }
        }
        if (nv.empty())
            printf("All the lights are visible.\n");
        else {
            printf("Some lights are not visible:\n");
            sort(nv.begin(), nv.end(), comp);
            for (int i = 0; i < nv.size(); ++i)
            {
                if (i < nv.size()-1)
                    printf("x = %.0lf, y = %.0lf;\n", nv[i].x, nv[i].y);
                else
                    printf("x = %.0lf, y = %.0lf.\n", nv[i].x, nv[i].y);
            }
        }
    }
    return 0;
}