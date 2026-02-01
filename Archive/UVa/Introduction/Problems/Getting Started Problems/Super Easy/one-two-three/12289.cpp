#include <string>
#include <iostream>
unsigned int hd(std::string a, std::string b)
{
	if(a.size() != b.size() )
		return -1;
	int diff = 0;
	for(unsigned int i = 0; i < a.size(); i++ )
	{
		if( a[i] != b[i] )
			diff++;
	}
	return diff;
}

int main()
{
	int t;
	std::string number;
	scanf("%d", &t);
	for( int i = 0; i < t; i++)
	{
		std::cin >> number;
		if( hd(number, "one") == 1 || hd(number, "one") == 0)
			printf("1\n");
		else if( hd(number, "two") == 1 || hd(number, "two") == 0)
			printf("2\n");
		else
			printf("3\n"); 
	}
	return 0;
}