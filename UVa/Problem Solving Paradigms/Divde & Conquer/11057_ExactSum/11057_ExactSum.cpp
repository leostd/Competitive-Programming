#include <bits/stdc++.h>
using namespace std;

int books[100005];

int main() {
    int n,m, ma, mb, t;
    bool first = true;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%d", &books[i]);
        scanf("%d", &m);
        sort(books, books+n);
        ma = 0, mb = 0x3f3f3f3f;
        for (int i=0; i < n; i++) {
            t = m - books[i];
            int aux = books[i];
            if (binary_search(books+i+1, books+n, t) && mb-ma > t-books[i]){
                ma = books[i];
                mb = t;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", ma, mb);
    }
    return 0;
}