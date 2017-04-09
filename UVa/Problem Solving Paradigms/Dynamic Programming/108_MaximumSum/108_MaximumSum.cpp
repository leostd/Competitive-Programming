#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <string.h>
#include <limits.h>
#define ROW 100
#define COL 100
using namespace std;

int N, m[101][101];

int kadane(int arr[], int *start, int *finish, int n)
{
    int sum = 0, maxsum = -1;
    *finish = -1;

    int lstart =  0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            lstart = i+1;
            sum = 0;
        }
        else if (sum > maxsum)
        {
            maxsum = sum;
            *start = lstart;
            *finish = i;
        }
    }
    if (*finish != -1)
        return maxsum;
    maxsum = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxsum)
        {
            *start = *finish = i;
            maxsum = arr[i];
        }
    return maxsum;
}

int findMaxSum()
{
    int maxsum = INT32_MIN, fl, fr, ft, fb;
    int left, right, i;
    int temp[ROW], sum, start, finish;
    bool allneg = true;
    for (left = 0; left < N; ++left)
    {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < N; ++right)
        {
            for (i = 0; i < N; ++i)
                temp[i] += m[i][right];
            sum = kadane(temp, &start, &finish, N);
            if (sum > 0)
                allneg = false;
            if (sum > maxsum)
                maxsum = sum;
        }
        if (allneg)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    maxsum = (m[i][j] > maxsum) ? m[i][j] : maxsum;
        }
    }
    return maxsum;
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &m[i][j]);
        int ans = findMaxSum();
        printf("%d\n", ans);
    }
    return 0;
}