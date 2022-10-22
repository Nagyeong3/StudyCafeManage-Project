#include "Account.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Account::readDB()
{
	ifstream file;
	file.open("AccountDB.txt");

	if (!file) { //오류처리
		cout << "AccountDB open 오류\n";
		exit(100);
	}


	//가격 불러오기

	string read;
	getline(file, read);

	int finshT;
	stringstream ssInt(read);
	ssInt >> totalAccount;

	file.close();

	
}

void Account::writeDB()
{
	ofstream file;
	file.open("AccountDB.txt");

	if (!file) { //오류처리
		cout << "AccountDB open 오류\n";
		exit(100);
	}

	file.put(totalAccount);

	file.close();

	return;
}

void Account::payTicket(int price)
{
	totalAccount += price;

}

