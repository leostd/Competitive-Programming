#include <bits/stdc++.h>
#define N 1001
using namespace std;

int p[N], q[N];

bool ordered(int n) {
    for (int i = 0; i < n-1; i++){
        if (q[i] < q[i+1])
            return false;
    }
    return true;
}

bool eq(int n){
    for (int i = 0; i < n; i++) {
        if (p[i] != q[i])
            return false;
    }
    return true;
}
int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &q[i]);
    }
    bool order = ordered(n), equal = eq(n);
    if (!equal)
        printf("rated\n");
    else if (equal && order)
        printf("maybe\n");
    else if (equal && !order)
        printf("unrated\n");
    return 0;
}