// Primer1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	}//�������캯��

	Test& operator=(const Test &dd) {
		cout << "operator=" << endl;
	} //���ظ�ֵ�����

	~Test() {
		cout << "destroying" << endl;
	} //��������

};

struct NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete; //��ֹ����
	NoCopy &operator=(const NoCopy&) = delete; //��ֹ��ֵ
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

