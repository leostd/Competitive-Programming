#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int acum;
int n, m, ct = 0;
vi onlights[20];

void solve(int flr, int side, int total, int rest) {
    if (flr == -1) {
        acum = min(acum, total);
        return;
    }
    else if (rest > 0 && onlights[flr].empty())
        solve(flr-1, side, total+1, rest);
    else {
        int pos = (side) ? m+1 : 0;
        int farthest = (side) ? onlights[flr].front() : onlights[flr].back();
        total += abs(farthest - pos);
        pos = farthest;
        rest -= onlights[flr].size();
        if (rest) {
            solve(flr-1, 0, total + pos + 1, rest);
            solve (flr-1, 1, total + abs(pos-(m+1)) + 1, rest); 
        }
        else {
            acum = min(acum, total);
            return;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    int b[20][105];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m+1; j++) {
            scanf("%1d", &b[i][j]);
            if (b[i][j]) {
                onlights[i].push_back(j);
                ct++;
            }
        }
    }
    acum = 0x3f3f3f3;
    if (ct)
        solve(n-1, 0, 0, ct);
    else
        acum = 0;
    printf("%d", acum);
    return 0;
}

