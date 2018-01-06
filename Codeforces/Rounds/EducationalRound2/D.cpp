#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define PI (acos(-1.0L))
using namespace std;

int main(){
    long long int x1,x2,y1,y2,r1,r2;
    long double alpha1, alpha2, aux, d, dsqr, p1x, t1, s1, t2, s2, ans1, ans2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    dsqr = sqr(x1-x2) + sqr(y1-y2);
    d = sqrt(dsqr);
    if (dsqr >= sqr(r1+r2)){
        printf("%.20Lf\n", 0.0L);
        return 0;
    }
    if (r1 > r2 && dsqr <= sqr(r1-r2)){
        printf("%.20Lf\n", PI*(long double)sqr(r2));
        return 0;
    }
    if (r2 > r1 && dsqr < sqr(r1-r2)){
        printf("%.20Lf\n", PI*(long double)sqr(r1));
        return 0;
    }
    p1x = (dsqr + sqr(r2) - sqr(r1)) / (2*d);
    aux = p1x/r1;
    alpha1 = acos(aux);
    t1 = sqr(r1)*sin(alpha1)*cos(alpha1);
    s1 = alpha1*sqr(r1);
    ans1 = s1 - t1;
    alpha2 = acos(fabs(d-p1x)/r2);
    t2 = sqr(r2)*sin(alpha2)*cos(alpha2);
    s2 = alpha2*sqr(r2);
    ans2 = s2 - t2;
    printf("%.20Lf\n", ans2+ans1);
    return 0;
}
