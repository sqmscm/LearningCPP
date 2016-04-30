#pragma once
#include<string>
#include<iostream>
using namespace std;

struct person {
	friend istream &read(istream &is, person &name);
	friend ostream &print(ostream &is, const person &name);
public:
	person() = default;
	person(const string &addre, const string &na) :address(addre), name(na) {}
	person(istream &is) { read(is, *this); }
	string getName() const { return name; }
	string getAdd() const { return address; }
private:
	string name;
	string address;

};

istream &read(istream &is, person &name) {
	is >> name.name >> " " >> name.address;
	return is;
}

ostream &print(ostream &os, const person &name) {
	os << name.name << " " << name.address;
	return os;
}