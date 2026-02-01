#ifdef JUDGE
	#include <fstream>
	std::ifstream cin("brackets.in");
	std::ofstream cout("brackets.out");
#else
	#include <iostream>
	using std::cin;
	using std::cout;
#endif

#include <stack>
#include <string>

int main()
{
	std::string line;
	char ind;
	bool flag = true;
	bool first = true;
	while(getline(cin, line))
	{
		if(first)
			first = false;
		else
			cout << "\n";
		flag = true;
		std::stack<char> s;
		for (int i = 0; i < line.size(); ++i)
		{
			ind = line[i];
			if (ind == '(')
				s.push(ind);
			else if (ind == '[')
				s.push(ind);
			else if (ind == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
				{
					cout << "NO";
					flag = false;
					break;
				}
			}
			else if (ind == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else
				{
					cout << "NO";
					flag = false;
					break;
				}
			}
		}
		if (flag && s.empty())
			cout << "YES";
		else if (flag)
			cout << "NO";
	}
	return 0;
}