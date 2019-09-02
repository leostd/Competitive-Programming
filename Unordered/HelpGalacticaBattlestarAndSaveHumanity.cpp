#include "../library/lib.hpp"
#include <iostream>
using namespace std;

map<string, vector<string>> nodes;
map<string, bool> visited;
ll ans;

void dfs(string a){
	if (a == "New Earth")
		ans++;
	else{
		for (int i = 0; i < nodes[a].size(); i++){
			dfs(nodes[a][i]);
		}
	}

}

class HelpGalacticaBattlestarAndSaveHumanity {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int c, cs =1;
	    in >> c;
	    while(c--){
	        int v;
	        in >> v;
	        string str, l;
	        bool first = true;
			nodes.clear();
			ans = 0;
			visited.clear();
			string root;
	        REP(i, v){
	        	if (first)
	        		in.ignore(), first = false;
	        	getline(in, str);
	            auto x = find(str.begin(), str.end(), ':');
	            string src = str.substr(0,x-str.begin());
	            if (i == 0)
	            	root = src;
				l.clear();
				for(int j = 1+x-str.begin(); j < str.size(); j++){
					if (str[j] == ',' || str[j] == '\n'){
						nodes[src].pb(l);
						l.clear();
					}else{
						l.pb(str[j]);
					}
				}
				nodes[src].pb(l);
	        }
			dfs(root);
			out << "Case #"<< cs++ << ": " << ans << "\n";
	    }

	}
};