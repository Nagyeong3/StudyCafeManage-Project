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
	//
	// 시간입력하기함수

	string menu;
	do {
		cout << "┌──────────────┐ ┌──────────────┐ ┌──────────────┐ ┌──────────────┐ ┌────────┐" << endl;
		cout << "│ [1] 회원출입 │ │ [2] 회원확인 │ │ [3] 회    계 │ │ [4] 자리확인 │ │ 종료: Q│" << endl;
		cout << "└──────────────┘ └──────────────┘ └──────────────┘ └──────────────┘ └────────┘" << endl;
		cin >> menu;

		if (menu.compare("1") == 0) {		// 회원출입
			
		}
		else if (menu.compare("2") == 0) {	// 회원확인
//			person.showPersonInfo();
		}
		else if (menu.compare("3") == 0) {	// 회계
//			account.showAccount();
		}
		else if (menu.compare("4") == 0) {	// 자리확인
			seat.showSeat();
		}
	} while (menu != "Q");

}

void enterMain() {
//	bool exist = 전화번호 입력함수
//	if(exist)
}