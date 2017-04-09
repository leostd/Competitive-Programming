#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull n, k;
    cin >> n >> k;
    vector<ull> divs;
    ull sq = sqrt(n);
    for (int i = 1; i <= sq; i++){
        if (n % i == 0){
            if (n/i == i)
                divs.push_back(i);
            else{
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    if (divs.size() < k)
        printf("-1\n");
    else
        cout << divs[k-1] << "\n";
    return 0;
}