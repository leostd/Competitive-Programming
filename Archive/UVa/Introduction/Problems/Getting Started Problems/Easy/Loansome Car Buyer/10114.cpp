#include <stdio.h>
#include <map>

int main()
{
	double dp, loan, p, aux, prc, pay;
	int months, pr, m;
	std::map<int, double> map;
	scanf("%d %lf %lf %d", &months, &dp, &loan, &pr);
	while(months >= 1)
	{
		aux = loan + dp;
		for(int i = 0; i < pr; i++)
		{
			scanf("%d %lf", &m, &p);
			map[m] = p;
		}
		prc = map[0];
		pay = loan/months;
		aux -= (aux*prc);
		if ( loan <  aux )
		{
			printf("0 months\n");
		}
		else
		{
			for(int i = 1; i <= months; i++)
			{	
				if(map.count(i))
					prc = map[i];
				aux -= (aux*prc);
				loan -= pay;
				if( loan < aux && i > 1 )
				{
					printf("%d months\n", i);
					break;
				}
				else if( loan < aux && i == 1 )
				{
					printf("1 month\n");
					break;
				}
			}
		}
		scanf("%d %lf %lf %d", &months, &dp, &loan, &pr);
		map.clear();
	}
	return 0;
}