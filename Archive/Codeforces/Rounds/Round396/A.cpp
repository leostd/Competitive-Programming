#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long int lli;

string a, b;


int main(){
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int ans;
    if (a == b)
        ans = -1;
    else
        ans = max(n, m);
    printf("%d\n", ans);
    return 0;
}