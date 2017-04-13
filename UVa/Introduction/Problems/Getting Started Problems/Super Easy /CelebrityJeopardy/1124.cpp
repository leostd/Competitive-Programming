#include <iostream>
#include <string>

int main()
{
	std::string eq;
	while(getline(std::cin, eq))
	{
		std::cout<<eq<<std::endl;
	}
	return 0;
}