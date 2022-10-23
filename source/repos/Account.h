#pragma once
#include <string>

using namespace std;

class Account {


public:

	int totalAccount;
	int Y, M, D, H, min;

	void readDB();
	void writeDB();
	void showAccount();
	string int2string(int I);
	string payTicket(string seat);  //∞·¡¶


};