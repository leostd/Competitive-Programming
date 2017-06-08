#include <bits/stdc++.h>
using namespace std;

struct step {
    bool sign;
    int inc, idx;
};

int ts[1004], ts2[1004], ansarr[1004], steps, n, k;

void process() {
    for (int i = 0; i < n; ++i)
        ts2[i] = ts[i];
    for (int i = 1; i < n; ++i) {
        if(ts2[i] - ts2[i-1] != k){
            ts2[i] = k + ts2[i-1];
            steps++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &ts[i]);
    step aux;
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 1000; ++i) {
        steps = 0;
        if (i != ts[0]) {
            steps++;
            ts[0] = i;
        }
        process();
        if (steps < ans){
            ans = steps;
            for (int i = 0; i < n; i++)
                ansarr[i] = ts2[i];
        }
    }
    printf("%d\n", steps);
    for (int i = 0; i < n; ++i){
        if (ts[i] != ansarr[i]){
            if (ansarr[i] > ts[i]) printf("+ ");
            else printf("- ");
            printf("%d %d\n", i+1, abs(ts[i]-ansarr[i]));
        }
    }
    return 0;
}