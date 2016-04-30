// Primer1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "constructor." << endl;
	}

	Test(const Test &dd) {
		cout << "copy constructor." << endl;
	}//拷贝构造函数

	Test& operator=(const Test &dd) {
		cout << "operator=" << endl;
	} //重载赋值运算符

	~Test() {
		cout << "destroying" << endl;
	} //析构函数

};

struct NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete; //禁止拷贝
	NoCopy &operator=(const NoCopy&) = delete; //禁止赋值
	~NoCopy() = default;
};

int main()
{
	Test a;
	Test b(a);
	Test c = a;
	Test *d = new Test;
	delete d;

	system("pause");
    return 0;
}

