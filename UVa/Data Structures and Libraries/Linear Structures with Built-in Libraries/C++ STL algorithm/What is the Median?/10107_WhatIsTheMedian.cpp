#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long unsigned x, mid;
	int size;
	vector<long long unsigned> vec;
	while(scanf("%llu", &x) != EOF)
	{
		vec.push_back(x);
		nth_element(vec.begin(), vec.begin() + vec.size()/2, vec.end());
		mid = vec[vec.size()/2];
		if( vec.size() % 2 == 0)
		{
			nth_element(vec.begin(), vec.begin() + vec.size()/2 - 1, vec.end());
			mid += vec[vec.size()/2-1];
			mid /= 2;
		}
		printf("%llu\n", mid);
	}
	return 0;
}