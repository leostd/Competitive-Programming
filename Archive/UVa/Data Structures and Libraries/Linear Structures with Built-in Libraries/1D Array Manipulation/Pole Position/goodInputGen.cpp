#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
	int tc, n, x, y;
	vector<bool> check, cars(10000,false);
	scanf("%d", &tc);
	srand(time(0));
	for(int i = 0; i < tc; i++)
	{
		while(scanf("%d", &n), n > 1000 || n < 2)
			perror("Error: N > 1000\n");
		printf("%d\n", n);
		check = vector<bool>(n, false);
		for(int i = 0; i < n; i++)
		{
			x = rand() % 1000;
			while(check[x])
				x = rand() % 1000;
			check[x] = true;
			y = rand() % 10000;
			while(cars[y])
				y = rand() % 10000;
			cars[y] = true;
			printf("%d %d\n",y,x);
		}
	}
	printf("0\n");
	return 0;
}