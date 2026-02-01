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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int lli;

lli mmerge(vi lhalf, vi rhalf, vi &a)
{
    int ls = lhalf.size();
    int rs = rhalf.size();
    vi sa;
    int i, j;
    lli inv = 0;
    i = j = 0;
    for (int k = 0; k < ls + rs; k++)
    {
        if (i == ls)
            sa.push_back(rhalf[j++]);
        else if (j == rs)
            sa.push_back(lhalf[i++]);
        else if (i < ls && j < rs)
        {
            if (rhalf[j] < lhalf[i])
            {
                sa.push_back(rhalf[j]);
                inv += (ls - i);
                j++;
            }
            else
            {
                sa.push_back(lhalf[i]);
                i++;
            }
        }
    }
    a = sa;
    return inv;
}

long long count_inversions(vector<int> &a) {
    if (a.size() <= 1)
        return 0;
    else
    {
        int mid = floor((a.size()-1)/2);
        vi lhalf = vi(a.begin(), a.begin() + mid +1);
        vi rhalf = vi(a.begin() + mid + 1, a.end());
        lli l = count_inversions(lhalf);
        lli r = count_inversions(rhalf);
        lli t = mmerge(lhalf, rhalf, a);
        return l + r + t;
    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
