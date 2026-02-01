#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll k, mx = 0, mn, s; // k, max, min, sergei counter
ll mt[102][102]; // matrix
int x, y; // coords of sergei

int main()
{
    cin >> n >> m >> k >> x >> y;
    ll period = (n > 2)?(n*m) + (n-2)*m : n*m;
    ll laps = k / period;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n-1)
                mt[i][j] = laps;
            else
                mt[i][j] = 2*laps;
        }
    mx = laps;
    ll rest = (period > 0) ? k % period : k;
    int i = 0, j = 0, inc = 1;
    while(rest--){
        mt[i][j]++;
        if (mt[i][j] > mx) 
            mx = mt[i][j];
        j++;
        if (j == m)
        {
            j = 0;
            i += inc;
        }
        if (i == n)
        {
            inc = -1;
            j = 0;
            i = n-2;
        }
    }
    mn = min(mt[0][0], mt[n-1][m-1]);
    mx = max(mt[0][0], mt[n-1][0]);
    if (n > 2)
        mx = max(max(mx, mt[n-2][0]), mt[1][0]);
    cout << mx << " " << mn << " " << mt[x-1][y-1] << "\n";
    return 0;
}