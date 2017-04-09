#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int rfp=1, n, np, aux;
	double compliance, bestcomp, price, bestprice;
	string name, bestname, s;
	while(scanf("%d %d", &n, &np), (n != 0 || np != 0))
	{
		if(rfp > 1)
			printf("\n");
		cin.ignore();	
		for(int i = 0; i < n; i++)
		{
			getline(cin, s);
		}
		for(int i = 0; i < np; i++)
		{
			getline(cin, name);
			scanf("%lf %d", &price, &aux);
			cin.ignore();	
			for(int i = 0; i < aux; i++)
			{
				getline(cin, s);
			}
			compliance = (float)aux/ (float)n;
			if(compliance > bestcomp || (compliance == bestcomp && price < bestprice))
			{
				bestcomp = compliance;
				bestprice = price;
				bestname = name;
			}			
		}
		printf("RFP #%d\n", rfp);
		cout << bestname << endl;
		bestcomp = -10980988;
		bestprice = 1E37;
		rfp++;
	}
	return 0;
}