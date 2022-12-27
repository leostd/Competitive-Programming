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

const int NON_NUM = INF;
const char NON_OPERATOR = 'n';

int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<ll> vans;

struct Monkey {
    bool isNum;
    char op;
    ll num;
    string operand1;
    string operand2;
    string id;
    bool hpath;

    Monkey() {
        isNum = false;
        op = NON_OPERATOR;
        operand1 = operand2 = "";
    }

    Monkey(string _id, bool _isNum, int _num, char _operator, string _operand1, string _operand2) {
        isNum = _isNum;
        if (isNum) {
            num = _num;
        }
        op = _operator;
        operand1 = _operand1;
        operand2 = _operand2;
        id = _id;
    }


    bool setPath(map<string, Monkey> &gr) {
        if (id == "humn") {
            hpath = true;
            return true;
        } 
        if (isNum)
            return false;
        bool a = gr[operand1].setPath(gr);
        bool b = gr[operand2].setPath(gr);
        hpath = a || b;
        return hpath;
    }

    ll compute(map<string, Monkey> &gr) {
        if (isNum) return num;

        ll a = gr[operand1].compute(gr);
        ll b = gr[operand2].compute(gr);
        switch(op){
            case '+':
                num = a + b;
                break;
            case '-':
                num = a - b;
                break;
            case '*':
                num = a * b;
                break;
            case '/':
                num = a / b;
                break;
        }

       // isNum = true;
        return num;
    }

    void compute2(map<string, Monkey> &gr, vector<ll> eqt) {
        if (id == "humn") {
            num = eqt[0];
            vans = eqt;
            return;
        }
        if (isNum) return;

        ll a;
        
        dbg(id, gr[operand1].hpath, gr[operand2].hpath);
        dbg(num, ""+op);
        if (!gr[operand1].hpath && !gr[operand2].hpath) {
            gr[id].compute(gr);
            return;
        }
        if (id == "root") {
            if (!gr[operand1].hpath) {
                a = gr[operand1].compute(gr);
                eqt.pb(a);
                gr[operand2].compute2(gr, eqt);
            }

            if (!gr[operand2].hpath) {
                a = gr[operand2].compute(gr);
                eqt.pb(a);
                gr[operand1].compute2(gr, eqt);
            }

            return;
        }
        
        if (!gr[operand1].hpath) {
            a = gr[operand1].compute(gr);
            gr[operand2].compute2(gr, getNum(eqt, op, a, true));
        }
        if (!gr[operand2].hpath) {
            a = gr[operand2].compute(gr);
            gr[operand1].compute2(gr, getNum(eqt, op, a, false));
        }
        
    }

    vector<ll> getNum(vector<ll> eqt, char op, ll x, bool left) {
        if (op == '+') {
            for(auto &y : eqt) y -= x;
        }
        if (op == '-') {
            if (left)
                for(auto &y : eqt) y = x-y;
            else 
                for(auto &y : eqt) y += x;
        }
        if (op == '/') {
            dbg("division", x, eqt);
            if (left) {
                for(auto &y : eqt) y = x/y;
                return eqt;
            }
            int sz = eqt.size();
            vector<ll> neqt;
            forn(i, sz) {
                ll aux = x * eqt[i];
                forn(i, x) neqt.pb(aux+i);
            }
           sort(all(neqt));
           neqt.resize(unique(all(neqt)) - neqt.begin());
           dbg(neqt);
           dbg(eqt.size(), neqt.size());
           eqt = neqt;
        }
        if (op == '*') {
            for(auto &y : eqt) y /= x;
        }
        return eqt;
    }
};

string to_string(char x) {
    string ret;
    ret.pb(x);
    return ret;
}

string to_string(Monkey a) {
    string ret;
    ret += "isNum: " + to_string(a.isNum) + endl;
    ret += "operator: " + to_string(a.op) + endl;
    ret += "operand1: " + a.operand1 + endl;
    ret += "operand2: " + a.operand2 + endl;
    ret += "num: " + to_string(a.num) + endl;
    return ret;
}

map<string, Monkey> gr;

void parse(string ln) {
    dbg(ln);
    stringstream ss(ln);
    string id;
    ss >> id;
    id.pop_back();
    dbg(id);
    string aux;
    ss >> aux;
    Monkey nm;
    if (isdigit(aux[0]) || aux[0] == '-') {
        nm = Monkey(id, true, stoi(aux), NON_OPERATOR, "", "");
    } else {
        string op, operand2;
        ss >> op >> operand2;
        nm = Monkey(id, false, NON_NUM, op[0], aux, operand2);
    }

    gr[id] = nm;
}

void solve1() {
    string ln;
    while(getline(cin, ln)) {
        parse(ln);
    }
    gr["humn"].num = 8882214318977;
    ll ans = gr["root"].compute(gr);
    string l = gr["root"].operand1;
    string r = gr["root"].operand2;
    cout << gr[l].num << " " << gr[r].num << endl;
    cout << ans << endl;
}

ll f(ll x) {
    map<string, Monkey> cgr = gr;
    cgr["humn"].num = x;
    cgr["root"].compute(cgr);
    string a = cgr["root"].operand1;
    string b = cgr["root"].operand2;
    return abs(cgr[a].num - cgr[b].num);
}

void solve2() {
    string ln;
    while(getline(cin, ln)) {
        parse(ln);
    }

    gr["root"].setPath(gr);
    vans.clear();
    gr["root"].compute2(gr, vector<ll>());
    ll ans = gr["humn"].num;
    sort(all(vans));
    vans.resize(unique(all(vans))-vans.begin());
    dbg(vans);
    cout << ans << endl;
}

int main() {
    fastIO();
    solve1();
    //solve2();
    string l = gr["root"].operand1, r = gr["root"].operand2;
    vector<ll> pos({3087390115719, 3087390115720, 3087390115721, 3087390115722});
    for(auto x : pos) {
        gr["humn"].num = x;
        gr["root"].compute(gr);
        cout << gr[l].num << " " << gr[r].num << endl;
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
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/

