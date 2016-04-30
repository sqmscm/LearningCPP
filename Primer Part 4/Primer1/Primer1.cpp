// Primer1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<string>
using namespace std;

int main()
{
	vector<int> vec = { 1,2,3,4,5,4,5 };
	vector<int> vec2 = { 1,2,3,4,5,4,4 };
	vector<string> words = { "fox","jumps","over","quick","slow","the","turtle","red","the","red" };

	//重排容器元素
	sort(words.begin(), words.end());
	for (auto &i : words)
		cout << i << " ";
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	for (auto &i : words)
		cout << i << " ";
	cout << endl;
	system("pause");

	//写容器元素
	fill(vec.begin(), vec.end(), 0);
	fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
	fill_n(back_inserter(vec2), 10, 0);
	auto ret = copy(begin(vec), end(vec), vec2.begin());
	replace(vec.begin(), vec.end(), 0, 42);
	replace_copy(vec.cbegin(), vec.cend(), back_inserter(vec2), 42, 2333);
	for (auto &i : vec)
		cout << i << " ";
	cout << endl;
	for (auto &i : vec2)
		cout << i << " ";
	cout << endl;
	system("pause");

	//只读算法
	cout << equal(vec.cbegin(), vec.cend(), vec2.cbegin()) << endl;
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << sum << endl;

	//find() & count()
	int val = 4;
	auto result = find(vec.cbegin(), vec.cend(), val);
	cout << "The value " << val << (result == vec.cend() ? " is not present " : " is present ");
	cout << count(vec.cbegin(), vec.cend(), val) << " times" << endl;

	system("pause");
    return 0;
}

