// Primer3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

int main()
{
	//���µ�����
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
	list<int> ilist(10, 42); //10��int ÿ������42
	ilist.resize(15); //��5��ֵΪ0��Ԫ����ӵ�ĩβ
	ilist.resize(25, -1); //��10��ֵΪ-1��Ԫ����ӵ�ĩβ
	ilist.resize(5); //��ĩβɾ��20��Ԫ��

	/*ɾ��Ԫ�ز�������array
	Details on Primer page 311
	c.pop_back()
	c.pop_front()
	c.erase(p)
	c.erase(b,e)
	c.clear()
	�����ڵ�������forward_list�Ĳ���������P313*/

	//����Ԫ��
	vector<int>c;
	if (!c.empty()) { //�ڽ�����һ�����������ߵ���front/backǰ����Ƿ���Ԫ�� 
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last); //���ܵݼ�forward_list������
		auto val4 = c.back(); //forward_list��֧��
	}

	//ʹ��insert�ķ���ֵ��������������һ���ض�λ�÷�������Ԫ��
	list<string> lst;
	string word;
	auto iter1 = lst.begin();
	while (cin >> word)
		iter1 = lst.insert(iter1, word); //�ȼ��ڵ���push_front

	//insert
	vector<string> svec;
	list<string> slist;
	slist.insert(slist.begin(), "Hello!");
	svec.insert(svec.begin(), "Hello!"); //�ȼ���push_front
	svec.insert(svec.end(), 10, "Anna"); //��ĩβ����ʮ��ͬ����Ԫ��
	vector<string> v = { "quasi","simba","frollo","scar" };
	slist.insert(slist.begin(), v.end() - 2, v.end()); //��v��������Ԫ����ӵ�slist��ʼ��λ��
	slist.insert(slist.end(), { "quasi","simba","frollo","scar" });

	//push_front ��֧��vect��string
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

