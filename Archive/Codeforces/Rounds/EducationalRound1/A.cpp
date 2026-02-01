#include <bits/stdc++.h>
using namespace std;


long long f(long long int x){
    return x*(x+1)/2L;
}

int main(){
    int t;
    long long pows[60],n;
    scanf("%d", &t);
    long long p = 1;
    int i = 0;
    long long acum = 0;
    while(p < (long long)(1e9)){
        acum += p;
        pows[i++] = acum;
        p *= 2;
    }
    for(int j = 0; j < t; j++){
        cin >> n;
        acum = f(n);
        int idx = (lower_bound(pows, pows+i, n)-pows);
        if (idx < 0) idx = i-1;
        long long x = pows[idx];
        cout << acum - 2*x<< "\n";
    }
    return 0;
}