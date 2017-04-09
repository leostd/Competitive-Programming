#include <iostream>
#include <cmath>
#include <climits>

int main()
{
	unsigned int vertices[40000], sum[40000], n, nvertices, neighbor;
	long long int maxsum, vertsum;
	while(scanf("%u", &n) != EOF)
	{
		maxsum = LLONG_MIN;
		nvertices = pow(2,n);
		for(int i = 0; i < nvertices; i++)
			scanf("%u", &vertices[i]);
		for(int i = 0; i < nvertices; i++)
		{
			vertsum = 0;
			for(int j = 0; j < n; j++)
			{
				neighbor = i ^ (1 << j);
				vertsum += vertices[neighbor];
			}
			sum[i] = vertsum;
		}
		for(int i = 0; i < nvertices; i++)
		{
			for(int j = 0; j < n; j++)
			{
				neighbor = i ^ (1 << j);
				vertsum = sum[i] + sum[neighbor];
				if(vertsum > maxsum)
					maxsum = vertsum;
			}
		}
		printf("%llu\n", maxsum);
	}
return 0;

}