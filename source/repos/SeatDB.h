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
	void showSeat();						/* showSeat() : �����¼����� �����ִ� �Լ� */
	int chooseSeat(int memType);			/* chooSeat() : �¼����� �Լ� */
	int checkInput(string s);				/* checkInput() : �¼����� input�˻� �Լ� */
	bool fixSeat(int memType, int idx);		/* fixSeat() : ���ù��� �¼����� */
	bool delSeat(int idx);					/* delSeat() : ���ù��� �¼����� */
	string toChar(string seat);				/* toChar() : 0,1,2 ���ڸ� '��','��','��'�� �ٲ��� */

};
