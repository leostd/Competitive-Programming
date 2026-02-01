#include <bits/stdc++.h>
using namespace std;

int ipow(int n, int e) {
    int ans = 1;
    for (int i = 0; i < e; ++i)
        ans *= n;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int last, nn, aux = n;
    nn = 0;
    while(aux) {
        last = (aux % 10 == 0) ? last : aux % 10;
        aux = aux / 10;
        nn++;
    }
    last++;
    aux = last * ipow(10, nn-1);
    printf("%d\n", aux-n);
    return 0;
}