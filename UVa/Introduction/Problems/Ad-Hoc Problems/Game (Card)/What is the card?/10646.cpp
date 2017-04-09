#include <iostream>
#include <stdio.h>
#include <string.h>

bool check[52];
char cards[52][3];

int main()
{
	long long int tc, cases=1;
	int Y, aux, value, j;
	scanf("%lli", &tc);
	while(tc--)
	{
		for(int i = 0; i < 52; i++)
			scanf("%s", &cards[i]);
		memset(check, false, sizeof(check));
		Y = 0;
		aux = 26;
		for(int i = 0; i < 3; i++)
		{
			if( cards[aux][0] >= '2' && cards[aux][0] <= '9')
				value = cards[aux][0] - '0';
			else
				value = 10;
			Y += value;
			check[aux--] = true;
			value = 10 - value;
			while(value--)
				check[aux--] = true;
		}
		for( j = 0; Y != 0, j < 52; j++)
		{
			if(!check[j])
				Y--;
			if(Y == 0)
				break;
		}
		printf("Case %lli: %s\n", cases++, cards[j] );
	}
	return 0;
}