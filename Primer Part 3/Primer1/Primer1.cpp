
#include "stdafx.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

istream& display(istream &is) {
	string a;
	while (is >> a)
		cout << a;
	is.clear();
	return is;
}

istream& display(istream &is,ostream &out) {
	string a;
	while (is >> a)
		out << a;
	is.clear();
	return is;
}

int main()
{

	//Ex8.5 & sstream
	ifstream test2In("test1");
	vector<string>eachWord;
	ostringstream record;
	ofstream test2Out("test1.copy", ofstream::out | ofstream::app); //appģʽ��ÿ��д����ǰ��λ���ļ�ĩβ������Ĭ��Ϊtrunc�ض�ģʽ�������ļ�����
	string temp2;
	while (test2In >> temp2)
		eachWord.push_back(temp2);
	for (string i : eachWord) {
		record << i + " ";
		test2Out << i << endl;
	}
	cout << record.str();
	
	//Ex8.4
	ifstream testIn("test1");
	vector<string>eachLine;
	string temp;
	while (getline(testIn, temp))
		eachLine.push_back(temp);
	for (string i : eachLine)
		cout << i << endl;


	string ifile = "test1";
	ifstream in(ifile);
	ofstream out;
	out.open(ifile + ".copy");

	display(in, out);

	display(cin);

	int pauseN;
	cin >> pauseN;
    return 0;
}


