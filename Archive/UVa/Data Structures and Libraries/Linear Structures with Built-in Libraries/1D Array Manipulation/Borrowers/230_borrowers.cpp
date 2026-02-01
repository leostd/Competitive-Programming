#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct book
{
	string title, author;
	inline bool operator< (book &b) const
	{
		if( author != b.author )
			return author < b.author;
		else
			return title < b.title; 
	}
};
int main() {
	book bk;
	vector<book> books;
	map<string, int> map;
	vector<bool> returned, borrowed;
	char author[83], title[83], action[50];
	int c=0, index;
	string act, prev;
	while(1)
	{
		scanf("\"%[^\"]\"%*4c%[^\n]\n", title, author);
		if(title[0] == '\0' && author[0] == '\0')
		{
			scanf("%*s%*c");
			break;
		}
		else
		{
			bool in = false;
			bk.title = title;
			bk.author = author;
			for(int i = 0; i < books.size(); i++)
			{
				if(books[i].title == bk.title && books[i].author == bk.author)
					in = true;
			}
			if(!in)
				books.push_back(bk);
		}
		title[0] = author[0] = '\0';
	}
	returned = vector<bool>(books.size(), false);
	borrowed = vector<bool>(books.size(), false);
	sort(books.begin(), books.end());
	for(int i = 0; i < books.size(); i++)
	{
		map[books[i].title] = i;	
	}
	while(1)
	{
		scanf("%s%*c\"%[^\"]\"%*c", action, title);
		if(title[0] != '\0')
		{
			string aux = title;
			index = map[aux];
		}
			
		if(strcmp(action, "END") == 0)
			break;
		else if( strcmp(action, "SHELVE") == 0)
		{
			int flag = -1;
			for(int i = 0; i < books.size(); i++)
			{
				if(!borrowed[i])
				{
					flag = map[books[i].title];
				}
				else if(returned[i])
				{
					if(flag == -1)
						cout << "Put \"" << books[i].title << "\" first" << endl;
					else
						cout << "Put \"" << books[i].title << "\" after \"" << books[flag].title << "\"" << endl;
					flag = i;
					borrowed[i] = returned[i] = false;
				}
			}
			cout << "END" << endl;
		}
		else if(strcmp(action, "BORROW") == 0)
		{
			borrowed[index] = true;
			returned[index] = false;
		}
		else if(strcmp(action, "RETURN") == 0)
		{
			returned[index] = true;
		}
	}
	
	return 0;
}
