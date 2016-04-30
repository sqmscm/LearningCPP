// Primer3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

int main()
{
	//更新迭代器
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
			iter = vi.erase(iter);
	}

	//resize
	list<int> ilist(10, 42); //10个int 每个都是42
	ilist.resize(15); //将5个值为0的元素添加到末尾
	ilist.resize(25, -1); //将10个值为-1的元素添加到末尾
	ilist.resize(5); //从末尾删除20个元素

	/*删除元素不适用于array
	Details on Primer page 311
	c.pop_back()
	c.pop_front()
	c.erase(p)
	c.erase(b,e)
	c.clear()
	适用于单向链表forward_list的操作在书上P313*/

	//访问元素
	vector<int>c;
	if (!c.empty()) { //在解引用一个迭代器或者调用front/back前检查是否有元素 
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last); //不能递减forward_list迭代器
		auto val4 = c.back(); //forward_list不支持
	}

	//使用insert的返回值，可以在容器中一个特定位置反复插入元素
	list<string> lst;
	string word;
	auto iter1 = lst.begin();
	while (cin >> word)
		iter1 = lst.insert(iter1, word); //等价于调用push_front

	//insert
	vector<string> svec;
	list<string> slist;
	slist.insert(slist.begin(), "Hello!");
	svec.insert(svec.begin(), "Hello!"); //等价于push_front
	svec.insert(svec.end(), 10, "Anna"); //在末尾插入十个同样的元素
	vector<string> v = { "quasi","simba","frollo","scar" };
	slist.insert(slist.begin(), v.end() - 2, v.end()); //将v最后的两个元素添加到slist开始的位置
	slist.insert(slist.end(), { "quasi","simba","frollo","scar" });

	//push_front 不支持vect和string
	list<int> ilist1;
	for (size_t ix = 0; ix != 4; ++ix)
		ilist.push_front(ix);
	for (auto &i : ilist1)
		cout << i;

	//push_back
	vector<string> container;
	string word1;
	while (cin >> word1)
		container.push_back(word1);
	for (auto &i : container)
		cout << i;
	system("pause");
    return 0;
}

