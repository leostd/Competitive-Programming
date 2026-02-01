#include <bits/stdc++.h>
#define N 101
using namespace std;

int main(){
    int n, d, r;
    int night[N], day[N];
    while(scanf("%d %d %d", &n, &d, &r), n || d || r){
        memset(night, 0, sizeof(night));
        memset(day, 0, sizeof(day));
        int sum_night = 0, sum_day = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &day[i]);
            sum_day += day[i];
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &night[i]);
            sum_night += night[i];
        }
        sort(day, day+n);
        sort(night, night+n);
        int aux = 0, overtime = 0;
        for(int i = 0; i < n; i++){
            overtime += max(0, day[i] + night[n-1-i] - d);
        }
        printf("%d\n", overtime*r);
    }
    return 0;
}
