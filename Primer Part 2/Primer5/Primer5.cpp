
#include "stdafx.h"
#include<iostream>
#include"Screen.h"
using namespace std;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(1, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	int pause;
	cin >> pause;
    return 0;
}
