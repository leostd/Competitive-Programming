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
 

int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<vector<double>> a;
vector<double> x;
double EPS = 1e-9;

void gauss() {
    forn(i, n) {
        if (a[i][i] < EPS) {
            int sel = -1;
            fore(row, i+1, n) {
                if (a[row][i] > EPS) {
                    sel = row;
                    break;
                }
            }
 
            forn(j, m) {
                swap(a[i][j], a[sel][j]);
            }
        }
 
        fore(i1, i+1, n) {
            if (a[i1][i] < EPS) continue;
            double coef = a[i][i] / a[i1][i];
            forn(j, m) {
                a[i1][j] = a[i][j] - a[i1][j]*coef;
            }
        }
    }
 
    nfor(i, n) {
        double sum = a[i][n];
        fore(j, i+1, n) {
            sum -= x[j]*a[i][j];
        }
        x[i] = sum / a[i][i];
    }
}

signed main() {
    cin >> n;
    m = n + 1;  // Adjust the value of m to account for the extra column
    a.assign(n, vector<double>(m, 0.0));
    x.assign(n, 0.0);
    forn(i, n) forn(j, m) cin >> a[i][j];
    gauss();
    forn(i, n) {
        cout << fixed << setprecision(7) << x[i] << endl;
    }
    
    return 0;
}
