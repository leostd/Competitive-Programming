#include <iostream>
using namespace std;

int matrix[3][3], tmp[3][3];

void solve()
{
	bool flag = true;
	int n = -1;
	while(1)
	{
		flag = false;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(matrix[i][j] == 1)
				{
					flag = true;
					n++;
					break;
				}
			}
			if(flag)
				break;
		}

		if(!flag)
			break;
		tmp[0][0] = (matrix[0][1] + matrix[1][0]) % 2;
		tmp[0][1] = (matrix[0][0] + matrix[1][1] + matrix[0][2]) % 2;
		tmp[0][2] = (matrix[0][1] + matrix[1][2]) % 2;
		tmp[1][0] = (matrix[0][0] + matrix[1][1] + matrix[2][0]) % 2;
		tmp[1][1] = (matrix[1][0] + matrix[0][1] + matrix[1][2] + matrix[2][1]) % 2;
		tmp[1][2] = (matrix[0][2] + matrix[1][1] + matrix[2][2]) % 2;
		tmp[2][0] = (matrix[1][0] + matrix[2][1]) % 2;
		tmp[2][1] = (matrix[2][0] + matrix[1][1] + matrix[2][2]) % 2;
		tmp[2][2] = (matrix[2][1] + matrix[1][2]) % 2;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				matrix[i][j] = tmp[i][j];
	}
	printf("%d", n);

}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				scanf("%1d", &matrix[i][j]);
		solve();
		printf("\n");
	}
	return 0;
}