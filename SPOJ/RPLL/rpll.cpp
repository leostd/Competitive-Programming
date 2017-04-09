#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;

lli ma; // max area
ii p[3]; // points
string d[3]; // directions
int inc[3]; // increment


/* Heron's Formula' */
double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return (sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c)); 
}


/* Schoelace's Formula */
lli schoelace(const vector<lli>& x, const vector<lli>& y, int n)
{
    lli area = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }
    return ceil(abs(area)/2);
}
/* Euclidean Distance */
double ed(ii a, ii b) 
{
    lli t1 = (a.first - b.first) * (a.first - b.first);
    lli t2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(t1 + t2);
}

bool func(lli x)
{
    double sides[3];
    //ii np[3];
    vector<lli> X(3, 0.0), Y(3, 0.0);
    for (int i = 0; i < 3; i++)
    {
        //np[i] = p[i];
        X[i] = p[i].first;
        Y[i] = p[i].second;
        if (d[i] == "north")
            Y[i] += (inc[i]*x);
        else if (d[i] == "south")
            Y[i] -= (inc[i]*x);
        else if (d[i] == "east")
            X[i] += (inc[i]*x);
        else if (d[i] == "west")
            X[i] -= (inc[i]*x);
    }
    // sides[0] = ed(np[0], np[1]);
    // sides[1] = ed(np[0], np[2]);
    // sides[2] = ed(np[1], np[2]);
    // double r = heron(sides[0], sides[1], sides[2]); 
    lli r = schoelace(X, Y, 3);
    return  r <= ma;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lli", &ma);
        for (int j = 0; j < 3; j++)
            cin >> p[j].first >> p[j].second >> d[j] >> inc[j];
        lli lo = 0, hi = 1000000000, mid;
        while(hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            if (func(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (func(hi))
            printf("Scenario #%d: %lli\n", i, hi);
        else
            printf("Scenario #%d: %lli\n", i, lo);
    }

    return 0;
}