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

	// 시간입력하기함수

	int menu;
	do {
		cout << "┌──────────────┐ ┌──────────────┐ ┌──────────────┐ ┌──────────────┐" << endl;
		cout << "│ [1] 회원출입 │ │ [2] 회원확인 │ │ [3] 회    계 │ │ [4] 자리확인 │" << endl;
		cout << "└──────────────┘ └──────────────┘ └──────────────┘ └──────────────┘" << endl;
		cin >> menu;

		if (menu == 1) {		// 회원출입
			
		}
		else if (menu == 2) {	// 회원확인
//			person.showPersonInfo();
		}
		else if (menu == 3) {	// 회계
//			account.showAccount();
		}
		else if (menu == 4) {	// 자리확인
			seat.showSeat();
		}
	} while (menu != 0);

}