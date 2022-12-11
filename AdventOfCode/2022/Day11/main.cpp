#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
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

// template<typename A>
// string to_string(vector<A> v);

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
const int ROUNDS = 10000;
vector<ll> mods;

class Monkey {
public:
    int id;
    vector<ll> items;
    vector<vector<ll>> ritems;
    string operation;
    string test;
    ll rank;
    int to[2];

    Monkey(vector<ll> _items, string _operation, string _test, int tr, int fa, int _id) {
        items = _items;
        operation = _operation;
        test = _test;
        to[0] = fa;
        to[1] = tr;
        id = _id;
        rank = 0;
    }

    void play(vector<Monkey> &monkeys) {
        for (auto &x : ritems) {
            inspect(x);
            // x /= 3;
            monkeys[to[t(x)]].ritems.pb(x);
            rank++;
        }
        ritems.clear();
    }

    void inspect(vector<ll> &x) {
        // dbg("Monkey", id);
        // dbg(x, "1");
        stringstream ss(operation);
        string s1, s2, s3;
        ss >> s1 >> s2 >> s3;
        vector<ll> a = parse(s1, x);
        vector<ll> b = parse(s3, x);
        if (s2 == "*") {
            int m = mods.size();
            forn(i, m) {
                x[i] = (a[i]%mods[i]) * (b[i]%mods[i]);
                x[i] %= mods[i];
            }
        }

        if (s2 == "+") {
            int m = mods.size();
            forn(i, m) {
                x[i] = (a[i]%mods[i]) + (b[i]%mods[i]);
                x[i] %= mods[i];
            }
        }
        // if (s2 == "*") ret = ((ret%MOD) * (parse(s3, x)%MOD))%MOD;
        // if (s2 == "+") ret += ((ret%MOD) + (parse(s3, x)%MOD))%MOD;
        // dbg(x, "2");
    }

    vector<ll> parse(string s, vector<ll> x) {
        vector<ll> ret;
        if (s == "old") return x;
        else return vector<ll>(mods.size(), stoll(s));
    }

    ll parse(string s, ll old) {
        if (s == "old") return old;
        else return stoll(s);
    }

    bool t(ll x) {
        stringstream ss(test);
        string s1, s2, s3;
        ss >> s1 >> s2 >> s3;
        return x % stoll(s3) == 0LL;
    }

    bool t(vector<ll> x) {
        return x[id] == 0;
    }

    ll getMod() {
        stringstream ss(test);
        string s1,s2,s3;
        ss >> s1 >> s2 >> s3;
        return stoll(s3);
    }

    void convertItems() {
        for(auto x : items) {
            vector<ll> aux;
            for(auto mod : mods) aux.pb(x%mod);
            ritems.pb(aux);
        }
    }
};

bool cmp(Monkey a, Monkey b) {
    if (a.rank == b.rank)
        return true;
    return a.rank < b.rank;
}

string to_string(Monkey x) {
    string ret;
    ret += "Monkey #" + to_string(x.id) + "\n";
    ret += "items: " + to_string(x.items) + "\n";
    ret += "operation: " + x.operation + "\n";
    ret += "test: " + x.test + "\n";
    ret += "to: if false -> " + to_string(x.to[0]) + " if true -> " + to_string(x.to[1]);
    ret += "\n";

    return ret;
}

vector<Monkey> monkeys;

vector<ll> parseItems(string ln) {
    vector<ll> items;
    int cnt = 0;
    stringstream ss(ln);
    string sk1, sk2;
    ss >> sk1 >> sk2;
    string cur;
    while(ss >> cur) {
        if (cur.back() == ',')
            cur.pop_back();
        items.push_back(stoll(cur));
    }

    return items;
}

string parseOperation(string ln) {
    string operation;
    stringstream ss(ln);
    string sk1, sk2, sk3;
    ss >> sk1 >> sk2 >> sk3;
    string x;
    bool first = true;
    while(ss >> x) {
        if (!first) operation += " ";
        operation += x;
        first = false;
    }

    return operation;
}

string parseTest(string ln) {
    string test;
    stringstream ss(ln);
    string sk1;
    ss >> sk1;
    string x;
    bool first = true;
    while(ss >> x) {
        if (!first) test += " ";
        test += x;
        first = false;
    }

    return test;
}

int main() {
    fastIO();
    string s1, s2;
    while(cin >> s1 >> s2) {
        s2.pop_back();
        dbg(s1, s2);
        int id = s2[0] - '0';
        string ln;
        cin.ignore();
        getline(cin, ln);
        dbg(ln);
        vector<ll> items = parseItems(ln);
        getline(cin, ln);
        dbg(ln);
        string operation = parseOperation(ln);
        getline(cin, ln);
        dbg(ln);
        string test = parseTest(ln);
        getline(cin, ln);
        dbg(ln);
        int tr = ln.back() - '0';
        getline(cin, ln);
        dbg(ln);
        int fa = ln.back() - '0';
        monkeys.pb(Monkey(items, operation, test, tr, fa, id));
        // dbg(monkeys.back());
    }
    
    int n = monkeys.size();
    forn(i, n) mods.pb(monkeys[i].getMod());
    dbg(mods);
    forn(i, n) monkeys[i].convertItems();
    forn(i, ROUNDS) {
        forn(j, n) {
            monkeys[j].play(monkeys);
        }
    }

    sort(all(monkeys), cmp);
    dbg(monkeys[n-1].rank, monkeys[n-2].rank);
    dbg(monkeys[n-1].id, monkeys[n-2].id);
    cout << monkeys[n-1].rank << " " << monkeys[n-2].rank << endl;
    ll ans = monkeys[n-1].rank * monkeys[n-2].rank;
    cout << ans;
    cout << endl;
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

