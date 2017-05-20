#include <bits/stdc++.h>
using namespace std;
int main(){
    for (int i = 1; i <= 2000; ++i){
        if (i*i*i*i > 2e9) break;
        for (int j = i; j <= 2000-i; ++j) {
            if (i*j*j*j > 2e9) break;
            for (int k = j; k <=2000-j; ++k) {
                if (i*j*k*k > 2e9) break;
                int a = i+j+k;
                int b = i*j*k;
                int c = 1e6;
                if (b == c) continue;
                int n = a*c;
                int d = b-c;
                if (n % d != 0) continue;
                int p4 = n/d;
                if (k > p4) continue;
                if (p4 + a > 2000) continue;
                if (p4*b > 2e9) continue;
                printf("%.2lf %.2lf %.2lf %.2lf\n", (double)i/100, (double)j/100, (double)k/100, (double)p4/100);
            }
        }
    }
    return 0;
}