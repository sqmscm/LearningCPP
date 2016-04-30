
#include "stdafx.h"
#include<iostream>
#include<string>
#include<cassert>
#include<vector>
using namespace std;

inline const string& shorter(const string &l1, const string &l2) {
	return l1.size() < l2.size() ? l1 : l2;
}

int addTo(int &a, int &b) {
	return a + b;
}

int subtraction(int&a, int&b) {
	return a - b;
}

int multi(int&a, int&b) {
	return a*b;
}

int divide(int&a, int&b) {
	return a / b;
}
int main()
{
	int t1 = 1, t2 = 2;
	vector<int(*)(int&,int&)>functions;
	int(*funcPtr)(int &, int&);
	funcPtr = addTo;
	functions.push_back(funcPtr);
	funcPtr = subtraction;
	functions.push_back(funcPtr);
	functions.push_back(multi);
	functions.push_back(divide);
	size_t loci = 0;
	while (loci != 4) {
		cout << functions[loci++](t1, t2) << endl;
	}

	int x = 9, y = 8;
#ifndef NDEBUG
	assert(x > y);
	cerr << "Error: " << __FILE__ << ": in function " << __func__ << "at line " << __LINE__ << endl << "	Complied on " << __DATE__
		<< " at " << __TIME__ << endl << "		Word read was \"" << x << "\": Length too large" << endl;
#endif 

	string a, b;
	cin >> a >> b;
	cout << shorter(a, b) << endl;

    return 0;
}

