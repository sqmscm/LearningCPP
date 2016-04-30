
//自定义数据结构

#include<iostream>
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif
using namespace std;

int main()
{

	Sales_data data1, data2;
	double price = 0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold*price;
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold*price;

	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << endl << totalCnt << endl << totalRevenue;
		if (totalCnt != 0)
			cout << totalRevenue / totalCnt << endl;
		else cout << "(no sales)" << endl;
	}
	else {
		cerr << "Data must refer to the same ISBN" << endl;
		
	}

	system("pause");
	return 0;
}

