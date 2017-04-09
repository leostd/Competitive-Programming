#include <iostream>
#include <map>
using namespace std;

int main()
{
	int i=1;
	map<string, string> r;
	r["Hajj"] = "Hajj-e-Akbar";
	r["Umrah"] = "Hajj-e-Asghar";
	string s;
	cin >> s;
	while(s != "*")
	{
		cout << "Case " << i << ": " << r[s] << endl; 
		cin >> s;
		i++;
	}
	return 0;
}