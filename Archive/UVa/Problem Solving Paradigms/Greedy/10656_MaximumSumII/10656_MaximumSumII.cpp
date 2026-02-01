#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, t = 1;
    while(scanf("%d", &n), n){
        bool flag = true;
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            if(a && flag){
                flag = false;
                printf("%d", a);
            }
            else if (a && !flag){
                printf("%s%d", i ? " ": "", a);
            }
        }
        if (flag)
            printf("0");
        printf("\n");
    }
    return 0;
}
