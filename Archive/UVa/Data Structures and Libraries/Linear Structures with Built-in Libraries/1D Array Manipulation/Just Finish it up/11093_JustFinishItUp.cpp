#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int qis[100005], pis[100005], sum[100005];
int tot, n;

int solve()
{
	int s=0, i, tank=0;
	while(1)
	{
		tank = 0;
		for(i = 0; i < n; i++)
		{
			tank += sum[(s+i) % n];
			if (tank < 0)
			{
				if(i == 0)
					s++;
				else
					s = s + i;
				break;
			}
		}
		if(tank >= 0)
			return s+1;
		else if(s > n)
			return -1;
	}

}

int main()
{	
	int t, x, r, c=1;
	scanf("%d", &t);
	while(t--)
	{
		tot = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &pis[i]);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &qis[i]);
			sum[i] = pis[i] - qis[i];
		}
		r = solve();
		if(r < 0)
			printf("Case %d: Not possible\n", c);
		else
			printf("Case %d: Possible from station %d\n", c, r);
		c++;
	}
	return 0;
}