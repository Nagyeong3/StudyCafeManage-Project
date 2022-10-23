#include <string>
#include <iostream>
#include <fstream>

#ifndef _HEADER_H
#define _HEADER_H
#define SEAT_MAX 30

class Person{
//PersonDB 내의 각 객체 Person
    public:
        string PhoneNum;
        string Name;
        string Seat;
        string startDate;
        string endDate; 
        Person* next;
        Person(string num,string name ,string seat,string startdate,string enddate):PhoneNum(num),Name(name),Seat(seat),startDate(startdate),endDate(enddate){
            next=NULL;
        };
        Person(){
            Seat="0";
            next=NULL;
        };
};
class PersonDB{
//Person 을 저장하는 PersonDB
    public:    
    //startpoint는 공백!
        Person* startPoint=new Person();
        int size;
        SeasonDB seasonDB;
        OnedayDB onedayDB;
        SeatDB seatDB;
        Time time;
        PersonDB();
        PersonDB(SeasonDB Season,OnedayDB Oneday,SeatDB Seat);
        //LinkedList 관리
        void initLinkedList();
        Person nextPerson();
        bool addPerson(Person target);
        bool deletePerson(string PhoneNum); 
        Person* searchPerson(string PhoneNum);
        void showPersonInfo(string PhoneNum);
        
        //File I/O
        bool readFile();
        bool writeFile();

        //회원가입
        bool signup();
        bool signup(string PhoneNum);

        //검증
        bool checkPhoneNum(string PhoneNum);
        bool checkName(string Name);
        bool checkSeat(string Seat);
        bool checkDate(string Date);

        //입력
        string inputPhoneNum();
        string inputName();
        string inputSeat();
        string inputDate();
};
class Time {
    private:
        int Date, Time;
        int bY, bM, bD, bH, bmin;
        int Y,M,D,H,min;
    public:
        void readData();
        void insertTime(); //시간입력함수
        void cleanDB(); //정기권,단일권 정리
        string leftTime(string seatnum,string finish); //남은시간 계산
        void showTime(); //시간출력 함수
        bool setTime();
        string getTime();
        string toString();
        string getEndTime();
        bool checkTime(string inputTime);
};

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
class Account {
    public:
        int totalAccount;
        int Y, M, D, H, min;

        void readDB();
        void writeDB();
        void showAccount();
        string int2string(int I);
        string payTicket(string seat);  //����
};

class Oneday
{
    public:
        Oneday* next = nullptr;
        string DB_phone_num;
        string DB_payment_date;
        string DB_expert_date;
        string DB_seat_num;
        string DB_arrival_time;
        string DB_departure_time;


        Oneday() {};
        Oneday(string num, string paydate, string expertdate, string seat, string arrivaltime, string departtime)
            :DB_phone_num(num), DB_payment_date(paydate), DB_expert_date(expertdate), DB_seat_num(seat), DB_arrival_time(arrivaltime), DB_departure_time(departtime) {};
};

class OnedayDB
{
    public:
        Oneday* start = new Oneday();	//시작노드

        bool readFile();	//oneday.txt 읽는 함수
        bool writeFile();	//oneday.txt 쓰는 함수
        //회원가입
        void signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_date, string depart_date);
        //노드를 연결리스트에 추가하는 함수
        void AddNode(Oneday _oneday);	
        void printData();
        //DB 삭제할 때 몇번째 노드인지 확인용 함수 
        int searchOnedayDB(string phonenum);
        bool deleteOneday(string phonenum);
    private:
        int cntSize = 0;
};
class Season
{
    public:
        Season* next = nullptr;
        string DB_phone_num;
        string DB_payment_date;
        string DB_expert_date;
        string DB_seat_num;
        string DB_arrival_time;
        string DB_departure_time;    
        Season() {};
        Season(string num, string paydate, string expertdate, string seat, string arrivaltime, string departtime)
    		:DB_phone_num(num), DB_payment_date(paydate), DB_expert_date(expertdate), DB_seat_num(seat), DB_arrival_time(arrivaltime), DB_departure_time(departtime) {};
};

class SeasonDB 
{
    public:
        Season* start = new Season();
        //Season* current = new Season();
        
        bool readFile();	
        bool writeFile();
        //회원가입
        void signup(string phone_num,string payment_date,string expert_date,string seat_num,string arrival_date,string depart_date);
        
        void AddNode(Season _Season);	//노드를 연결리스트에 추가하는 함수
        void printData();
        bool deleteSeason(string phonenum);
        void ReEntrance();
        int searchSeasonDB(string phonenum);	//전번 있으면 true
    private:
        int cntSize = 0;
};


#endif