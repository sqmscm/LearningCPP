
//数组

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	//范围for处理多维数组
	int ia[3][4];
	for (auto &row : ia) //必须要引用，否则得到的是指向首元素的指针
		for (auto &col : row)
			col = 0;
	
	//使用数组初始化向量对象
	int int_arr[] = { 0,1,2,3,4,5 };
	vector<int> ivec(begin(int_arr), end(int_arr)); //end指向尾元素后一位置
	vector<int> subVec(int_arr + 1, int_arr + 4); //拷贝1，2，3 没有4
	
	//C风格字符串
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	char largeStr[100];
	if (strcmp(ca1, ca2))
		cout << 1 << endl;
	strcpy(largeStr, ca1);
	strcat(largeStr, " ");
	strcat(largeStr, ca2);
	cout << largeStr << endl;
	
	//指针运算
	constexpr size_t a = 5;
	int a1[a] = { 1,2,3,4,5 };
	int *ip = a1;
	int *ip2 = ip + 4;
	cout << *ip << *ip2 << endl;
	
	//初始化数组
	constexpr unsigned sz = 42;
	int array[sz];
	int arr[10];
	int(*pArray)[10] = &arr;
	int(&arrRef)[10] = arr;

	//指针迭代器
	int test[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *e = &test[10];
	for (int *b = test; b != e; ++b)
		cout << *b << endl;

	system("pause");
    return 0;
}

