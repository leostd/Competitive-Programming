#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1e9
using namespace std;


struct point {
    double x, y;
    point(){x = y = 0;}
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec2 {
    double x, y;
    vec2() {x = y = 0;}
    vec2(double _x, double _y) : x(_x), y(_y) {}
};

vec2 toVec2(point a, point b){
    return vec2(b.x - a.x, b.y - a.y);
}

double dist(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}

double dot(vec2 a, vec2 b) {return (a.x*b.x + a.y*b.y);}

vec2 scale(vec2 v, double s) {  
    return vec2(v.x * s, v.y * s); 
}

point translate(point p, vec2 v) {   
    return point(p.x + v.x , p.y + v.y); 
}

double norm_sq(vec2 v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c) {
  vec2 ap = toVec2(a, p), ab = toVec2(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                 
  return dist(p, c); 
}

double distToLineSegment(point p, point A, point B, point &c)
{
    vec2 Ap = toVec2(A, p), AB = toVec2(A, B);
	double u = dot(Ap, AB) / norm_sq(AB);
	if (u < 0.0) {
		c = point(A.x, A.y);
		return dist(p, A);
	}
	if (u > 1.0) {
		c = point(B.x, B.y);
		return dist(p, B);
	}
	return distToLine(p, A, B, c);
}

int main ()
{
    //freopen("in", "r", stdin);
    int n;
    point m, pans, paux, p[10007];
    double dans, daux;
    while(scanf("%lf\n%lf\n%d", &m.x, &m.y, &n) != EOF)
    {
        for (int i = 0; i <= n; ++i)
            scanf("%lf\n%lf\n", &p[i].x, &p[i].y);
        pans = point();
        dans = INF;
        for (int i = 0; i < n; ++i)
        {
            daux = distToLineSegment(m, p[i], p[i+1], paux);
            if (daux < dans) {
                dans = daux;
                pans = paux;
            }
        }
        printf("%.4lf\n%.4lf\n", pans.x, pans.y);
    }
    return 0;
} 