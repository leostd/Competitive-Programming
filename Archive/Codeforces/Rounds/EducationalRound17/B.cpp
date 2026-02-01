#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, int> p;

map<string, int> mp;
p ms[300005];

int main(){
    mp["USB"] = 0;
    mp["PS/2"] = 1;
    int types[3], mouses, type;
    string str;
    ll val, sum = 0, cm = 0;
    cin >> types[0] >> types[1] >> types[2] >> mouses;
    for (int i = 0; i < mouses; i++){
        cin >> val >> str;
        ms[i].first = val;
        ms[i].second = mp[str];
    }
    sort(ms, ms+mouses);
    for (int i = 0; i < mouses; i++){
        if (types[ms[i].second] > 0){
            types[ms[i].second]--;
            sum += ms[i].first;
            cm++;
        }
        else if(types[2] > 0){
            types[2]--;
            sum += ms[i].first;
            cm++;
        }
    }
    cout << cm << " " << sum << "\n";
    return 0;
}