#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;



int main()
{
    string number;
    int t,k;
    scanf("%d\n", &t);
    while(t--)
    {
        cin >> number >> k;
        if (number.size() == k)
        {
            printf("\n");
            continue;
        }
        vector<int> digits[10];
        int idx[10] = {0};
        for (int i = 0; i < number.size(); i++)
            digits[number[i] - '0'].push_back(i);
        int lastIdx = -1, pos = 0, maxp = number.size() - k, printed = 0;
        for (int i = 9; i >= 0; i--)
        {
            while (idx[i] < digits[i].size() && digits[i][idx[i]] < pos)
                idx[i]++;
            if (idx[i] == digits[i].size())
                continue;
            if (k - abs(digits[i][idx[i]] - pos) >= 0)
            {
                k -= (digits[i][idx[i]] - pos);
                pos = digits[i][idx[i]];
                printf("%d", i);
                ++idx[i];
                ++printed;
                ++pos;
                if (printed == maxp)
                    break;
                i = 10;
            }
        }
        printf("\n");
    }
    return 0;
}