#include <bits/stdc++.h>
using namespace std;

struct led {
    bool l[7];
    led() { for (int i = 0; i < 7; i++) l[i] = false; }
    led(bool a[]) { for (int i = 0; i < 7; i++) l[i] = a[i]; }
};

map<int, led> mp;

led ls[12];
bool broken[7];
int n;

// can a be b?
bool can(led a, led b) {
    bool ans = true;
    for (int i = 0; i < 7; i++) {
        if (a.l[i] && broken[i]) return false;
        if (b.l[i] && !a.l[i] && !broken[i]) return false;
        if (a.l[i] && !b.l[i]) return false;
    }
    return true;
}

bool solve(int i, int prev, int mask) {
    if (i == n) {
        return true;
    }
    if (prev == -1) {
        led a = ls[0];
        for (int j = 9; j >= 0; --j) {
            led t = mp[j];
            if (!can(a, t)) continue;
            if (solve(1, j, mask)) return true;
        }
        return false;
    }
    else {
        if (prev-1 >= 0 && prev-1 <= 8){
            bool flag = false;
            bool ans = false;
            int m;
            for(m = mask; m < (1 << 7); m++){
                for (int j = 0; j < 7; ++j) {
                    if (mask & (1 << j) || m & (1 << j))
                        broken[j] = true;
                }
                flag = can(ls[i], mp[prev-1]);
                if (flag) ans = solve(i+1, prev-1, mask | m);
                if (ans && flag)
                    return true;
                memset(broken, 0, sizeof(broken));
            }
            return false;
        }
        return false;
    }
}
        
int main()
{
    //freopen("in", "r", stdin);
    bool aux0[7] = {true, true, true, true, true, true, false};
    mp[0] = led(aux0);
    bool aux1[7] = {false, true, true, false, false, false, false};
    mp[1] = led(aux1);
    bool aux2[7] = {true, true, false, true, true, false, true};
    mp[2] = led(aux2);
    bool aux3[7] = {true, true, true, true, false, false, true};
    mp[3] = led(aux3);
    bool aux4[7] = {0, 1, 1, 0, 0, 1, 1};
    mp[4] = led(aux4);
    bool aux5[7] = {1, 0, 1, 1, 0, 1, 1};
    mp[5] = led(aux5);
    bool aux6[7] = {1, 0, 1, 1, 1, 1, 1};
    mp[6] = led(aux6);
    bool aux7[7] = {1, 1, 1, 0, 0, 0, 0};
    mp[7] = led(aux7);
    bool aux8[7] = {1, 1, 1, 1, 1, 1, 1};
    mp[8] = led(aux8);
    bool aux9[7] = {1, 1, 1, 1, 0, 1, 1};
    mp[9] = led(aux9);
    char ch;
    while(scanf("%d\n", &n), n) {
        int seq[12];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 7; ++j) {
                ch = getchar();
                ls[i].l[j] = (ch == 'N') ? false : true;
            }
            getchar();
        }
        bool ans;
        memset(broken, 0, sizeof(broken));
        for(int i = 0; i < (1 << 7); ++i) {
            for (int j = 0; j < 7; ++j) {
                if (i & (1 << j))
                    broken[j] = true;
            }
            ans = solve(0, -1, i);
            if (ans) break;
            memset(broken, 0, sizeof(broken));
        }
        if (ans) printf("MATCH\n");
        else printf("MISMATCH\n");
    }
    return 0;
}