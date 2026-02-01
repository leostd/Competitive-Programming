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

char inv(char x){
    return (x == '1'? '0' : '1');
}

int main() {
    int t, b;
    cin >> t >> b;
    string response;

    while(t--){
        string ans(b, '0');
        pii diff(-1,-1), same(-1,-1);
        if (b == 10){
            bool flag = true;
            for (int i = 1; i <= 4; i++){
                cout << i << endl;
                cout.flush();
                cin >> ans[i-1], flag = false;
                cout << b - i + 1 << endl;
                cout.flush();
                cin >> ans[b-i], flag = true;
                if (ans[b-i] == ans[i-1])
                    same = pii(i, b-i+1);
                else
                    diff = pii(i, b-i+1);
            }
            cout << 5 << endl;
            cout.flush();
            cin >> ans[4];
            
            pii aux_diff;
            if (diff.fst != -1) {
                cout << diff.fst << endl;
                cout.flush();
                cin >> aux_diff.fst;
                cout << diff.snd << endl;
                cout.flush();
                cin >> aux_diff.snd;
            }

            pii aux_same;
            if (same.fst != -1) {
                cout << same.fst << endl;
                cout.flush();
                cin >> aux_same.fst;
                cout << same.snd << endl;
                cout.flush();
                cin >> aux_same.snd;
            }

            int transformation;
            if ((aux_same != same && diff != aux_diff) || (same.fst != -1 && diff.fst == -1 && aux_same != same) || (diff.fst != -1 && same.fst == -1 && diff != aux_diff)){
                transformation = 1;
                for(int i = 1; i <= b; i++) {
                    ans[i-1] = inv(ans[i-1]);
                }
                cout << 6 << endl; cout.flush();
                cin >> ans[5];
            }else if ( (aux_diff != diff && same == aux_same) || (same.fst != -1 && diff.fst == -1 && aux_same == same) || (diff.fst != -1 && same.fst == -1 && diff != aux_diff)) {
                transformation = 2;
                for(int i = 1; i <= 5; i++) {
                    swap(ans[i-1], ans[b-i]);
                }
                cout << 5 << endl; cout.flush();
                cin >> ans[4];
            }else if ( (aux_diff == diff && same != aux_same) || (same.fst != -1 && diff.fst == -1 && aux_same != same) || (diff.fst != -1 && same.fst == -1 && diff == aux_diff)) {
                transformation = 3;
                for(int i = 1; i <= 5; i++) {
                    swap(ans[i-1], ans[b-i]);
                    ans[i-1] = inv(ans[i-1]);
                    ans[b-i] = inv(ans[b-i]);
                }
                cout << 5 << endl; cout.flush();
                cin >> ans[4];
                
            } else if (aux_diff == diff && same == aux_same) {
                transformation = 4;
                cout << 6 << endl; cout.flush();
                cin >> ans[5];
            }

            cout << ans << endl;
        }else if(b > 10 && b <= 20){
            cout << ans << endl;
        }else{
            cout << ans << endl;
        }
        cin >> response;
    }
    return 0;
}