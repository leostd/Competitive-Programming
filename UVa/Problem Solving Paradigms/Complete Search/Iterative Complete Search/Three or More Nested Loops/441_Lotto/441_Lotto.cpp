#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    int ns[20];
    bool first = true;
    while(scanf("%d", &k), k != 0) {
        if (!first)
            printf("\n");
        first = false;
        for (int i = 0; i < k; ++i)
            scanf("%d", &ns[i]);
        //sort(ns, ns+k); 
        for (int i = 0; i < k-5; ++i) 
            for (int j = i+1; j < k-4; ++j)
                for (int l = j+1; l < k-3; ++l)
                    for (int m = l+1; m < k-2;++m)
                        for (int n = m+1; n < k-1; ++n)
                            for (int o = n+1; o < k; ++o)
                                printf("%d %d %d %d %d %d\n", ns[i], ns[j], ns[l], ns[m], ns[n], ns[o]);
    }
    return 0;
}