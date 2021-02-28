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
const ld EPS = 1e-9;


const int base = 1000000000;
const int base_digits = 9;
 
struct bigint {
    vector<int> a;
    int sign;
 
    bigint() :
        sign(1) {
    }
 
    bigint(long long v) {
        *this = v;
    }
 
    bigint(const string &s) {
        read(s);
    }
 
    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }
 
    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }
 
    bigint operator+(const bigint &v) const             //Addition Operation
    {
        if (sign == v.sign) 
        {
            bigint res = v;
 
            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) 
            {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
 
    bigint operator-(const bigint &v) const             //Subtraction Function
    {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) 
                {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
 
    void operator*=(int v)                      //Multiplication Function
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) 
        {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }
 
    bigint operator*(int v) const 
    {
        bigint res = *this;
        res *= v;
        return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) 
    {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());
 
        for (int i = a.a.size() - 1; i >= 0; i--) 
        {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
 
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const                 //Division Function
    {
        return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const                 //Modulus Operation
    {
        return divmod(*this, v).second;
    }
    
    void operator/=(int v)                                  //Shorthand Operation
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) 
        {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
 
    bigint operator/(int v) const 
    {
        bigint res = *this;
        res /= v;
        return res;
    }
 
    int operator%(int v) const 
    {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }
 
    void operator+=(const bigint &v) 
    {
        *this = *this + v;
    }
    void operator-=(const bigint &v) 
    {
        *this = *this - v;
    }
    void operator*=(const bigint &v) 
    {
        *this = *this * v;
    }
    void operator/=(const bigint &v) 
    {
        *this = *this / v;
    }
 
    bool operator<(const bigint &v) const 
    {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
 
    bool operator>(const bigint &v) const 
    {
        return v < *this;
    }
    bool operator<=(const bigint &v) const 
    {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const 
    {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const 
    {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const 
    {
        return *this < v || v < *this;
    }
 
    void trim() 
    {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
 
    bool isZero() const 
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    bigint operator-() const 
    {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }
 
    bigint abs() const 
    {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }
 
    long long longValue() const 
    {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
 
    friend bigint gcd(const bigint &a, const bigint &b)             //GCD Function(Euler Algorithm)
    {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b)             //Simple LCM Operation
    {
        return a / gcd(a, b) * b;
    }
 
    void read(const string &s)                                  //Reading a Big Integer
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) 
        {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) 
        {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) 
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) 
    {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
 
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) 
    {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) 
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) 
            {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
 
    typedef vector<long long> vll;
 
    static vll karatsubaMultiply(const vll &a, const vll &b)        //Multiplication using Karatsuba Algorithm
    {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) 
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
 
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
 
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
 
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
 
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];
 
        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
 
    bigint operator*(const bigint &v) const 
    {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) 
        {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};


//#############################
const int MAXN = 1000005;

bigint n; // sizes
vector<vector<int>> g; //graph, grid

vector<bigint> toArrayInt(string x) {
    vector<bigint> ret;
    reverse(all(x));
    forn(i, x.size())
        ret.pb(x[i]-'0');

    return ret;
}

bigint toIntWithBase(vector<bigint> x, bigint b) {
    bigint ret = 0;
    // dbg(x, b, ret);
    int ds = x.size();

    bigint pw = 1;
    forn(i, ds) {
        bigint d = x[i];
        ret += d*pw;
        pw *= b;
        // dbg(d, pw, ret);
    }
    // cout << "ret: " << ret << endl;
    return ret;
}

bool f(vector<bigint> arr, bigint base, bigint bound) {
    bigint tst = toIntWithBase(arr, base);

    // dbg (tst, bound, base);

    if (tst <= bound)
        return true;
    else
        return false;
}

int main() {
    fastIO(); 
    string x;
    ll m;
    cin >> x >> m;
    vector<bigint> arr = toArrayInt(x);
    n = *max_element(all(arr));

    // dbg(arr, n, toIntWithBase(arr, 3));
    bigint l, r, mid;
    l = n+1, r = INF64;
    while(r - l > 1){
        mid = l + (r-l)/2;

        if (f(arr, mid, m)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    bigint ans;
    if (!f(arr, l, m) && !f(arr, r, m))
        ans = 0;
    else if (f(arr, r, m))
        ans = r - n;
    else if (f(arr, l, m))
        ans = l - n;
    dbg(x, x.size());
    if (x.size() == 1) {
        // cout << "hola" << endl;
        bigint a = x[0] - '0';
        if (a > m) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    cout << ans << endl;
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
*/