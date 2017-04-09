#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>	
#include <sstream>
using namespace std;

struct result{
	int nproblems, penalty, nteam, nincorrect[9];
	bool resolved[9];
	bool operator< (const result &other) const
	{
		if(nproblems < other.nproblems)
			return true;
		else if(nproblems == other.nproblems && penalty > other.penalty)
			return true;
		else if(nproblems == other.nproblems && penalty == other.penalty && nteam > other.nteam)
			return true;
		else
			return false;
	}
};


int main()
{	
	int t, i=0, team, time, pid;
	char type[2], input[101];
	result aux;
	map<int, int> indices;
	vector<result> contest;
	aux.penalty = aux.nproblems = 0;
	memset(aux.nincorrect, 0, sizeof(aux.nincorrect));
	memset(aux.resolved, false, sizeof(aux.resolved));
	scanf("%d", &t);
	scanf("\n");
	while(t--)
	{
		scanf("\n");
		while(fgets(input, 100, stdin))
		{
			if(input[0] == '\n') break;
			stringstream s(input);
			s >> team >> pid >> time >> type;
			if(indices.count(team) == 0)
			{	
				aux.nteam = team;
				indices[team] = contest.size();
				contest.push_back(aux);
			}
			if(type[0] == 'C' && !contest[indices[team]].resolved[pid-1])
			{
				contest[indices[team]].resolved[pid-1] = true;
				contest[indices[team]].nproblems++;
				contest[indices[team]].penalty += (contest[indices[team]].nincorrect[pid-1] * 20) + time;
			}
			else if (type[0] == 'I')
			{
				contest[indices[team]].nincorrect[pid-1]++;
			}

		}
		sort(contest.begin(), contest.end());
		for(auto it = contest.rbegin(); it != contest.rend(); ++it)
		{
			printf("%d %d %d\n", it->nteam, it->nproblems, it->penalty);
		}
		if(t)
			printf("\n");
		contest.clear();
		indices.clear();

	}
	return 0;
}
