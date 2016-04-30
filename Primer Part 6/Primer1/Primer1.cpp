// Primer1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<new>
using namespace std;

class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	size_type size()const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back(){
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string& back(){
		check(0, "back on empty StrBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const {
		if (i >= data->size())
			throw out_of_range(msg);
	}
};

int main()
{
	//unique_ptr
	unique_ptr<int> p6(new int(42)); //需要绑定到一个new返回的指针上
	unique_ptr<int> p7(p6.release()); //p7指向p6原来的，p6置为空
	unique_ptr<int> p8(new int(1));
	p7.reset(p8.release()); //p7指向p8

	//直接管理内存
	vector<int> *pv = new vector<int>{ 0,1,2,3,4,5,6,7,8,9 };
	int *p1 = new int; //分配失败抛出std::bad_alloc
	int *p2 = new(nothrow) int; //分配失败返回空指针
	delete pv, p1, p2;

	//make_shared函数
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string>p4 = make_shared<string>(10, '9'); //p4指向一个值为"999999999"的string
	shared_ptr<int> p5 = make_shared<int>();
	auto px = make_shared<string>(); //用auto比较方便


	system("pause");
    return 0;
}

