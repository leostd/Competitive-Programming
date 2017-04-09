#include <bitset>
#include <iostream>
using namespace std;

int main()
{
	bitset<1000010> bits;
	bool conflict;
	int n,m,a,b, r;
	while(scanf("%d %d", &n, &m), n != 0 || m != 0)
	{
		bits.reset();
		conflict = false;
		while(n--)
		{
			scanf("%d %d", &a, &b);
			for(int i = a; i < b && !conflict; i++)
			{
				if(bits[i]) 
					conflict = true;
				bits[i] = 1;
			}
		}
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &r);
			while(a < 1E6 || b < 1E6 && !conflict)
			{
				if(b < 1E6)
					for(int i = a; i < b; i++)
					{
						if(bits[i])
							conflict = true;
						bits[i] = 1;
					}
				else
					for(int i = a; i < 1E6; i++)
					{
						if(bits[i])
							conflict = true;
						bits[i] = 1;
					}
				a += r;
				b += r;
			}
		}
		if(conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}
	return 0;
}