#include "../library/lib.hpp"
#include <iostream>
using namespace std;

pii findcoords (const string *kb, char l){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 10; j++){
			if (kb[i][j] == l)
				return mp(i,j);
		}
	}
	return pii();
}


class ForbiddenLove {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, cs=1;
	    in >> n;
	    string kb[4] = {"1234567890", "QWERTYUIOP", "ASDFGHJKL;", "ZXCVBNM,.-"};
	    while (n--){
            char bg;
            string msg;
            in >> bg;
            in.ignore();
            getline(in, msg);
            pii b = findcoords(kb, bg);
			pii a = findcoords(kb, msg.back());
			int r_dist = b.fst - a.fst;
			int c_dist = b.snd - a.snd;
			out << "Case #" << cs++ << ": ";
			for(int i = 0; i < msg.size(); i++){
            	if(msg[i] != ' '){
            		pii c = findcoords(kb, msg[i]);
            		int row = (c.fst + r_dist + 4)%4;
            		int col = (c.snd + c_dist + 10)%10;
            		out << kb[row][col];
            	}else
            		out << msg[i];
            }
            out << endl;
	    }

	}
};