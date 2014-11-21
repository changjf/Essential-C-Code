#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream in_file("C:\\text.txt");
	if(!in_file)
	{
		cerr << "oops! unable to open input file" << endl;
		return -1;
	}
	ofstream out_file("C:\\text.sort");
	if(!out_file)
	{
		cerr << "oops! unable to open output file" << endl;
		return -2;
	}
	string word;
	vector<string> text;
	while(in_file >> word)
		text.push_back(word);
	int ix;
	cout << "unsorted text: " << endl;
	for(ix = 0; ix < text.size(); ++ix)
		cout << text[ix] << ' ';
	cout << endl;
	sort(text.begin(), text.end());
	cout << "sorted text: " << endl;
	for(ix = 0; ix < text.size(); ++ix)
		out_file << text[ix] << ' ';
	out_file << endl;
	return 0;
}
