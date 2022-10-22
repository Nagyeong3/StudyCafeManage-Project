#include "SeatDB.h"

bool SeatDB::readFile()
{
	string filename = "seat.txt";
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << "���� �б� ����\n";
		return false;
	}

	for (int i = 0; i < SEAT_MAX; i++) {
		getline(fin, seat[i]);
	}

	return true;
}

bool SeatDB::writeFile()
{
	string filename = "seat.txt";
	try {
		ofstream fout(filename);
		if (!fout.is_open()) {
			cerr << "���� ���� ����" << endl;
			return false;
		}

		for (int i = 0; i < SEAT_MAX; i++) {
			fout << seat[i] << endl;
		}
		cout << "SeatDB ������ �Ϸ�Ǿ����ϴ�." << endl;
	}
	catch (exception& e) {
		return false;
	}
	return false;
}

// �����¼����� �����ִ� �Լ�
void SeatDB::showSeat()
{
	readFile();
	cout << "\n[           �¼���Ȳ          ]" << endl;
	cout << "   1  2  3  4  5  6  7  8  9 10" << endl;
	for (int i = 0; i < SEAT_MAX; i++) {
		if (i % 10 == 0) {
			cout << char('A' + i / 10) << " ";
		}
		string c = toChar(seat[i]);
		cout << c << " ";
		if (i % 10 == 9) {
			cout << endl;
		}
	}
	cout << endl;
}

// �¼����� �Լ�
int SeatDB::chooseSeat(int memType)
{
	readFile();
	string chooseS;	// ������Է�(ex: A3, C10)
	do {
		cout << "\n[           �¼�����          ]\n" << endl;
		showSeat();
		cout << "\n�¼��� �����ϼ���(ex: A3, C10)(�� �ڸ� => ��) : ";
		cin >> chooseS;
	} while (!checkInput(chooseS));

	int chooseIdx = checkInput(chooseS) - 1;
	fixSeat(memType, chooseIdx);

	return chooseIdx;

}

// �¼����� input�˻� �Լ�
int SeatDB::checkInput(string s)
{
	string s1, s2;	// ex: �Է¹��� A3���� A�κа� 3�κ�
	s1 = s.substr(0, 1);
	s2 = s.substr(1);

	if (s1.compare("A") < 0 || s1.compare("C") > 0) {
		return 0;
	}
	if (stoi(s2) < 1 || stoi(s2) > 10) {
		return 0;
	}

	int ss = 0;
	if (s1.compare("A") == 0) {
		ss = 0 + stoi(s2);
	}
	else if (s1.compare("B") == 0) {
		ss = 10 + stoi(s2);
	}
	else if (s1.compare("C") == 0) {
		ss = 20 + stoi(s2);
	}

	if (seat[ss - 1].compare("0") == 0) {
		return ss;
	}
	else {
		return 0;
	}
}

// ���ù��� �¼�����
bool SeatDB::fixSeat(int memType, int idx)
{
	string fixStr;
	if (memType == 1) {			// �����������
		fixStr = "2";
	}
	else if (memType == 2 || memType == 3) {	// �����������, �ܱ��������
		fixStr = "1";
	}
	else {
		return false;
	}

	seat[idx] = fixStr;
	writeFile();
	return true;
}

// ���ù��� �¼�����
bool SeatDB::delSeat(int idx)
{
	readFile();
	seat[idx] = "0";
	writeFile();
	return true;
}

// 0,1,2 ���ڸ� '��','��','��'�� �ٲ���
string SeatDB::toChar(string seat)
{
	if (seat.compare("0") == 0) {
		return "��";
	}
	else if (seat.compare("1") == 0) {
		return "��";
	}
	else if (seat.compare("2") == 0) {
		return "��";
	}
	else {
		return "??";
	}
}
