#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
   map<char, int> ac, bc; // chars counters
   int dc  = 0; // delete counter
   int aux;
   for (int i = 0; i < a.size(); i++)
       ac[a[i]]++;
    for (int i = 0; i < b.size(); i++)
        bc[b[i]]++;
    for (auto it = ac.begin(); it != ac.end(); ++it)
    {
        int w = (bc.count(it->first)?bc[it->first]:0);
        aux = abs(it->second - w);
        dc += aux;
        bc[it->first] = it->second;
    }
    for (auto it = bc.begin(); it != bc.end(); ++it)
    {
        if (ac.count(it->first))
            continue;
        dc += it->second;
        ac[it->first] = it->second;
    }
    return dc;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
