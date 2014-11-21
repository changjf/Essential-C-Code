#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void initialize_exclusion_set(set<string> &);
void process_file(map<string, int> &, const set<string> &, ifstream &);
void user_query(const map<string, int> &);
void display_word_count(const map<string, int> &, ofstream &);

int main()
{
	ifstream ifile("C:\\test.txt");
	ofstream ofile("C:\\test.map");
	if(!ifile || !ofile) 
	{
		cerr << "Unable to open file -- bailing out! " << endl;
		return -1;
	}
	set<string> exclude_set;
	initialize_exclusion_set(exclude_set);

	map<string, int> word_count;
	process_file(word_count, exclude_set, ifile);
	user_query(word_count);
	display_word_count(word_count, ofile);
	return 0;
}


void initialize_exclusion_set(set<string> &exs)
{
	static string _excluded_words[5] = {
		"the", "an", "I", "of", "am"
	};
	exs.insert(_excluded_words, _excluded_words + 5);
}

void process_file(map<string, int> &word_count, 
				  const set<string> &exclude_set, ifstream &ifile)
{
	string word;
	while(ifile >> word)
	{
		if(exclude_set.count(word))
			continue;
		word_count[word]++;
	}
}

void user_query(const map<string, int> &word_map)
{
	string search_word;
	cout << "Please enter a word to search: q to quit";
	cin >> search_word;
	while(search_word.size() && search_word != "q")
	{
		map<string, int>::const_iterator it;
		if((it = word_map.find(search_word)) != word_map.end())
			cout << "Found " << it->first << " occurs " << it->second
				<< "times" << endl;
		else
			cout << search_word << "not found in text" << endl;
		cout << "Another Search ? (q to quit)" << endl;
		cin >> search_word;
	}
}

void display_word_count(const map<string, int> &word_map, ofstream &os)
{
	map<string, int>::const_iterator iter = word_map.begin(),
		end_it = word_map.end();
	while(iter != end_it)
	{
		os << iter->first << "( " << iter->second << " )" << endl;
		++iter;
	}
	os << endl;
}
