#include <iostream>
using namespace std;

char N[500][500], n[500][500];
int a, b;

int count()
{
	int c, t;
	c = t = 0;
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < a; j++)
		{
			c = 0;
			for(int k = 0; k < b; k++)
			{
				for(int l = 0; l < b; l++)
				{
					if(k + i < a && l + j < a)
					{
						if(n[k][l] == N[k+i][l+j])
							c++;
					}
				}
			}
			if(c == b*b)
				t++;
		}
	}
	return t;
}

void rotate()
{
	 char aux[500][500];
	 for(int i = 0; i < b; i++)
	 	for(int j = 0; j < b; j++)
	 		aux[i][j] = n[b-j-1][i];
	 for(int i = 0; i < b; i++)
	 	for(int j = 0; j < b; j++)
	 		n[i][j] = aux[i][j];
}

int main()
{
	while(scanf("%d %d", &a, &b), (a != 0 && b != 0))
	{
		for(int i = 0; i < a; i++)
				scanf("%s",N[i]);

		for(int i = 0; i < b; i++)
				scanf("%s", n[i]);
		for(int i = 0; i < 4; i++)
		{
			if(i)
				putchar(' ');	
			printf("%d", count());
			rotate();
		}
		printf("\n");
	}
	return 0;
}