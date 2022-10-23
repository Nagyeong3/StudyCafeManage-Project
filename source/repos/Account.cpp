#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void Account::readDB()
{
	ifstream file;
	file.open("account.txt");

	if (!file) { //����ó��
		cout << "account open ����\n";
		exit(100);
	}


	//���� �ҷ�����

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

	if (!file) { //����ó��
		cout << "account open ����\n";
		exit(100);
	}

	string write = to_string(totalAccount);
	file << write<<"\n";

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

	//��¥�Է�
	int Date, Time;
	cout << "\n��¥�� �Է����ּ��� (2022��07��21�� -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "�ð��� �Է����ּ��� (16��34�� -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;



	//���������Է�

	if (num == 1 || num==2) {  //�����
		int choice;
		cout << "1) 7�� ------- 70��\n";
		cout << "2) 14�� ------- 140��\n";
		cout << "3) 28�� ------- 280��\n";
		cout << "�̿��Ͻ� �̿���� �������ּ��� : ";
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
		

	}else if (num == 3) {  //���ϱ�
		int choice;
		cout << "1) 8�ð� ------- 8��\n";
		cout << "2) 16�ð� ------- 16��\n";
		cout << "3) 24�ð� ------- 24��\n";
		cout << "�̿��Ͻ� �̿���� �������ּ��� : ";
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

	
	cout << price << "���� �����Ǿ����ϴ�.\n";
	totalAccount += price;

	
	//�� �� �� ������ �ð� ��ġ��
}

