#include <bits/stdc++.h>
#define N 100000
using namespace std;

int main(){
    int n, a[N],t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int counter = 1,acum = 1;
        for(int i = 1; i < n-1; i++){
            acum += a[i];
            if (acum < a[i+1])
                counter++;
            else
                acum -= a[i];
        }
        if (n > 1)
            counter++;
        printf("%d\n", counter);
    }
    return 0;
}
