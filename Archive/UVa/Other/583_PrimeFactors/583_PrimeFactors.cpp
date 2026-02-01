#include <bits/stdc++.h>
using namespace std;


void primeFactors(int n, multiset<int> &pf) {
    while(n%2 == 0)
    {
        pf.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while(n%i == 0) {
            pf.insert(i);
            n = n/i;
        }
    }
    if (n > 2) pf.insert(n);
}

int main() {
    int n;
    multiset<int> pf;
    while(scanf("%d", &n), n) {
        pf.clear();
        printf("%d = ", n);
        if (n < 0)
            printf("-1 x ");
        primeFactors(abs(n), pf);
        for (auto it = pf.begin(); it != pf.end(); ++it) {
            if (it != pf.begin())
                printf(" x ");
            printf("%d", *it);
        }
        printf("\n");
    }
    return 0;
}