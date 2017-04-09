#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool coins[100], lt[100], g[100];
int p1ind[50], p2ind[50];

int main()
{
	int m, k, n, pi, coin;
	char c;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%*c");
		scanf("%d %d", &n, &k);
		memset(coins, true, sizeof(coins));
		memset(lt, false, sizeof(lt));
		memset(g, false, sizeof(g));
		coin = 0;
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &pi);
			for(int i = 0; i < pi; i++)
			{
				scanf("%d", &p1ind[i]);
			}
			for(int i = 0; i < pi; i++)
			{
				scanf("%d", &p2ind[i]);
			}
			scanf("%*c%c", &c);
			if( c == '=')
			{
				for(int i = 0; i < pi; i++)
				{
					lt[p1ind[i]-1] = g[p1ind[i]-1] = true;
					lt[p2ind[i]-1] = g[p2ind[i]-1] = true;
				}
			}
			else if(c == '<')
			{
				for(int i = 0; i < pi; i++)
				{
					lt[p2ind[i]-1] = false;
					lt[p1ind[i]-1] = true;
					g[p2ind[i]-1] = true;
					g[p1ind[i]-1] = false;
				}
			}
			else if(c == '>')
			{
				for(int i = 0; i < pi; i++)
				{
					lt[p2ind[i]-1] = true;
					lt[p1ind[i]-1] = false;
					g[p2ind[i]-1] = false;
					g[p1ind[i]-1] = true;
				}
			}
			memset(p1ind, -1, sizeof(p1ind));
			memset(p2ind, -1, sizeof(p2ind));
			if(coin == 0)
			{
				for(int i = 0; i < n; i++)
				{
					if((!g[i] || !lt[i]) && coin == 0)
					{
						coin = i + 1;
					}
					else if((!g[i] || !lt[i]) && coin != 0)
					{
						coin = 0;
						break;
					}
				}
			}
			
		}

		printf("%d\n\n", coin);
	}
	return 0;
}