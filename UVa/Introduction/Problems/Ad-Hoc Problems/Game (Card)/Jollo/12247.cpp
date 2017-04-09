//#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//using namespace std;

bool endIn(int a, int b, int c, int d, int e)
{
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
		return false;
	return true;
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

bool check[52];

int main()
{
	int p1[3], p2[2], aux, c=0, max, maxind;
	int z[3] = {0, 0, 0};
	bool flag, win[2], sup[3];
	while (scanf("%d %d %d %d %d", &p1[0], &p1[1], &p1[2], &p2[0], &p2[1]), endIn(p1[0], p1[1], p1[2], p2[0], p2[1]))
	{
		qsort(p1, 3, sizeof(int), compare);
		qsort(p2, 2, sizeof(int), compare);
		memset(check, false, sizeof(check));
		memset(z, 0, sizeof(z));
		memset(win, false, sizeof(win));
		memset(sup, false, sizeof(sup));
		flag = false;
		c = max = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (p1[i] > p2[j]){
					z[i]++;
					if( !win[j] && !sup[i])
					{
						win[j] = true;
						sup[i] = true;
					}
				}
			}
		}
		for(int i = 0; i < 3; i++)
		{
			if(z[i] > 0)
				c += z[i];
			if(z[i] > 2)
			{
				flag = true;
				aux = i;
			}
		}
		if (c >= 4 || (win[0] && win[1]) || (p1[1] == 50 && p1[2] == 51))
		{
			printf("-1\n");
			continue;
		}
		check[p1[0]] = true;
		check[p1[1]] = true;
		check[p1[2]] = true;
		check[p2[0]] = true;
		check[p2[1]] = true;
		if(flag)
		{
			for(int i = 0; i < 3; i++)
			{
				if( i != aux )
				{
					if(p1[i] > max)
					{
						max = p1[i];
						maxind = i;
					} 	
				}
			}
			aux = max;
		}
		else
		{
			if(c == 3)
			{
				aux = p1[2];
				maxind = 2;
			}
			else if( c == 0)
			{
				aux = 1;
				maxind = 0;
			}
			else if( c == 1 )
			{
				aux = p1[1];
				maxind = 1;
			}
			else
			{
				aux = z[2] == 2 ? p1[1] : p1[2];
				maxind = z[2] == 2 ? 1 : 2 ;
			}
		}
		while (check[aux])
			if(aux < 52)
				aux++;
			else
			{
				aux = p1[--maxind];
				c++;
			}
		printf("%d\n", aux);
	}
	return 0;
}