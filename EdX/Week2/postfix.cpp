#ifdef JUDGE
	#include <fstream>
	std::ifstream cin("postfix.in");
	std::ofstream cout("postfix.out");
#else
	#include <iostream>
	using std::cin;
	using std::cout;
#endif

#include <stack>
#include <stdlib.h>
#include <ctype.h>

typedef long long int lli;

int main()
{
	char ch;
	std::stack<int> s;
	while(cin >> ch)
	{
		if (isdigit(ch))
			s.push(ch - '0');
		else
		{
			int a,b, c;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			if (ch == '+')
				c = a + b;
			else if (ch == '-')
				c = b - a;
			else if (ch == '*')
				c = a * b;
			s.push(c);
		}
	}
	cout << s.top() << "\n";
	return 0;
}