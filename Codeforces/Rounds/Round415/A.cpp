#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    int n, k;
    int ns[200];
    double acum = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &ns[i]);
    for (int i = 0; i < n; i++)
        acum += ns[i];
    double acum2 = (double)acum/n;
    int ac = acum2 + 0.5;
    int i = 0;
    while(ac < k) {
        acum += k;
        i++;
        acum2 = (double) acum/(n + i);
        ac = acum2 + 0.5; 
    }
    printf("%d\n", i);
    return 0;
}