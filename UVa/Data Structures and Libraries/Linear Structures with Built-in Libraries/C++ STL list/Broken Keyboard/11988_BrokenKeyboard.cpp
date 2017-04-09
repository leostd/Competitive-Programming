#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main()
{
	char ch, line[10004];
	unsigned int sz;
	list<char> text;
	while(scanf("%s", line) != EOF)
	{
		auto it = text.begin();
		sz = strlen(line);
		for(int i = 0; i < sz; ++i)
		{
			if(line[i] == '[')
				it = text.begin();
			else if(line[i] == ']')
				it = text.end();
			else
				text.insert(it,line[i]);
		}
		for(it = text.begin(); it != text.end(); ++it)
			printf("%c", *it);
		printf("\n");
		text.clear(); 
	}
	return 0;
}