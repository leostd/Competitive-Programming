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

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
#define all(x) (x).begin(), (x).end()
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;

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


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};
int KXMOV[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int KYMOV[8] = {1, -1, 1, -1, 2, 2, -2, -2};

//#############################
const int MAXN = 1000005;
bool check(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}
int bfs(int r0, int c0, int r1, int c1) {
    if (r0 == r1 && c0 == c1)
        return 0;
    bool visited[9][9] = {false};
    memset(visited, 0, sizeof(visited));
    visited[r0][c0] = true;
    iii a = make_tuple(r0,c0,0);
    queue<iii> q;
    q.push(a);
    while(!q.empty()){
        a = q.front();
        q.pop();
        int r, c, m;
        r = get<0>(a);
        c = get<1>(a);
        m = get<2>(a);
        // cout << r << " " << c << " " << m << endl;
        // cout << r1 << " " << c1 << endl;
        for(int i = 0; i < 8; i++) {
            int nr = r + KXMOV[i], nc = c + KYMOV[i];
            if (nr == r1 && nc == c1)
                return m+1;
            if (check(nr, nc) && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push(make_tuple(nr,nc,m+1));
            }
        }
    }
}

int main() {
    string a, b;
    while(cin >> a >> b && (a!= "" && b != "")) {
        int r0,r1,c0,c1;
        c0 = a[0] - 'a', c1 = b[0] - 'a';
        r0 = a[1] - '0'-1, r1 = b[1] - '0'-1;
        int ans = bfs(r0,c0, r1,c1);
        cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves." << endl;
    } 
    return 0;
}