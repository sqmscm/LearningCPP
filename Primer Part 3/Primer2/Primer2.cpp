// Primer2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<forward_list>
#include<string>
#include<array>
using namespace std;

bool search(vector<int>::iterator, vector<int>::iterator, int);
int main()
{
	//���������������ȿ�����öࣺԪ�ر���δ������swap�������������ڲ����ݽṹ������array���⡣
	vector<string> svec1(10);
	vector<string> svec2(24);
	swap(svec1, svec2);
	svec1.swap(svec2);
	
	/*
	seq.assign(b,e);
	��seq�е�Ԫ���滻Ϊ������b��e����ʾ��Χ�ڵ�Ԫ�ء�b��e����ָ��seq�е�Ԫ��
	seq.assign(n,t);
	��seq�е�Ԫ���滻Ϊn��ֵΪt��Ԫ��
	*/
	list<string> names;
	vector<const char*> oldstyle;
	names.assign(oldstyle.cbegin(), oldstyle.cend()); //���Խ�const char* ת��Ϊstring

	array<int, 10> ia1 = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10>::size_type j = 10;

	vector<const char*> articles = { "a","an","the" };
	forward_list<string> words(articles.begin(), articles.end());
	for (auto i : words)
		cout << i << endl;

	vector<int> list1 = { 0,1,2,3,4,5,6,7,8 };
	vector<int> list2(list1);
	auto dd3 = list2.begin();
	vector<int>::iterator dd1 = list1.begin();
	vector<int>::iterator dd2 = list1.end();
	list<deque<int>> ex9_2;
	if (search(dd1, dd2, 8))
		cout << "true" << endl;
	else cout << "false" << endl;
#ifndef endTest
	auto pausetest = 0;
	cin >> pausetest;
#endif
    return 0;
}

bool search(vector<int>::iterator first, vector<int>::iterator last, int x) {
	while (first != last) {
		if (*first == x)
			return true;
		++first;
	}
	return false;
}
