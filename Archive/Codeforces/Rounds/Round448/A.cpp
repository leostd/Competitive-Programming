#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int a[400];
    int acums[400];
    acums[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++)
        acums[i] = acums[i-1] + a[i];
    int min_diff = 0x3f3f3f3f;
    if (n == 0)
        printf("360\n");
    else{
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < i; j++){
                int a = acums[i] - acums[j];
                int b = 360 - a;
                min_diff = min(min_diff, abs(a-b));
            }
        }
        printf("%d\n", min_diff);
    }

    return 0;
}
