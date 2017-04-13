#include <stdio.h>

int main()
{
	int a,b,c,t;
	scanf("%d", &t);
	
	for( int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if( a > 20 || b > 20 || c > 20)
			printf("Case %d: bad\n", i+1);
		else
			printf("Case %d: good\n", i+1);
	}
	return 0;
}