
// (C) Copyright SQM

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<memory>
#include<map>
#include<set>

using namespace std;
using line_no = vector<string>::size_type;

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

class TextQuery {
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

void search(string x,ostream &t,TextQuery a) {
	print(t, a.query(x));
	t << "---------------------------------------------------------------------------------------" << endl;
	cout << "1 record has been writen in file." << endl;
}

int main()
{
	ifstream input("in.txt");
	ofstream output("out.txt");
	TextQuery file(input);
	string x;
	cout << "Enter a word, the result will be outputed in the file 'out.txt'" << endl;
	while (cin >> x) {
		search(x, output, file);
	}
    return 0;
}

TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " time(s)." << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}

