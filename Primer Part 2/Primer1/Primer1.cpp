

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	//Å×³öÒì³£
	int a1, a2;
	while (cin >> a1 >> a2) {
		try {
			if (a1 != a2)
				throw runtime_error("Data must refer to same ISBN");
		}
		catch (runtime_error err) {
			cout << err.what() << "\nTry again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!c || c == 'n')
				break;
		}
	}
	
	//switch
	char r;
	int yy = 0;
	int fy = 0;
	while (cin >> r) {
		switch (r)
		{
		case'a':
		case'e':
		case'i':
		case'o':
		case'u':
			++yy;
			break;
		default:
			++fy;
			break;
		}
	}
	cout << yy << endl << fy << endl;
	system("pause");
    return 0;
}

