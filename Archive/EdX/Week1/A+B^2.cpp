#ifdef JUDGE
#include <fstream>
std::ifstream cin("aplusbb.in");
std::ofstream cout("aplusbb.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long int a, b, c;
	cin >> a >> b;
	c = b * b + a;
	cout << c;
	return 0;
}