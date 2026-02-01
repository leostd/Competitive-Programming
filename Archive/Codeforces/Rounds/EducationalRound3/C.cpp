#include <bits/stdc++.h>
#define N 100001
using namespace std;

int main(){
    int n, l[N];
    scanf("%d", &n);
    int acum = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &l[i]);
        acum+=l[i];
    }
    int avg = acum/n;
    sort(l, l+n);
    int ans[N];
    for(int i = 0; i < n; i++)
        ans[i] = avg;
    int aux = acum % n;
    for (int i = n-1; i >= n-aux; i--)
        ans[i]++;
    aux = 0;
    for(int i = 0; i < n; i++)
        aux += abs(ans[i]-l[i]);
    aux /= 2;
    printf("%d", aux);
    return 0;
}
