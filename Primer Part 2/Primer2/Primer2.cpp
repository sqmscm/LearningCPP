
#include "stdafx.h"
#include<iostream>
#include<initializer_list>
#include<string>
#include<vector>
using namespace std;

int fact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}


string::size_type find_char(const string &s, char c, string::size_type &occours) {
	auto ret = s.size();
	occours = 0;
	for (decltype(ret) i = 0; i != s.size(); i++) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;
			++occours;
		}
	}
	return ret;
}

void print(const char *cp) {
	if (cp)
		while (*cp)
			cout << *cp++;
}

void print(const int *beg, const int *end) {
	while (beg != end)
		cout << *beg++ << endl;
}

void print(int(&arr)[2]) {
	for (auto i : arr)
		cout << i << endl;
}

void error_msg(initializer_list<string> il) {
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}

void outputVec(vector<int> &target,int a) {
	if (a != target.size()) {
		cout << target[a] << " ";
		outputVec(target, ++a);
	}
}

int odd[] = { 1,3,5,7,9 };
int even[] = { 2,4,6,8,10 };
decltype(odd) *arrPtr(int i) {
	return (i % 2) ? &odd : &even;
}
auto func(int i)->int(&)[5] {
	return (i % 2) ? odd : even;
}

int main()
{
	int*test3 = func(1);
	while (test3 != end(odd))
		cout << *test3++ << " ";
	cout << endl;

	int *test2 = *arrPtr(2);
	while (test2 != end(even))
		cout << *test2++ << " ";
	cout << endl;

	vector<int> test1 = { 1,2,3,4,5,6,7 };
	outputVec(test1, 0);
	error_msg({ "fuctionX","okay" });

	int tes[2] = { 0,1 };
	print(tes);
	print(begin(tes), end(tes));

	print("you are silly b\n");

	string::size_type p, x = find_char("you are silly b", 'l', p) + 1;
	cout << x << " " << p << endl;

	int j = fact(5);
	cout << "5! is " << j << endl;

	system("pause");
    return 0;
}

