#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define SEAT_MAX 30

class SeatDB {
private:
	string seat[SEAT_MAX];
public:
	bool readFile();
	bool writeFile();
	void showSeat();						/* showSeat() : 현재좌석상태 보여주는 함수 */
	int chooseSeat(int memType);			/* chooSeat() : 좌석선택 함수 */
	int checkInput(string s);				/* checkInput() : 좌석선택 input검사 함수 */
	bool fixSeat(int memType, int idx);		/* fixSeat() : 선택받은 좌석수정 */
	bool delSeat(int idx);					/* delSeat() : 선택받은 좌석삭제 */
	string toChar(string seat);				/* toChar() : 0,1,2 숫자를 '□','▦','■'로 바꿔줌 */

};
