#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) ((int)x.size())
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
const string abc = "abcdefghijklmnopqrstuvwxyz";
//#############################
const int MAXN = 1000005;

const string ACCEPTED = "A";
const string REJECTED = "R";
const string SKIP = "S";

struct MPart {
    ll x, m, a, s;
    MPart(ll _x, ll _m, ll _a, ll _s): x(_x), m(_m), a(_a), s(_s) {}
};

struct RPart {
    pll x, m, a, s;
    RPart(pll _x, pll _m, pll _a, pll _s): x(_x), m(_m), a(_a), s(_s) {}
    ll prod() {
        ll lx = max(0LL, x.snd - x.fst);
        ll lm = max(0LL, m.snd - m.fst);
        ll la = max(0LL, a.snd - a.fst);
        ll ls = max(0LL, s.snd - s.fst);

        return lx * lm * la * ls;
    }

    pll getRng(char ch) {
        if (ch == 'x') return x;
        if (ch == 'm') return m;
        if (ch == 'a') return a;
        if (ch == 's') return s;
        return mp(-1, -1);
    }

    void setRng(char ch, pll rng) {
        if (ch ==  'x') x = rng;
        if (ch == 'm') m = rng;
        if (ch == 'a') a = rng;
        if (ch == 's') s = rng;
    }

    void bisectRange(char ch, ll val, char op, bool inc) {
        pll rng = getRng(ch);
        if (op == '<') {
            rng.snd = min(val+inc, rng.snd);
        } else {
            rng.fst = max(val+1-inc, rng.fst);
        }

        if (rng.fst > rng.snd) rng = mp(0, 0);
        setRng(ch, rng);
    }
};

struct Rule {
    string definition;
    char param;
    ll operand;
    char op;
    string result;

    Rule(string def) {
        definition = def;
        param = def[0];
        op = def[1];
        int idx = def.find(":");
        result = def.substr(idx+1, string::npos);
        def.pop_back();
        operand = stoll(def.substr(2, string::npos));
        dbg(definition);
        dbg(operand, result);
    }
    string eval(ll x) {
        if (op == '>' && x > operand) return result;
        else if (op == '<' && x < operand) return result;
        return "S";
    }

};

struct Workflow {
    string definition;
    string id;
    vector<Rule> rules;
    string defaultVal;
    Workflow(): definition(""), id(""), rules(vector<Rule>()), defaultVal("") {}
    //Workflow(Workflow &wf) {
    //    definition = wf.definition;
    //    id = wf.id;
    //    rules = wf.rules;
    //    defaultVal = wf.defaultVal;
    //}
    Workflow(string &def) {
        definition = def;
        int idx = def.find("{");
        id = def.substr(0, idx);
        def = def.substr(idx+1, string::npos);
        def.pop_back();
        string cur;
        forn(i, sz(def)) {
            if (def[i] == ',') {
                rules.pb(Rule(cur));
                cur = "";
            } else {
                cur.pb(def[i]);
            }
        }
        defaultVal = cur;
        dbg(definition);
        dbg(id, defaultVal);
    }

    string eval(MPart part) {
        for (auto x : rules) {
            string res="-1";
            if (x.param == 'x') res = x.eval(part.x);
            else if (x.param == 'm') res = x.eval(part.m);
            else if (x.param == 'a') res = x.eval(part.a);
            else if (x.param == 's') res = x.eval(part.s);
            string a1, a2;
            a1.pb(x.param);
            a2.pb(x.op);
           // dbg(x.definition, a1, a2, res, part.x, part.m, part.a, part.s);
            if (res == SKIP) continue;
            else return res;
        }
        dbg("returning defaultValue");
        return defaultVal;
    }
};

map<string, Workflow> wmap;
vector<MPart> parts;
void parse() {
    string line;
    while(getline(cin, line), line != "") {
        dbg(line);
        Workflow w(line);
        wmap[w.id] = w;
    }

    cout << "---------" << endl;

    while(getline(cin, line)) {
        dbg(line);
        line.pop_back();
        line = line.substr(1, string::npos);
        string cur;
        vector<ll> aux;
        forn(i, sz(line)) {
            if (line[i] == ',') {
                cur = cur.substr(2,string::npos);
                aux.pb(stoll(cur));
                cur = "";
            } else cur.pb(line[i]);
        }
        cur = cur.substr(2, string::npos);
        aux.pb(stoll(cur));
        MPart p(aux[0], aux[1], aux[2], aux[3]);
        parts.pb(p);
    }
}

void solve1() {
    int ans = 0;
    string wf = "in";
    for (auto x : parts) {
        while(wf != ACCEPTED && wf != REJECTED) {
            wf = wmap[wf].eval(x);
            dbg(x.x, wf);
       }
        if (wf == ACCEPTED) {
            dbg(x.x);
            ans += x.x + x.m + x.a + x.s;
            wf = "in";
        } else if (wf == REJECTED) {
            wf = "in";
            continue;
        }
    }

    cout << ans << endl;
}

vector<vector<string>> paths;
ll ans;
set<string> vis;
char inv(char x) {
    if (x == '>') return '<';
    else return '>';
}

void dfs(RPart z, string cur, vector<string> path) {
    dbg(path);
    dbg(cur);
    dbg(z.x, z.m, z.a, z.s);
    if (cur == ACCEPTED) {
        dbg(z.x, z.m, z.a, z.s);
        ans += z.prod();
        dbg(z.prod());
        return;
    } else if (cur == REJECTED) {
        return;
    }

    vis.insert(cur);

    Workflow wf = wmap[cur];
    RPart defP(z);
    for(auto x : wf.rules) {
        string res = x.result;
        if (!vis.count(res)) {
            RPart aux(defP);
            aux.bisectRange(x.param, x.operand, x.op, 0);
            string dvar(1, x.param);
            path.pb(res);
            dfs(aux, res, path);
            path.pop_back();
        }
        defP.bisectRange(x.param, x.operand, inv(x.op), 1);
    }

    if (!vis.count(wf.defaultVal)) {
        path.pb(wf.defaultVal);
        dfs(defP, wf.defaultVal, path);
    }
}

void solve2() {
    ans = 0;
    string cur = "in";
    RPart x(mp(1, 4001), mp(1, 4001), mp(1, 4001), mp(1, 4001));
    vector<string> a;
    a.pb(cur);
    dfs(x, cur, a);
    cout << ans << endl;
}

signed main() {
    fastIO(); 
    parse();
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

