#include "header.h"

void Time::readData()
{
	ifstream file;
	file.open("account.txt");

	if (!file) { //오류처리
		cout << "AccountDB open 오류\n";
		exit(100);
	}


	string read;
	file.seekg(0);

	getline(file, read); // 회계 쓰루
	//Date읽기
	getline(file, read);

	int D;
	stringstream ssInt(read);
	ssInt >> D;

	//Time읽기
	getline(file, read);

	int T;
	stringstream ssInt(read);
	ssInt >> T;

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

	if (!file) { //오류처리
		cout << "account open 오류\n";
		exit(100);
	}

	string D = to_string(Date);
	string T = to_string(Time);
	file << D << "\n";
	file << T << "\n";

	file.close();

	return;
}

void Time::insertTime()//시간입력함수
{
	// 이전시간 기록
	cout << "이전시간은";
	showTime();
	cout << "입니다.";
	bY = Y;
	bM = M;
	bD = D;
	bH = H;
	bmin = min;
	

	cout << "날짜를 입력해주세요 (2022년07월21일 -> 20220721) : ";
	cin >> Date;

	Y = Date / 10000;
	M = (Date % 10000) / 100;
	D = (Date % 10000) % 100;

	cout << "시간을 입력해주세요 (16시34분 -> 1634)";
	cin >> Time;

	H = Time / 100;
	min = Time % 100;

}

void Time::cleanDB()
{
	//정기권

	//단일권

}

string Time::leftTime(string num, string finish)
{
	int lY, lM, lD, lH, lmin;  //끝난시간

	//int로변경
	int finshT;
	stringstream ssInt(finish);
	ssInt >> finshT;
	int n;
	stringstream ssInt(num);
	ssInt >> n;

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

		return to_string(lH) + "시간" + to_string(lmin) + "분";
	}
	else { //정기권
		if (lM != M) {
			return to_string((30 - D) + lD)+"일";
		}
		else {
			return to_string(lD - D) + "일";
		}
	}

	


}

void Time::showTime()
{
	cout << Y << "년" << M / 100 << "월" << D % 100 
		<< "일\t"<<H<<"시"<< min<<"분";

}