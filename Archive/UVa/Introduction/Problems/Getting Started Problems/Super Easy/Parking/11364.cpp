#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	int t, x, n, acum=0;
	std::vector<int> shops;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			shops.push_back(x);
		}
		if(!std::is_sorted(shops.begin(), shops.end()))
			std::sort(shops.begin(), shops.end());
		for( int i = 0; i < shops.size(); i++)
			acum = i == shops.size()-1 ? acum + (shops[i]-shops[0]) : acum + (shops[i+1]-shops[i]);
		printf("%d\n", acum);
		shops.clear();
		acum = 0; 
	}
	return 0;
}