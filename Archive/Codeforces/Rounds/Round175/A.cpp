#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, p[100001];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int idx = 1;
    int ls=1;
    while(k && idx <= n/2) {
        int sym = n-idx+1;
        if (abs(sym - idx) == 1) {
            swap(p[idx], p[sym]);
            k--;
            ls = idx;
        }
        else if (sym - idx == 0)
            k--;
        else if(abs(sym-idx) > 1 && k > 1) {
            k -= 2; 
            swap(p[idx], p[sym]);
            ls = idx;
        }
        idx++;
    }
    if (k == 1)
        swap(p[ls+1], p[ls+2]);
    for (int i = 1; i <= n; ++i)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}