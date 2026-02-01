#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	char str[53];
	char test[3] = {'a','b', 'c'};
	int ints[3] = {1,2,3};
	while(scanf("%s", str), str[0] != '#')
	{
		if(next_permutation(str, str+strlen(str)))
			printf("%s\n", str);
		else
			printf("No Successor\n");
	}
	return 0;
}