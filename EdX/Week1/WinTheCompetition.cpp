#ifdef JUDGE
#include <fstream>
std::ifstream cin("win.in");
std::ofstream cout("win.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <algorithm>
#include <vector>

int main()
{
	int pi, n;
	std::vector<int> pis;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pi;
		pis.push_back(pi);
	}
	sort(pis.begin(), pis.end());
	int count = 0;
	int tt = 18000;
	int i = 0;
	while(tt >= 0 && i < pis.size())
	{
		tt -= pis[i++];
		if (tt >= 0)
			count++;
	}
	cout << count;
	return 0;
}