	#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int s;
long long int w = 0; //ways
vector<long long int> memo;

long long int davis(int c){
    if (c == 1)
        return 1;
    else if ( c == 2)
        return 2;
    else if (c == 3)
        return 4;
    else if (c > 0){
        if (memo[c] == -1)
        {
            memo[c] = davis(c-1) + davis(c-2) + davis(c-3);
        }
        return memo[c];
    }
    return 0;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    memo = vector<long long int>(37,-1);
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    cin >> n;
    s = 36;
    davis(36);
    while(n--){
        cin >> s;
        printf("%lli\n", memo[s]);
        w = 0;
    }
    return 0;
}
