
//迭代器

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s("some string");
	vector<string> text{ "Hello cpp" };

	//二分搜索
	vector<int> find{ 1,2,3,4,5,6,7,8,9,10 };
	auto beg = find.begin(), end = find.end();
	auto mid = find.begin() + (end - beg) / 2;
	int sought = 2;
	while (mid != end && *mid != sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}
	cout << *mid << endl;

	//组合解引用和成员访问操作
	/*for (auto it = text.cbegin(); it != text.cend && !it->empty(); ++it)
		cout << *it << endl;*/

	//将迭代器从一个元素移动到另一个元素
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
		*it = toupper(*it);
	cout << s << endl;

	//操作符
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it); //*it 返回迭代器it所指元素的引用
	}
	cout << s << endl;

	system("pause");
    return 0;
}

