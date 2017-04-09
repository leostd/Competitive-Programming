#include <stdio.h>

int main()
{
	int b, n, ri, d, c, v;
	bool flag = true;
	scanf("%d %d", &b, &n);
	while(b != 0 || n != 0)
	{
		int *bs = new int[b];
		for(int i = 0; i < b; i++)
		{
			scanf("%d", &bs[i]);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &d, &c, &v);
			bs[d-1] -= v;
			bs[c-1] += v;
		}
		for(int i = 0; i < b; i++)
		{
			if(bs[i] < 0)
				flag = false;
		}
		if( flag )
			printf("S\n");
		else
			printf("N\n");
		delete[] bs;
		flag=true;
		scanf("%d %d", &b, &n);
	}
	return 0;
}