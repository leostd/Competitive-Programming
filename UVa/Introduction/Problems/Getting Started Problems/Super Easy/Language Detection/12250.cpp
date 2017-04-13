#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>

std::map<std::string, std::string> languages;


int main()
{
	languages["HELLO"] = "ENGLISH";
	languages["HOLA"] = "SPANISH";
	languages["HALLO"] = "GERMAN";
	languages["BONJOUR"] = "FRENCH";
	languages["CIAO"] = "ITALIAN";
	languages["ZDRAVSTVUJTE"] = "RUSSIAN";
	int i=1;
	std::string word;
	std::cin >> word;
	while( word != "#" )
	{
		if( languages.count(word) == 1 )
			std::cout<<"Case "<<i<<": "<<languages[word]<<std::endl;
		else
			printf("Case %d: UNKNOWN\n", i);
		std::cin>>word;
		i++;
	}
	return 0;
}