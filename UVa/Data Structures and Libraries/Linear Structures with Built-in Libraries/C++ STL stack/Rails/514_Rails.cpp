#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int order[1001], n, current, index;
	while(scanf("%d", &n), n != 0)
	{
		while(true)
		{
			scanf("%d", &order[0]);
			if(order[0] == 0)
				break;
			for(int i = 1; i < n; ++i)
				scanf("%d", &order[i]);
			current = 1;
			index = 0;
			stack<int> s;
			while(current <= n)
			{
				s.push(current);
				while((!s.empty() && s.top() == order[index]) && index < n)
				{
					s.pop();
					++index;
				}
				++current;
			}
			if(s.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
}