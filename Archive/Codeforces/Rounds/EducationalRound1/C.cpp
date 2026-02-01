#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1e9
#define PI acos(-1.0)
using namespace std;

typedef long double LD;

LD degToRad(LD d) { return d * PI / 180.0; }
LD radToDeg(LD r) { return r * 180.0 / PI; }

struct point {
    LD x,y;
    point() { x = y = 0.0; }
    point(LD _x, LD _y) : x(_x), y(_y) {}
    bool operator == (const point &other) const {
        return (fabs(x - other.x)) < EPS && (fabs(y - other.y));}
};

struct vec2 {
    LD x,y;
    vec2() {x=y=0;}
    vec2(LD _x, LD _y) : x(_x), y(_y) {}
};

vec2 toVec2(point a, point b){
    return vec2(b.x - a.x, b.y - a.x);
}

LD dot(vec2 a, vec2 b) {
    return (a.x * b.x + a.y * b.y);
}

LD norm_sq(vec2 v) { return v.x * v.x + v.y * v.y; }

LD angle(point a, point o, point b) {
    vec2 oa = toVec2(o, a), ob = toVec2(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}



int main(){
    pair<LD, int> angles[100010];
    point ps[100010];
    int n;
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        //angles[i].first = angle(point(a, b), point(0.0, 0.0), point(1.0, 0.0));
        angles[i].first = atan2(1.0*b, 1.0*a);
        if (angles[i].first < 0) angles[i].first += 2*PI;
        angles[i].second = i;
        ps[i].x = a;
        ps[i].y = b;
    }
    sort(angles, angles+n);
    int u, v;
    LD m = INF, aux;
    for (int i = 1; i < n; i++){
        aux = angles[i].first - angles[i-1].first;
        if (aux < m){
            m = aux;
            u = angles[i-1].second;
            v = angles[i].second;
        }
    }
    aux = angles[0].first + 2*PI - angles[n-1].first;
    //aux = angle(ps[angles[0].second], point(0.0, 0.0), ps[angles[n-1].second]);
    if (aux < m){
        u = angles[0].second;
        v = angles[n-1].second;
    }
    printf("%d %d\n", u+1, v+1);
    return 0;
}