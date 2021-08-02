#pragma GCC diagnostic ignored "-Wunused-const-variable"

#ifdef MAC
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#else
#include <bits/stdc++.h>
#endif
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define fst first
#define snd second
#define endl "\n"
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;
 
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return a / gcd (a, b) * b; }
template<class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }
 
string to_string(string s) {
    return '"' + s + '"';
}
    
string to_string(const char* s) {
    return to_string((string) s);
}
    
string to_string(bool b) {
    return (b ? "true" : "false");
}
    
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
    
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
void dbg() { cout << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T) {
    cout << " " << to_string(H);
    dbg(T...);
}
 
#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
void fastIO() {
    cin.sync_with_stdio(false);
    cin.tie(0);
}
 
template<typename T>
vector<T> make_unique(vector<T> v) {
    sort(all(v));
    return v.resize(unique(all(v)) - v.begin());
}
 
int nxt() {
    int x;
    cin >> x;
    return x;
}
 
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int dxKn[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int dyKn[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
const int dxK[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyK[8] = {1, -1, 0, 0, 1, -1, 1, -1};
 
const int MOD = int(1e9) + 7;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-7;
 
//#############################
const int MAXN = 1000005;

bool isEqual(double a, double b) {
    return abs(a-b) < EPS;
}

struct Point {
    double x, y;
    Point(){
        x = y = 0.0;
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    } 
};

string to_string(Point p) {
    return to_string(mp(p.x, p.y));
}

struct Vec {
    double i, j;
    Vec(double _i, double _j) {
        i = _i;
        j = _j;
    }
};

double sqrEuclideanDistance(Point a, Point b) {
    double x = a.x - b.x;
    double y = a.y - b.y;

    return sqr(x) + sqr(y);
}

double triangleArea(Point a, Point b, Point c) {
    double num = (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);

    return abs(num)/2.0;
}

struct Circle {
    Point center;
    double radius;

    Circle(Point _center, double _radius) {
        center = _center;
        radius = _radius;
    }

    bool isInside(Point p) {
        double dist = sqrEuclideanDistance(p, center);

        return dist-sqr(radius) < EPS;
    }
};

struct Triangle {
    Point a;
    Point b;
    Point c;

    Triangle(Point _a, Point _b, Point _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    bool isInside(Point p) {
        double aa = area();
        dbg(aa);
        double t1 = Triangle(a,b,p).area();
        dbg(t1);
        double t2 = Triangle(a,c,p).area();
        dbg(t2);
        double t3 = Triangle(b,c,p).area();
        dbg(t3);
        return isEqual(aa, t1 + t2 + t3);
    }

    double area() {
        return abs((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x)) / 2.0;
    }
};

struct Square {
    Point a,b,c,d;

    Square(Point p1, Point p2, Point p3, Point p4) {
        a = p1;
        b = p2;
        c = p3;
        d = p4;
    }

    Square(Point p1, Point p3) {
        a = p1;
        c = p3;

        Point center((a.x+c.x)/2.0, (a.y+c.y)/2.0);
        dbg(center);

        double di = a.x - center.x;
        double dj = a.y - center.y;

        double pi = -dj;
        double pj = di;

        // pi * di + pj * dj == 0 <--> perpendicular
        b = Point(center.x+pi, center.y+pj);
        d = Point(center.x-pi, center.y-pj);
    }

    bool isInside(Point p) {
        return Triangle(a,c,b).isInside(p) || Triangle(a,c,d).isInside(p);
    }
};
 
int main() {
    fastIO(); 
    int n, m;
    cin >> n >> m;
    
    double cx, cy, r;
    cin >> cy >> cx >> r;
    Circle circle(Point(cx, cy), r);

    double p1x, p1y, p2x, p2y;
    cin >> p1x >> p1y >> p2x >> p2y;
    Square square(Point(p1y, p1x), Point(p2y, p2x));
    dbg(square.b);
    dbg(square.d);
    dbg(square.a);
    dbg(square.c);
    vector<string> g(m, string(n, '.'));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            Point p(i, j);
            dbg(p);
            if (circle.isInside(p) || square.isInside(p)) {
                g[i][j] = '#';
            } else
                g[i][j] = '.';
        }
    }

    forn(i, m){
        forn(j, n){
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}

/*
    RECALL CORNER CASES - e.g. n = 1, n = 0
    WRITE SOME STUFF

    think first, always - 
    1. concretely
    2. graphically 
    3. abstractly
    4. algebraically

    Checklist:
    - I/O make sense?   - Exclusion/inclusion           - Is a known sequence?
    - Reverse           - Brute force approach          - DP
    - Sort input        - Greedy approach
    - Check diagonals   - Divide and Conquer approach
*/