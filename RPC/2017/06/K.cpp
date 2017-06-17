#include <bits/stdc++.h>
using namespace std;

double f(double b) {
    double c1, c2, h;
    h = b;
    c1 = (double)b/2;
    c2 = sqrt(h*h - c1*c1);
    return c2;
}

int main(){
    double dec = 0, s1= 0, s2= 0;
    int t, n;
    double b;
    char ch;
    scanf("%d", &t);
    bool first, second, third;
    first = second = third = false;
    while(t--) {
        scanf("%d\n", &n);
        dec = s1 = s2 = 0;
        first = second = false;
        for (int i = 0; i < n; i++){
            scanf("%c %lf\n", &ch, &b);
            dec += (ch == 'T') ? f(b)*b/2 : b*b;
            
            if (i > 0){
                if (!first) {
                    s1 += b;
                    if (ch == 'C'){
                        first = true;
                        s2 += b;
                    }
                }
                else if (first && !second){
                    s2 += b;
                    if (ch == 'C') second = true;
                }
            }
            else
                s1 += b;
        }
        double area = s1 * s2;
        printf("%.4lf\n", area-dec);
    }
    return 0;
}