// Primer1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<sstream>
#include<fstream>
using namespace std;

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else throw runtime_error("no rule for " + key);
	return trans_map;
}

const string & transform(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input,ofstream &cout) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	//单词转换程序
	ifstream mapfile("map.txt");
	ifstream target("arti.txt");
	ofstream output("out.txt");
	word_transform(mapfile, target, output);

	//关联容器迭代器
	map<string, size_t> test1 = { {"aert",12},{"sdfasd",34} };
	auto map_it = test1.begin();
	cout << map_it->first;
	cout << " " << map_it->second;
	system("pause");


	//使用map和set
	map<string, size_t> word_count;
	set<string> exclude = { "the","But","and","a" };
	string word;
	while (cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

	system("pause");
    return 0;
}

