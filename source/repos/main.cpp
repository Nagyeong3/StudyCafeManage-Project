#include <iostream>
#include <string>
#include "SeatDB.h"
using namespace std;

int main()
{
	SeatDB seat;
	//	PersonDB person;
	//	SeasonDB season;
	//	OnedayDB oneday;
	//	Time time;
	//	Account account;

		// �ð��Է��ϱ��Լ�

	string menu;
	do {
		cout << "�������������������������������� �������������������������������� �������������������������������� �������������������������������� ��������������������" << endl;
		cout << "�� [1] ȸ������ �� �� [2] ȸ��Ȯ�� �� �� [3] ȸ    �� �� �� [4] �ڸ�Ȯ�� �� �� ����: Q��" << endl;
		cout << "�������������������������������� �������������������������������� �������������������������������� �������������������������������� ��������������������" << endl;
		cin >> menu;

		if (menu.compare("1") == 0) {		// ȸ������

		}
		else if (menu.compare("2") == 0) {	// ȸ��Ȯ��
//			person.showPersonInfo();
		}
		else if (menu.compare("3") == 0) {	// ȸ��
//			account.showAccount();
		}
		else if (menu.compare("4") == 0) {	// �ڸ�Ȯ��
			seat.showSeat();
		}
	} while (menu != "Q");

}

void enterMain() {
	//	bool exist = ��ȭ��ȣ �Է��Լ�
	//	if(exist)
}