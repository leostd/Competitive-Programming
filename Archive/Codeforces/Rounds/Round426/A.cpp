#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    char dir[4]={'^', 'v', '<', '>'}, s, e;
    bool fcw, fccw;
    fcw = fccw = false;
    map<char, int> ccw, cs;
    ccw['^'] = 0;
    ccw['<'] = 1;
    ccw['v'] = 2;
    ccw['>'] = 3;
    cs['^'] = 0;
    cs['>'] = 1;
    cs['v'] = 2;
    cs['<'] = 3;
    int n;
    scanf("%c %c\n", &s, &e);
    scanf("%d", &n);
    int a, b, c;
    a = ccw[s];
    b = ccw[e];
    c = n % 4;
    if ((a + c)%4 == b) 
        fccw = true;
    a = cs[s];
    b = cs[e];
    if ((a+c)%4 == b)
        fcw = true;
    if (fcw == fccw)
        printf("undefined\n");
    else if (fcw)
        printf("cw\n");
    else
        printf("ccw\n");
    return 0;
}