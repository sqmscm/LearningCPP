// Primer3.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//���������
	string target = "WER,POSDF,WEORPK";
	auto rcomma = find(target.cbegin(), target.cend(), ',');
	system("pause");

	//iostream������
	istream_iterator<int> int_it(cin);
	istream_iterator<int> int_eof; //�յģ��ɵ���β�������ʹ��
	vector<int> vec(int_it, int_eof); //�ӵ�������Χ����vec
	ostream_iterator<int> out_iter(cout, " ");
	for (auto e : vec)
		*out_iter++ = e; //out_iter = e ͬ������
	cout << endl;
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
	system("pause");

	//���������
	list<int> lst = { 1,2,3,4 };
	list<int> lst2, lst3;
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2)); //lst2 ���� 4 3 2 1
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())); //lst3 ���� 1 2 3 4

	system("pause");
	return 0;
}

