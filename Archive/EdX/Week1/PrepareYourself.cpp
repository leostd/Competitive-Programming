#ifdef JUDGE
#include <fstream>
std::ifstream cin("prepare.in");
std::ofstream cout("prepare.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <algorithm>
#define MAX(a, b) (a > b) ? a : b

typedef long long int lli;

lli pis[100], tis[100];

int main()
{
	int a, b;
	int days, ti, pi;
	lli maxSum, maxSumLackTheory, maxSumLackPractice;
	maxSum = maxSumLackPractice = maxSumLackTheory = 0;
	bool lackTheory, lackPractice;
	cin >> days;
	lackPractice = lackTheory = true;
	for (int i = 0; i < days; i++)
		cin >> pis[i];
	for (int i = 0; i < days; i++)
		cin >> tis[i];

	for(int i = 0; i < days; i++)
	{

		if(pis[i] > tis[i])
		{
			maxSum += pis[i];
			lackPractice = false;
		}
		else
		{
			maxSum += tis[i];
			lackTheory = false;
		}
	}

	if (!lackPractice && !lackTheory)
		cout << maxSum << std::endl;
	else if (lackTheory)
	{
		maxSumLackTheory = maxSum + tis[0] - pis[0];
		for (int i = 1; i < days; i++)
		{
			if(maxSumLackTheory < maxSum - pis[i]+ tis[i])
				maxSumLackTheory = maxSum - pis[i]+ tis[i];
		}
		cout << maxSumLackTheory << std::endl;
	}
	else
	{
		maxSumLackPractice = maxSum - tis[0] + pis[0];
		for(int i = 1; i < days; i++)
		{
			if (maxSumLackPractice < maxSum + pis[i] - tis[i])
				maxSumLackPractice = maxSum + pis[i] - tis[i];
		}
		cout << maxSumLackPractice << std::endl;
	}
	return 0;
}