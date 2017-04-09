#include <iostream>

int leftn[100005], rightn[100005];

int main()
{
	int s,b, l,r, sh;
	while(scanf("%d %d", &s, &b), (s != 0 && b != 0))
	{
		for(int i = 1; i <= s; i++)
		{
			leftn[i] = i - 1;
			rightn[i] = i + 1;
		}
		for(int i = 0; i < b; i++)
		{
			scanf("%d %d", &l, &r);
			if(leftn[l] == 0)
				printf("* ");
			else
				printf("%d ", leftn[l]);
			if(rightn[r] == s+1)
				printf("*\n");
			else
				printf("%d\n", rightn[r]);
			leftn[rightn[r]] = leftn[l];
			rightn[leftn[l]] = rightn[r];
		}
		printf("-\n");
	}
	return 0;
}