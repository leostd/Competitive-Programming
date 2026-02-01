#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define lsb(x) ((-x)&(x))
#define fst first
#define snd second
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ld, ld, ld> ddd;

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

template<typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) +  ", " + to_string(get<2>(t)) + ")"; }

template<typename A>
string to_string(priority_queue<A> pq) {
    bool first = true;
    string res = "{";
    int sz = pq.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}

template<typename A>
string to_string(queue<A> q) {
    bool first = true;
    string res = "{";
    int sz = q.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;

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
 
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
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

const int NCOL = 150, NROW = 200;
//const int NCOL = 16, NROW = 12;
int n, m; // sizes
vector<string> g; //graph, grid
vector<string> steps;
vector<pii> fl, cfl;

int getFace(int cr, int cc);

ll getAns(ll row, ll col, ll facing) {
    row++, col++;
    //col -= fl[row-1].fst;
    return 1000*row + 4*col + facing;
}

void readGrid() {
    g.clear();
    g.assign(NROW, "");
    string ln;
    forn(i, NROW) {
        getline(cin, ln);
        g[i] = ln;
    }
    dbg(g.size());
    fl.assign(NROW, mp(0,0));
    cfl.assign(NCOL, mp(0,0));
    forn(i, NROW) {
        fl[i] = mp(-1, -1);
        bool fill = false;
        forn(j, NCOL) {
            if (fill) {
                g[i].pb('\0');
                continue;
            }
            if (!isspace(g[i][j]) && (g[i][j] == '.' || g[i][j] == '#')) {
                if (fl[i].fst == -1) fl[i].fst = j;
                fl[i].snd = j;
            } else {
                if (g[i][j] == '\0') {
                    fill = true;
                }
            }
        }
    }
    
    string aux;
    forn(i, NCOL) {
        cfl[i] = mp(-1, -1);
        forn(j, NROW) {
            if ((g[j][i] == '.' || g[j][i] == '#')) {
                if (i == 79) aux.pb(g[j][i]);
                if (cfl[i].fst == -1) cfl[i].fst = j;
                cfl[i].snd = j;
            } else {
                if (g[j][i] == '\0') {
                    dbg("breaking!", j, i);

                    break;
                }
            }
        }
    }
    forn(i, NROW) {
        forn(j, NCOL) {
            cout << g[i][j];
        }
        cout << endl;
    }
}

void readSteps() {
    cin.ignore();
    string ln;
    getline(cin, ln);
    int sz = ln.size();
    string cur;
    forn(i, sz) {
        if (isdigit(ln[i]))
            cur.pb(ln[i]);
        else if (isalpha(ln[i])) {
            if (!cur.empty())
                steps.pb(cur);
            cur.clear();
            cur.pb(ln[i]);
            steps.pb(cur);
            cur.clear();
        }
    }
    if (!cur.empty()) steps.pb(cur);
    dbg(steps);
}

void setNewPos(int &cr, int &cc, int &f) {
    dbg("wrapping");
    int face = getFace(cr, cc);
    int pr = cr, pc = cc, pf = f;
    bool changed = false;

    if (face == 1) {
        if (f == 2) {
            f = 0;
            int diff = cr;
            cc = 0, cr = 149 - diff;
            changed = true;
        } 

        if (f == 3) {
            f = 0;
            int diff = cc - 50;
            cc = 0, cr = 150 + diff;
            changed = true;
        }

    }

    if (face == 2) {
        if (f == 0) {
            f = 2;
            int diff = cr;
            cr = 149 - diff, cc = 99;
            changed = true;
        }

        if (f == 1) {
            f = 2;
            int diff = cc - 100;
            cr = 50 + diff, cc = 99;
            changed = true;

        }

        if (f == 3) {
            dbg("here");
            f = 3;
            int diff = cc - 100;
            cr = 199, cc = diff;
            dbg(cr, cc);
            changed = true;
        }

    }

    if (face == 3) {
        if (f == 2) {
            f = 1;
            int diff = cr - 50;
            cr = 100, cc = diff;
            changed = true;
        }
        if (f == 0) {
            f = 3;
            int diff = cr - 50;
            cr = 49, cc = 100 + diff;
            changed = true;
        }

    }

    if (face == 4) {
        if (f == 2) {
            f = 0;
            int diff = cr - 100;
            cr = 49 - diff, cc = 50;
            changed = true;

        }

        if (f == 3) {
            f = 0;
            int diff = cc;
            cr = 50+diff, cc = 50;
            changed = true;
        }
    }

    if (face == 5) {
        if (f == 0) {
            f = 2;
            int diff = cr - 100;
            cr = 49 - diff, cc = 149;
            changed = true;
        }

        if (f == 1) {
            f = 2;
            int diff = cc - 50;
            cr = 150 + diff, cc = 49;
            changed = true;
        }

    }

    if (face == 6) {
        if (f == 0) {
            f = 3;
            int diff = cr - 150;
            cc = 50 + diff, cr = 149;
            changed = true;
        }

        if (f == 1) {
            f = 1;
            int diff = cc;
            cc = 100 + diff, cr = 0;
            changed = true;
        }

        if (f == 2) {
            f = 1;
            int diff = cr - 150;
            cc = 50 + diff, cr = 0;
            changed = true;
        }
    }

    if (g[cr][cc] == '#') {
        cr = pr, cc = pc, f = pf;
    }

    if (!changed) {
        cout << "This must be an error!" << endl;
        dbg(cr, cc, f);
    }
}

//void setNewPos(int &cr, int &cc, int &f) {
//    int face = getFace(cr, cc);
//    int pr = cr, pc = cc, pf = f;
//    if (face == 1) {
//        if (f == 2) {
//            int diff = cr;
//            cr = 4, cc = 4 + diff, f = 1;
//        } else if (f == 0) {
//            int diff = cr;
//            cr = 8 + diff, cc = 15, f = 2; 
//        } else if (f == 3) {
//            int diff = cc - 8;
//            cr = 4, cc =  diff, f = 1;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (face == 2) {
//        if (f == 3) {
//            int diff = cc;
//            cr = 0, cc = 8 + diff, f = 1;
//        } else if (f == 2) {
//            int diff = cr - 4;
//            cr = 11, cc = 12 + diff, f = 3;
//
//        } else if (f == 1) {
//            int diff = cc;
//            cr = 11, cc = 8 + diff, f = 3;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (face == 3) {
//        if (f == 3) {
//            int diff = cc - 4;
//            cr = diff, cc = 8, f = 0;
//        } else if (f == 1) {
//            int diff = cc - 4;
//            cr = 11 - diff, cc = 8, f = 0;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (face == 4) {
//        if (f == 0) {
//            int diff = cr - 4;
//            cr = 8, cc = 15 - diff, f = 1;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (face == 5) {
//        if (f == 1) {
//            int diff = cc - 8;
//            cc = 3 - diff, cr = 7, f = 3;
//            dbg("here!", cr, cc, f);
//        } else if (f == 2) {
//            int diff = cr - 8;
//            cr = 7, cc = 11-diff, f = 3;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (face == 6) {
//        if (f == 0) {
//            int diff = cr - 8;
//            cr = 3 - diff, cc = 11, f = 2;
//        } else if (f == 1) {
//            int diff = cc - 12;
//            f = 1, cr = 7 - diff, cc = 4;
//        } else if (f == 3) {
//            int diff = cc - 12;
//            f = 2, cr = 7 - diff, cc = 11;
//        } else {
//            dbg(cr, cc, f);
//            cout << "This is an error" << endl;
//        }
//    }
//
//    if (g[cr][cc] == '#') {
//        cr = pr, cc = pc, f = pf;
//    }
//}

void move2(int st, int &cr, int &cc, int &f) {
    cout << "Start moving: " << st << "steps " << cr << " " << cc << " facing: " << f << endl;
    dbg(fl[cr], cfl[cc]);
    forn(i, st) {
        int nr = cr + dx[f];
        int nc = cc + dy[f];
        bool wrap = ((f == 0 || f == 2) && nc == fl[cr].fst-1) || ((f == 0 || f == 2) && nc == fl[cr].snd+1) || ((f == 1 || f == 3) && nr == cfl[cc].fst-1);
        wrap = wrap || ((f == 1 || f == 3) && nr == cfl[cc].snd+1);
        if (wrap) setNewPos(cr, cc, f);
        //dbg(nr, nc);
        
        if (!wrap && g[nr][nc] == '.')
            cr = nr, cc = nc;
        dbg(cr, cc, f);
    }
    cout << "Ended at: " << cr << " " << cc << endl;
}

void move(int st, int &cr, int &cc, int f) {
    cout << "Start moving: " << st << "steps " << cr << " " << cc << " facing: " << f << endl;
    dbg(fl[cr], cfl[cc]);
    forn(i, st) {
        int nr = cr + dx[f];
        int nc = cc + dy[f];
        if ((f == 0 || f == 2) && nc == fl[cr].fst-1) nc = fl[cr].snd;
        if ((f == 0 || f == 2) && nc == fl[cr].snd+1) nc = fl[cr].fst;
        if ((f == 1 || f == 3) && nr == cfl[cc].fst-1) nr = cfl[cc].snd;
        if ((f == 1 || f == 3) && nr == cfl[cc].snd+1) nr = cfl[cc].fst;
        //dbg(nr, nc);
        if (g[nr][nc] == '.')
            cr = nr, cc = nc;
    }
    cout << "Ended at: " << cr << " " << cc << endl;
}

int getFace(int row, int col) {
    if (col >= 50 && col <= 99 && row >= 0 && row <= 49) return 1;
    if (col >= 100 && col <= 149 && row >= 0 && row <= 49) return 2;
    if (col >= 50 && col <= 99 && row >= 50 && row <= 99) return 3;
    if (col >= 0 && col <= 49 && row >= 100 && row <= 149) return 4;
    if (col >= 50 && col <= 99 && row >= 100 && row <= 149) return 5;
    if (col >= 0 && col <= 49 && row >= 150 && row <= 199) return 6;
    return -1; 
}

//int getFace(int row, int col) {
//    if (col >= 8 && col <= 11 && row >= 0 && row <= 3) return 1;
//    if (col >= 0 && col <= 3 && row >= 4 && row <= 7) return 2;
//    if (col >= 4 && col <= 7 && row >= 4 && row <= 7) return 3;
//    if (col >= 8 && col <= 11 && row >= 4 && row <= 7) return 4;
//    if (col >= 8 && col <= 11 && row >= 8 && row <= 11) return 5;
//    if (col >= 12 && col <= 15 && row >= 8 && row <= 11) return 6;
//    return -1;
//}

void drawGridWithFaces() {
    dbg(g[0]);
    dbg(getFace(0, 0));
    dbg(isspace(g[0][0]));
    forn(i, NROW) {
        forn(j, (int)g[i].size()) {
            if (g[i][j] == '\0') break;
            cout << (isspace(g[i][j]) ? " " : to_string(getFace(i, j)));

        }
        cout << endl;
    }
}

void solve1() {
    int cr, cc, f, pad;
    cr = 0;
    cc = g[cr].find('.');
    pad = cc;
    f = 0;
    dbg(cc, cr, f, pad);
    n = steps.size();
    forn(i, n) {
        if (isdigit(steps[i][0])) {
            int st = stoi(steps[i]);
            move(st, cr, cc, f);
        } else if (isalpha(steps[i][0])) {
            if (steps[i][0] == 'R') f = (f+1) % 4;
            else f = (f - 1 + 4) % 4;
        }
    }
    
    ll ans = getAns(cr, cc, f);
    cout << g[cr] << endl << g[cr+1] << endl << g[cr+2] << endl;
    cout << g[cr].size() << endl;
    dbg(cr, cc, f);
    cout << ans << endl;
}

void solve2() {
    drawGridWithFaces();
    int cr, cc, f, pad;
    cr = 0;
    cc = g[cr].find('.');
    pad = cc;
    f = 0;
    dbg(cc, cr, f, pad);
    n = steps.size();
    forn(i, n) {
        if (isdigit(steps[i][0])) {
            int st = stoi(steps[i]);
            move2(st, cr, cc, f);
        } else if (isalpha(steps[i][0])) {
            if (steps[i][0] == 'R') f = (f+1) % 4;
            else f = (f - 1 + 4) % 4;
        }
    }
    
    ll ans = getAns(cr, cc, f);
    cout << g[cr] << endl << g[cr+1] << endl << g[cr+2] << endl;
    cout << g[cr].size() << endl;
    dbg(cr, cc, f);
    cout << ans << endl;
}

int main() {
    readGrid();
    readSteps();
    //solve1();
    solve2();
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
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/

