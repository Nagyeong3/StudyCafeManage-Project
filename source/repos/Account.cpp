#include "Account.h"
#include <iostream>

using namespace std;

Account::readDB()
{
	ifstream file;
	file.open("AccountDB.txt");

	if (!file) { //����ó��
		cout << "AccountDB open ����\n";
		exit(100);
	}

	totalAccount=file.getline();

	file.close();

	
}

Account::writeDB()
{
	ofstream file;
	file.open("AccountDB.txt");

	if (!file) { //����ó��
		cout << "AccountDB open ����\n";
		exit(100);
	}

	file.put(totalAccount);

	file.close();
	return 0;
}

Account::payTicket(int price)
{
	totalAccount += price;

}

