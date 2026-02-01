#include <bits/stdc++.h>
using namespace std;

string notes[12] = {"DO", "DO#", "RE", "RE#", "MI", "FA", "FA#", "SOL", "SOL#", "LA", "LA#", "SI"};
map<string, int> denotes;

void init(){
	denotes["DO"] = 0;
	denotes["DO#"] = 1;
	denotes["RE"] = 2;
	denotes["RE#"] = 3;
	denotes["MI"] = 4;
	denotes["FA"] = 5;
	denotes["FA#"] = 6;
	denotes["SOL"] = 7;
	denotes["SOL#"] = 8;
	denotes["LA"] = 9;
	denotes["LA#"] = 10;
	denotes["SI"] = 11;
}

int main(){
	init();
	int a;
	string b;
	cin >> a >> b;
	int aux = denotes[b];
	cout << notes[(aux-a+12) % 12] << "\n";
	return 0;
}