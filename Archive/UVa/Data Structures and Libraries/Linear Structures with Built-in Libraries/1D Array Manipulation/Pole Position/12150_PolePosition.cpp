#include <iostream>
#include <string.h>
using namespace std;

int cars[1000], n, c, p, aux;
bool flag;

int main()
{
	while(scanf("%d", &n), n != 0)
	{
		memset(cars, 0, sizeof(cars));
		flag = true;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &c, &p);
			aux = i + p;
			if( aux < 0 || aux >= n)
			{
				flag = false;
				continue;
			}
			else if(cars[aux] == 0)
			{
				cars[aux] = c;
			}
			else
			{
				flag = false;
			}
		}
		if(!flag)
			printf("-1");
		else
			for(int i = 0; i < n; i++)
			{
				printf("%d", cars[i]);
				if(i != n-1)
					printf(" ");
			}
		printf("\n");
	}
	return 0;
}