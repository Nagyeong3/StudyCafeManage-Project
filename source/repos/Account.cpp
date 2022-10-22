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
	file.open("account.txt");

	if (!file) { //오류처리
		cout << "account open 오류\n";
		exit(100);
	}


	//가격 불러오기

	string read;
	file.seekg(0);
	getline(file, read);

	int finshT;
	stringstream ssInt(read);
	ssInt >> totalAccount;

	file.close();

	
}

void Account::writeDB()
{
	ofstream file;
	file.open("account.txt", ios::app);

	if (!file) { //오류처리
		cout << "account open 오류\n";
		exit(100);
	}

	string write = to_string(totalAccount);
	file << write;

	file.close();

	return;
}

void Account::showAccount()
{
	cout <<"total : " <<totalAccount;
}

string Account::int2string(int I)
{
	if (I < 10) return to_string(0) + to_string(I);
	else return to_string(I);
	
}

string Account::payTicket(string seat)
{
	int num, price;
	int fY, fM, fD, fH, fmin;
	int hour, day;

	stringstream ssInt(seat);
	ssInt >> num;

	//날짜입력
	int Date, Time;
	cout << "\n날짜를 입력해주세요 (2022년07월21일 -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "시간을 입력해주세요 (16시34분 -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;



	//결제정보입력

	if (num == 1 || num==2) {  //정기권
		int choice;
		cout << "1) 7일 ------- 70원\n";
		cout << "2) 14일 ------- 140원\n";
		cout << "3) 28일 ------- 280원\n";
		cout << "이용하실 이용권을 선택해주세요 : ";
		cin >> choice;

		if (choice == 1) { 
			day = 7; price = 70; 
			if (24 >= D) {
				if (Y == 12) return to_string(Y+1) + to_string(01) + int2string((D+6)-30) + "2359";
				else return to_string(Y) + int2string(M + 1) + int2string((D + 6) - 30) + "2359";
			}else return to_string(Y) + int2string(M+1) + int2string(D + 6) + "2359";
		}
		else if (choice == 2) { 
			day = 14; price = 140;
			if(17 >= D){
				if (Y == 12) return to_string(Y+1) + to_string(01) + int2string((D + 13) - 30) + "2359";
				else return to_string(Y) + int2string(M + 1) + int2string((D + 13) - 30) + "2359";
			}else return to_string(Y) + int2string(M + 1) + int2string(D + 13) + "2359";
		}
		else if (choice == 3) { 
			day = 28; price = 28; 
			if (3 >= D) {
				if (Y == 12) return to_string(Y+1) + to_string(01) + int2string((D + 27) - 30) + "2359";
				else return to_string(Y) + int2string(M+1) + int2string((D + 27) - 30) + "2359";
			}
			else return to_string(Y) + int2string(M + 1) + int2string(D + 27) + "2359";
		}
		

	}else if (num == 3) {  //단일권
		int choice;
		cout << "1) 8시간 ------- 8원\n";
		cout << "2) 16시간 ------- 16원\n";
		cout << "3) 24시간 ------- 24원\n";
		cout << "이용하실 이용권을 선택해주세요 : ";
		cin >> choice;

		if (choice == 1) { 
			hour = 8; price = 8;
			if (H >= 16) return to_string(Y) + int2string(M) + int2string(D) + "2359";
			else return to_string(Y) + int2string(M) + int2string(D) + int2string(H + 8) + int2string(min);
		}else if (choice == 2) { 
			hour = 16; price = 16; 
			if (H >= 8) return to_string(Y) + int2string(M) + int2string(D) + "2359";
			else return to_string(Y) + int2string(M) + int2string(D) + int2string(H+16) + int2string(min);
		}else if (choice == 3) { 
			hour = 24; price = 24; 
			return to_string(Y) + int2string(M) + int2string(D) + "2359";
		}
	}

	
	cout << price << "원이 결제되었습니다.\n";
	totalAccount += price;

	
	//이 함 수 끝나고 시간 고치기
}

