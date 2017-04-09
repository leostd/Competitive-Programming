#include <iostream>

int main()
{
	long unsigned n, a, b, check;
	unsigned int j;
	bool toa;
	while(scanf("%lu", &n), n != 0)
	{
		j = 0;
		a = b = 0;
		toa = true;
		while( (1 << j) <= n )
		{
			check = (1 << j) & n;
			if(check > 0)
			{
				if(toa)
					a = (1 << j) | a;
				else
					b = (1 << j) | b;
				toa = !toa;
			}
			j++;
		}
		printf("%lu %lu\n", a, b);
	}
	return 0;
}