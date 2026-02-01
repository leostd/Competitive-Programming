#include <bits/stdc++.h>
#define N 1004
using namespace std;

int ts[N], ts2[N], mins[N], n, k, steps;

void process() {
    for (int i = 1; i < n; i++)
        ts2[i] = ts[i];
    for (int i = 1; i < n; i++) {
        if (ts2[i] - ts2[i-1] != k){
            ts2[i] = k+ts2[i-1];
            steps++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &ts[i]);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 1000; i++){
        ts2[0] = ts[0];
        steps = 0;
        if (ts2[0] != i) {
            ts2[0] = i;
            steps++;
        }
        process();
        if (steps < ans){
            ans = steps;
            for (int j = 0; j < n; ++j)
                mins[j] = ts2[j];
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        if (mins[i] != ts[i]) {
            int aux1 = mins[i]; int aux2 = ts[i];
            if (mins[i] > ts[i]) printf("+ ");
            else printf("- ");
            printf("%d %d\n", i+1, abs(ts[i]-mins[i]));
        }
    }
    return 0;
}