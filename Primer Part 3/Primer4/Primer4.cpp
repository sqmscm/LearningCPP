// Primer4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
using namespace std;



int main()
{
	//ջ������
	stack<int> intStack; //��ջ
	for (size_t ix = 0; ix != 10; ++ix) //����ջ
		intStack.push(ix);
	while (!intStack.empty()) {
		int value = intStack.top();
		intStack.pop(); //����ջ��Ԫ�أ�����ѭ��
	}

	//��ֵת��
	int i = 42;
	string s = to_string(i); //������iת��Ϊ�ַ���ʾ��ʽ
	double d = stod(s); //���ַ���sת��Ϊ������
	string s2 = "pi=3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));

	//�������� P318
	vector<int> test1;
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	for (auto ix = 0; ix != 24; ++ix)
		test1.push_back(ix);
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	test1.reserve(50);
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	while (test1.size() != test1.capacity())
		test1.push_back(0);
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	test1.push_back(42);
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	test1.shrink_to_fit();
	cout << "size " << test1.size() << " capacity " << test1.capacity() << endl;

	system("pause");

    return 0;
}

