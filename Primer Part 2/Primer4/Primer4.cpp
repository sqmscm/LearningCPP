
#include "stdafx.h"
#include<iostream>
#include"Person.h"
using namespace std;

int main()
{
	person david("wku", "david");
	cout << david.getAdd() << " " << david.getName() << endl;

#ifndef TESTMODE
	int testmodepause;
	cin >> testmodepause;
#endif

    return 0;
}

