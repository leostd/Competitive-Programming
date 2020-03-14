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

using namespace std;

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
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


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

//#############################
const int MAXN = 1000005;

pii multiply(char x, char y) {
    int mult = (x-'0') * (y-'0');
    int num = mult % 10;
    int carry = mult / 10;
    return pii(num, carry);
}

pii add(char x, char y) {
    int sum = (x-'0') + (y-'0');
    int num = sum % 10;
    int carry = sum / 10;
    return pii(num, carry);
}

// 9 9 9
// 9 9

// 8 8 

// 2 2 2 
// 4 5 
// 8 8 8
// 0 0 1 1 1
// 8 8 9 1 1

string sum(string a, string b, bool rev) {
    if (!rev){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    }
    string res(max(a.size(), b.size()), '0');
    int carry = 0, sum, digit;
    for (int i = 0; i < res.size(); i++) {
        if (i < a.size() && i < b.size()) {
            sum = (a[i]-'0') + (b[i]-'0') + carry;
            digit = sum % 10;
            carry = sum / 10;
        }
        else if (i < a.size() && i >= b.size()) {
            sum = (a[i]-'0') + carry;
            digit = sum % 10;
            carry = sum / 10;
        }
        else if (i >= a.size() && i < b.size()) {
            sum = (b[i]-'0') + carry;
            digit = sum % 10;
            carry = sum / 10;
        }
        res[i] = digit + '0';
    }
    if (carry)
        res.pb('1');
    return res;
}

int main() {
    string a,b;

    while(cin >> a >> b) {

        if (a=="0" || b=="0") {
            cout << 0 << endl;
            continue;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());


        int pow = 0;
        string res = "0";
        for (int i = 0; i < a.size(); i++) {
            string aux;
            for (int j = 0; j < i; j++){
                aux.pb('0');
            }
            int carry = 0, mult, digit;
            for (int j = 0;j < b.size();j++) {
                mult = (a[i]-'0') * (b[j]-'0') + carry;
                carry = mult / 10;
                digit = mult % 10;
                aux.pb(digit+'0');
            }
            if (carry)
                aux.pb(carry+'0');

            // cout << aux << endl;
            // cout << res << endl;

            res = sum(res, aux, true);

        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }


    return 0;
}