#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

typedef long long int lli;

map<lli, lli> m;

lli coins(lli n){
    if (n == 1 || n == 0)
        return n;
    else if (m.count(n))
        return m[n];
    else{
        m[n] = max(n, coins(n/2) + coins(n/3) + coins(n/4));
        return m[n];
    }
}

int main(){
    lli n;
    while(scanf("%lli", &n) != EOF){
        m.clear();
        printf("%lli\n", coins(n));
    }
    return 0;
}