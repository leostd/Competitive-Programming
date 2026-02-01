#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int A, B, C, x,y,z;
        bool flag = false;
        scanf("%d %d %d", &A, &B, &C);
        for (x = -100; x <= 100; ++x) {
            for (y = x+1; y <= 100; ++y) {
                z = A - y - x;
                if (z == x || z == y) continue;
                if (x*y*z == B && (x*x) + (y*y) + (z*z) == C)
                {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if(!flag)
            printf("No solution.\n");
        else
            printf("%d %d %d\n", x, y, z);
    }
    return 0;
}