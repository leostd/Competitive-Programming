/*
	This code seems to work with the test case,
	but it gets RTE when I submitted it.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> top, pile, aux;
map<string, int> values;
int main()
{
	long long int tc, c=1;
	int value;
	string card, t1, t2, t3;
	int Y=0;
	values["A"] = 10;
	values["2"] = 2;
	values["3"] = 3;
	values["4"] = 4;
	values["5"] = 5;
	values["6"] = 6;
	values["7"] = 7;
	values["8"] = 8;
	values["9"] = 9;
	values["J"] = 10;
	values["Q"] = 10;
	values["K"] = 10;
	scanf("%lli", &tc);
	while(tc--)
	{
		for(int i = 0; i < 52; i++)
		{
			cin >> card;
			pile.push_back(card);	
		}
		top = vector<string>(pile.rbegin(), pile.rbegin()+25);
		pile = vector<string>(pile.rbegin()+25, pile.rend());
		for(int i=0; i < 3; i++)
		{
			card = pile[0];
			value = values[card.substr(0,1)];
			Y += value;
			pile.erase(pile.begin(), pile.begin() + 11 - value);
		}
		for(auto it = pile.begin(); it != pile.end(); ++it)
			top.push_back(*it);
		card = top[top.size() - Y];
		cout << "Case " << c++ << ": " << card << endl;
		pile.clear();
		top.clear();
		Y = 0; 
	}
	cout << endl;
	return 0;
}