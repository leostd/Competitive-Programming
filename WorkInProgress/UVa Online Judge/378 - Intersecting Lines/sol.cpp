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

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

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
const ld EPS = 1e-9;

//#############################
const int MAXN = 1000005;

struct point { 
    double x, y;
    point() { x = y = 0.0; }                      
    point(double _x, double _y) : x(_x), y(_y) {}        
    bool operator == (const point &other) const {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } 
};

/*  LINEAS - LINES */

/*  Ecuacion general de la recta - General Form 
            ax + by + c = 0
    a y b no son simultaneamente nulos.
    a or b can be zero, but not both at the same time.*/
struct line { 
    double a, b, c; 
    };         

/* Ecuacion simplificada de la recta - Simplified Form 
            mx + b = y
    m representa la pendiente de la recta y b el intercepto o
    punto de corte con el eje y.
    m its the slope and b its the intercept.
*/
struct line2 {
    double m, b;
};

bool areParallel(line l1, line l2) {       
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

/*  SON RECTAS IGUALES? - ARE EQUAL? 
        true <=> parallel(l1, l2) && l1.c == l2.c
        otherwise  => false */
bool areSame(line l1, line l2) {           
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; 
}

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
    } 
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

int main() {
    fastIO(); 
    string ss = "INTERSECTING LINES OUTPUT";
    string se = "END OF OUTPUT";
    string sa[3] = {"POINT", "NONE", "LINE"};
    point p0, p1, p2, p3;
    int t = nxt();

    line l0, l1;

    cout << setprecision(2) << fixed;   
    cout << ss << endl;
    while(t--) {
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        // debug_out(p0, p1, p2, p3);

        pointsToLine(p0, p1, l0);
        pointsToLine(p2, p3, l1);


        if (areSame(l0, l1))
            cout << sa[2] << endl;
        else if (areParallel(l0, l1))
            cout << sa[1] << endl;
        else {
            point p;
            areIntersect(l0, l1, p);            
            cout << sa[0] << " " << p.x << " " << p.y << endl;
        }
    }
    
    cout << se << endl;
        return 0;
}