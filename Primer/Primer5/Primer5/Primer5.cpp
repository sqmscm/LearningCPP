
//����

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	//��Χfor�����ά����
	int ia[3][4];
	for (auto &row : ia) //����Ҫ���ã�����õ�����ָ����Ԫ�ص�ָ��
		for (auto &col : row)
			col = 0;
	
	//ʹ�������ʼ����������
	int int_arr[] = { 0,1,2,3,4,5 };
	vector<int> ivec(begin(int_arr), end(int_arr)); //endָ��βԪ�غ�һλ��
	vector<int> subVec(int_arr + 1, int_arr + 4); //����1��2��3 û��4
	
	//C����ַ���
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	char largeStr[100];
	if (strcmp(ca1, ca2))
		cout << 1 << endl;
	strcpy(largeStr, ca1);
	strcat(largeStr, " ");
	strcat(largeStr, ca2);
	cout << largeStr << endl;
	
	//ָ������
	constexpr size_t a = 5;
	int a1[a] = { 1,2,3,4,5 };
	int *ip = a1;
	int *ip2 = ip + 4;
	cout << *ip << *ip2 << endl;
	
	//��ʼ������
	constexpr unsigned sz = 42;
	int array[sz];
	int arr[10];
	int(*pArray)[10] = &arr;
	int(&arrRef)[10] = arr;

	//ָ�������
	int test[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *e = &test[10];
	for (int *b = test; b != e; ++b)
		cout << *b << endl;

	system("pause");
    return 0;
}

