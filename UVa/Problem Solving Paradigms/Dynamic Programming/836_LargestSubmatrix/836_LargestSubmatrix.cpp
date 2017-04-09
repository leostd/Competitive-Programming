#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <stack>
using namespace std;

int matrix[25][25], summ[25][25], maxm, n;
string smatrix[25];

int min3(int a, int b, int c)
{
    if (b < a)
        return min(b, c);
    else
        return min(a, c);
}

int maxArea(int hist[])
{
    stack<int> s;
    int maxarea = 0, area, i = 0, tp;
    while(i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else 
        {
            tp = s.top();
            s.pop();
            area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            if (area > maxarea)
                maxarea = area;
        }
    }
    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        maxarea = (area > maxarea) ? area : maxarea;
    }
    return maxarea;
}

int maxRectangle()
{
    int result = maxArea(matrix[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (matrix[i][j])
                matrix[i][j] += matrix[i-1][j];
        result = max(result, maxArea(matrix[i]));
    }
    return result;
}
int main()
{
    int t;
    bool first = true;
    scanf("%d\n\n", &t);
    while(t--)
    {
        int i = 0, j = 0, maxm = 0;
        char c;
        while( c = getchar(), c != '\n' && c != EOF)
        {
            matrix[i][j++] = c - '0';
            while(c = getchar(), c != '\n' && c != EOF)
                matrix[i][j++] = c - '0';
            i++;
            j = 0;
        }
        n = i;
        if (!first)
            printf("\n");
        first = false;
        int ans = maxRectangle();
        printf("%d\n", ans);
    }
    return 0;
}