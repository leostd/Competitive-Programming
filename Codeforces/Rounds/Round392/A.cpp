#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int nums[105];
int n;
long long sum = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    sort(nums, nums+n);
    int max = nums[n-1];
    for (int i = 0; i < n; i++)
        sum += max - nums[i];
    cout << sum << "\n";
    return 0;
}