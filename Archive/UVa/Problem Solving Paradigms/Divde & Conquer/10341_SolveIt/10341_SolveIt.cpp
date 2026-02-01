#include <bits/stdc++.h>
#define EPS 1e-5
using namespace std;

int p,q,r,s,t,u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        if (f(0) * f(1) > 0){
            printf("No solution\n");
            continue;
        }
        double a = 0, b = 1, mid;
        for(int i = 0; i < 300; ++i) {
            mid = (double)(b-a)/2 + a;
            if (f(mid) > 0)
                a = mid;
            else if (f(mid) < 0)
                b = mid;
        }
        printf("%.4lf\n", mid);   
    }
    return 0;
}