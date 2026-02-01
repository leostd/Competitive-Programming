#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	int prev, x, n, num;
	vector<bool> flags;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 1)
		{
			printf("Jolly\n");
			scanf("%*d");
			continue;
		}
		int diff;
		bool jolly;
		flags = vector<bool>(n-1);
		scanf("%d", &x);
		for(int i = 0; i < n; i++)
		{
			prev = x;
			if(i < n-1)
				scanf("%d", &x);
			diff = abs(x-prev);
			if(diff >= 1 && diff <= n-1) flags[diff-1] = true;
		}
		jolly = true;
		for(auto it = flags.begin(); it != flags.end(); ++it)
		{
			if(!(*it)) 
			{
				jolly = false;
				break;
			}
		}
		if(jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
		
	}
	return 0;
}