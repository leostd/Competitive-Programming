#include <iostream>
#include <map>
#include <vector>
using namespace std;

string lines="", line;

int main()
{
	int n, k, l;
	map<char, double> paid;
	char ch[2], c;
	double cents, dollars;
	scanf("%d", &n);
	while(n--)
	{
		dollars = 0;
		lines = "";
		paid.clear();
		scanf("%d", &k);
		while(k--)
		{
			scanf("%s %lf", ch, &cents);
			paid[ch[0]] = cents;
		}
		scanf("%d", &l);
		scanf("%*c");
		while(l--)
		{
			do
			{
				c = getchar();
				if(paid.count(c) > 0)
					dollars += paid[c];
			}while(c != '\n');
		}
		for(int i = 0; i < lines.length(); i++)
		{
			if(paid.count(lines[i]) > 0)
				dollars += paid[lines[i]];
		}
		printf("%.2lf$\n",dollars / 100 );
	}
	return 0;
}