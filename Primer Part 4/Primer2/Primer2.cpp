// Primer2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string>&, vector<string>::size_type);

bool check_size(const string&s, string::size_type sz) {
	return s.size() >= sz;
}
int main()
{
	vector<string> words = { "fox","jumps","over","quick","slow","the","turtle","red","the","red" };
	vector<int> test = { 0,2,-3,4,2,-1,34,-45,-6,45,5,-6,4 };
	//bind: auto newCallable = bind (callable, arg_list); 
	auto check6 = bind(check_size, _1, 6);
	string s = "hello";
	bool b1 = check6(s);


	//lambda: [�����б�] (����) -> return type {function body}
	//����1���滻Ϊ888��С���滻Ϊ666
	int test1 = 1;
	transform(test.begin(), test.end(), test.begin(), [test1](int i)->int {if (i > test1)return 888; else return 666; }); 
	for (auto &i : test)
		cout << i << " ";
	cout << endl;
	system("pause");

	size_t v1 = 42;
	auto f2 = [v1]()mutable {return ++v1; };
	v1 = 0;
	auto j = f2();
	cout << j << endl;
	system("pause");

	auto f = [] {return 42; };
	cout << f() << endl;
	biggies(words, 5);
	system("pause");

	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter); //���ֵȳ�Ԫ���ֵ���
	for (auto &i : words)
		cout << i << " ";
	cout << endl;

	sort(words.begin(), words.end(), isShorter);
	for (auto &i : words)
		cout << i << " ";
	cout << endl;
	system("pause");
    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto f = [sz](const string &a) {return a.size() >= sz; };
	auto wc = find_if(words.begin(), words.end(), f);
	auto count = words.end() - wc;
	cout << count << " words" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}


