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

vector<lli> nums;

int main(){
    lli input, n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());
    if (nums[n-1] + nums[n-2] > nums[n-3] && 
        nums[n-1] + nums[n-3] > nums[n-2] &&
        nums[n-2] + nums[n-3] > nums[n-1])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}