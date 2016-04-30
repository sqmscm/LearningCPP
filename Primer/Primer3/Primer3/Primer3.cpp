
//标准库类型vector向量

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	//计算vector内对象的索引
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade)
		if (grade <= 100)
			++scores[grade / 10];
	for (auto i : scores)
		cout << i << " ";
	cout << endl;

	//访问容器中的元素
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	for (auto &i : v)
		i *= i;
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	//向vector对象添加元素
	vector<int> v2;
	for (int i = 0; i != 100; i++)
		v2.push_back(i);
	string word;
	vector<string> text;
	while (cin >> word)
		text.push_back(word);

	system("pause");
    return 0;
}

