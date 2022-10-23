#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Time.h"

using namespace std;

void Time::readData()
{
	ifstream file;
	file.open("account.txt");

	if (!file) { //����ó��
		cout << "AccountDB open ����\n";
		exit(100);
	}


	string read;
	file.seekg(0);

	getline(file, read); // ȸ�� ����
	//Date�б�
	getline(file, read);

	int D= stoi(read);

	//Time�б�
	getline(file, read);

	int T = stoi(read);

	file.close();


	bY = D / 10000;
	bM = (D % 10000) / 100;
	bD = (D % 10000) % 100;
	bH = T / 100;
	bmin = T % 100;
}

void Time::writeData()
{
	ofstream file;
	file.open("account.txt", ios::app);

	if (!file) { //����ó��
		cout << "account open ����\n";
		exit(100);
	}

	string D = to_string(Date);
	string T = to_string(Time);
	file << D << "\n";
	file << T << "\n";

	file.close();

	return;
}

void Time::insertTime()//�ð��Է��Լ�
{
	// �����ð� ���
	cout << "�����ð���";
	cout << bY << "��" << int2string(bM) << "��" << int2string(bD)
		<< "��\t" << int2string(bH) << "��" << int2string(bmin) << "��";
	cout << "�Դϴ�.";


	cout << "��¥�� �Է����ּ��� (2022��07��21�� -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "�ð��� �Է����ּ��� (16��34�� -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;

	bY = Y;
	bM = M;
	bD = D;
	bH = H;
	bmin = min;


}

void Time::cleanDB()
{
	//�����

	//���ϱ�

}

string Time::int2string(int I)
{

	if (I < 10) return to_string(0) + to_string(I);
	else return to_string(I);


}

string Time::leftTime(string num, string finish)
{
	int lY, lM, lD, lH, lmin;  //�����ð�

	//int�κ���
	int finshT=stoi(finish);
	int n=stoi(num);

	int lDate = finshT / 10000;
	int lTime = finshT % 10000;

	lY = lDate / 10000;
	lM = (lDate % 10000) / 100;
	lD = (lDate % 10000) % 100;
	lH = lTime / 100;
	lmin = lTime % 100;

	if (n = 3) { //
		int a = H * 60 + min;
		int b = lH * 60 + lmin;
		int c = b - a;
		lH = c / 60;
		lmin = c % 60;

		return to_string(lH) + "�ð�" + to_string(lmin) + "��";
	}
	else { //�����
		if (lM != M) {
			return to_string((30 - D) + lD)+"��";
		}
		else {
			return to_string(lD - D) + "��";
		}
	}

	


}

void Time::showTime()
{
	cout << Y << "��" << int2string(M) << "��" << int2string(D)
		<< "��\t"<< int2string (H)<<"��"<< int2string (min)<<"��";

}

string Time::returnTime()
{
	return int2string(Y) + int2string(M) +int2string(D) + int2string(H) + int2string(min) ;
}
