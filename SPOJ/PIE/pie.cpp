#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define PI 3.14159265358979323846264338327950
#define EPS 0.00001
using namespace std;

int main()
{
    int n, f, tc;
    scanf("%d", &tc);
    while(tc--)
    {
        f=0;
        scanf("%d %d", &n, &f);
        vector<int> rs(n, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &rs[i]);
            rs[i] = rs[i] * rs[i];
        }
        sort(rs.begin(), rs.end());
		double lo = 0,hi = 4e8,mi;
		for(int it = 0;it < 43;++it){
			mi = (lo + hi) / 2;
			
			int cont = 0;
			
			for(int i = n - 1;i >= 0 && cont <= f;--i)
				cont += (int)floor(M_PI * rs[i] / mi);
			
			if(cont > f) lo = mi;
			else hi = mi;
		}
        printf("%.4f\n", lo);
    }
    return 0;
}