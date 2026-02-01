#include "../library/lib.hpp"
#include <iostream>
using namespace std;



class BSpreadsheets {
public:
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	void solve(std::istream& in, std::ostream& out) {
		int n;
		string s;
		in >> n;
		for (int i = 0; i < n; i++){
			in >> s;
			if (check_input(s) == 1){
				out << to_type_2(s);
			}
			else
				out << to_type_1(s);
			out << "\n";
		}
	}

private:
	int check_input(string &x){
		if (x[0] == 'R' && isdigit(x[1]) && x.find('C') != string::npos)
			return 1;
		else
			return 2;
	}

	string to_type_1(string &x){ // RXCY
		ll r = 0;
		string letters, numbers, ans;
		ans.clear();
		ans.pb('R');
		for (int i = 0; i < x.size(); i++){
			if (!isdigit(x[i]))
				letters.pb(x[i]);
			else
				numbers.pb(x[i]);
		}
		ll pw = 1;
		reverse(letters.begin(), letters.end());
		for (int i = 0; i < letters.size(); i++){
			r += (letter_to_num(letters[i])*pw);
			pw *= 26;
		}
		ans += numbers;
		ans.pb('C');
		ans += (to_string(r));
		return ans;
	}

	string to_type_2(string &x){ // Otherwise
		string ans, row, col;
		ll r, pw = 1;
		int i = 1;
		while (isdigit(x[i])){
			row.pb(x[i]);
			i++;
		}
		i++;
		while(i < x.size()){
			col.pb(x[i]);
			i++;
		}
		r = strtol(col.c_str(), nullptr, 10);
		ll a, b, c;
        while(r > 0){
            a = r % 26;
            b = (r / 26);
            // patch. idk why it works, but it works!
            if (a == 0)
            	b--;
            r = b;
            ans.pb(num_to_letter(a));
        }
        reverse(ans.begin(), ans.end());
        ans += row;
        return ans;

	}

	int letter_to_num(char x){
		return (x - 'A') + 1;
	}

	char num_to_letter(int x){
		return abc[(x - 1 + 26)%26];
	}

};

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
// a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z