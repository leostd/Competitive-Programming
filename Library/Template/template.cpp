// I/O
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

// String manipulation and memset
#include <string>
#include <string.h>

// Data Structures
#include <vector>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
#include <array>
#include <list>
#include <forward_list>

// Utility
#include <algorithm>
#include <utility>
#include <limits>
#include <functional>
#include <numeric>
#include <math.h>
#include <assert.h>
#include <time.h>

// Defines
#define SCD1(t) scanf("%d",&t)
#define SCD2(a, b) scanf("%d %d",&a, &b)
#define SCD3(a, b, c) scanf("%d %d %d",&a, &b, &c)
#define SCD4(a, b, c, d) scanf("%d %d %d %d",&a, &b, &c, &d)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sqr(x) x*x
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define SORT(a) sort(all(a))
#define SORT(a,n) sort(a, a+n)
#define PTD1(a) printf("%d", a)
#define PTD2(a, b) printf("%d %d", a,b)
#define PTD3(a, b, c) printf("%d %d %d", a,b,c)
#define PTD2(a, b, c, d) printf("%d %d %d %d", a,b,c,d)
const double pi=acos(-1.0); // alternative PI const

using namespace std;

// typedefs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef long long ll;
typedef long int li;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef map<int, int> mii;
typedef set<int> si;
typedef multiset<int> msi;

// basic operations
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y;}
template<typename T, typename U> inline void amax(T &x, U y) { if (y > x) x = y;}

int main()
{
    return 0;
}