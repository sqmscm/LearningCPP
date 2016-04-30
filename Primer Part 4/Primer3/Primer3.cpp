// Primer3.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	//反向迭代器
	string target = "WER,POSDF,WEORPK";
	auto rcomma = find(target.cbegin(), target.cend(), ',');
	system("pause");

	//iostream迭代器
	istream_iterator<int> int_it(cin);
	istream_iterator<int> int_eof; //空的，可当作尾后迭代器使用
	vector<int> vec(int_it, int_eof); //从迭代器范围构造vec
	ostream_iterator<int> out_iter(cout, " ");
	for (auto e : vec)
		*out_iter++ = e; //out_iter = e 同样可以
	cout << endl;
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
	system("pause");

	//插入迭代器
	list<int> lst = { 1,2,3,4 };
	list<int> lst2, lst3;
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2)); //lst2 包含 4 3 2 1
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())); //lst3 包含 1 2 3 4

	system("pause");
	return 0;
}

