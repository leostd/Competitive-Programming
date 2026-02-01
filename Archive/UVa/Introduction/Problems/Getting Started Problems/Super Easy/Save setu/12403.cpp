#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
	int t, k, acum=0;
	std::string w;
	scanf("%d", &t);
	for(int i=0; i < t; i++)
	{
		std::cin >> w;
		if( w == "report")
			printf("%d\n", acum);
		else
		{
			scanf("%d", &k);
			acum += k;
		}
	}
	return 0;
}