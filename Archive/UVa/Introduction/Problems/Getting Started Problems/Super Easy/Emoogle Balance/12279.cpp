#include <stdio.h>

int main()
{
	int n, acum, z, v;
	z = 0;
	acum = 1;
	scanf("%d", &n);
	while(n != 0)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &v);
			if ( v == 0 )
				z++;
		}
		printf("Case %d: %d\n", acum, n-(2*z));
		acum++;
		z = 0;
		scanf("%d", &n);
	}
	return 0;
}