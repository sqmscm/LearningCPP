
//��׼������string

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s = "abc";
	string s1(10, 'c'); //s1=cccccccccc
	string s2 = "some string";
	string s3 = "Hello World!!!";
	
	//�±�ִ���������
	const string hexdigits = "0123456789ABCDEF";
	string result;
	string::size_type n;
	while (cin>>n)
		if (n < hexdigits.size())
			result += hexdigits[n];
	cout << result << endl;

	//�������ַ�
	for (decltype(s2.size()) index = 0; index != s2.size() && !isspace(s2[index]); index++)
		s2[index] = toupper(s2[index]);
	cout << s2 << endl;

	//ת��Ϊ��д����������
	for (auto &c : s3)
		c = toupper(c);
	cout << s3 << endl;

	//ͳ�Ʊ����Ÿ���
	decltype(s3.size()) punct_cnt = 0;
	for (auto c : s3)
		if (ispunct(c))
			++punct_cnt;
	cout << punct_cnt << endl;

	//ÿ�����
	for (auto c : s2)
		cout << c << endl;

	system("pause");
    return 0;
}

