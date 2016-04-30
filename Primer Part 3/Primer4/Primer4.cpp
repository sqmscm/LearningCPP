// Primer4.cpp : 定义控制台应用程序的入口点。
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
	//栈适配器
	stack<int> intStack; //空栈
	for (size_t ix = 0; ix != 10; ++ix) //填满栈
		intStack.push(ix);
	while (!intStack.empty()) {
		int value = intStack.top();
		intStack.pop(); //弹出栈顶元素，继续循环
	}

	//数值转换
	int i = 42;
	string s = to_string(i); //将整数i转换为字符表示形式
	double d = stod(s); //将字符串s转换为浮点数
	string s2 = "pi=3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));

	//管理容量 P318
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

