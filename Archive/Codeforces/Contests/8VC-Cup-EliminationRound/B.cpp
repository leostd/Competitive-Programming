#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<string> eb, pb; //enemy ball, poland ball. words
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> intersec, diffpb, diffeb;
    pb = vector<string>(n, "");
    eb = vector<string>(m, "");
    intersec = vector<string>(n+m, "");
    diffpb = diffeb = intersec;
    for (int i = 0; i < n; i++)
        cin >> pb[i];
    for (int i = 0; i < m; i++)
        cin >> eb[i];
    sort(pb.begin(), pb.end());
    sort(eb.begin(), eb.end());
    auto it=std::set_intersection (pb.begin(), pb.end(), eb.begin(), eb.end(), intersec.begin());
    intersec.resize(it-intersec.begin());
    // if (intersec.size() == n && n == m && n % 2 == 0)
    //     printf("YES\n");
    // else if (intersec.size() == n && n == m && n % 2 != 0)
    //     printf("NO\n");
    auto itpb = set_difference(pb.begin(), pb.end(), intersec.begin(), intersec.end(), diffpb.begin());
    auto iteb = set_difference(eb.begin(), eb.end(), intersec.begin(), intersec.end(), diffeb.begin());
    diffeb.resize(iteb-diffeb.begin());
    diffpb.resize(itpb-diffpb.begin());

    if (intersec.size() % 2 == 0)
    {
        if (diffeb.size() == diffpb.size()){
            printf("NO\n");
        }
        else if (diffeb.size() > diffpb.size())
            printf("NO\n");
        else
            printf("YES\n");
            
    }
    else
    {
        if (diffeb.size() == diffpb.size()){
            printf("YES\n");
        }
        else if (diffeb.size() > diffpb.size())
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}