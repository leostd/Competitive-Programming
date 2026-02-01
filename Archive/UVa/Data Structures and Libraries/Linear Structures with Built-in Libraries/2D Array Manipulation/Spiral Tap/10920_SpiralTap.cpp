#include <iostream>
using namespace std;

int main()
{
	int ln, cl, border, count;
	long long int n, num;
	bool flag;
	while(scanf("%d %lli", &border, &num), (border || num))
	{	
		flag = true;
		n = count = 1;
		ln = cl = border - (border/2);
		while(n != num)
		{
			if(flag)
			{
				if(count + n < num)
				{
					n += count;
					ln += count;
				}
				else
				{
					for(int j = 0; j < count; j++)
					{
						if(num == n)
							break;
						n++;
						ln++;
					}
				}
				if(count + n < num)
				{
					n += count;
					cl -= count;
				}
				else
				{
					for(int j = 0; j < count; j++)
					{
						if(num == n)
							break;
						n++;
						cl--;
					}
				}
				flag = false;
				count++;
			}
			else
			{
				if(count + n < num)
				{
					n += count;
					ln -= count;
				}
				else
				{
					for(int j = 0; j < count; j++)
					{
						if(num == n)
							break;
						n++;
						ln--;
					}

				}
				if(count + n < num)
				{
					n += count;
					cl += count;
				}
				else
				{
					for(int j = 0; j < count; j++)
					{
						if(num == n)
							break;
						n++;
						cl++;
					}
				}
				flag = true;
				count++;
			}
		}
		printf("Line = %d, column = %d.\n", ln, cl);
	}
	return 0;
}