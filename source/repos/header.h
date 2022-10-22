#include <string>
#include <iostream>
#include <fstream>

#ifndef _HEADER_H
#define _HEADER_H
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
        void readData(int D,int T);
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

class SeatDB{

    public:
        bool chooseSeat();
};
class Account{
    public:
        string payTicket(string ticket);
};
class SeasonDB{
    public:
        void signup(string PhoneNum,string startTime,string endTime,string seat);
};
class OnedayDB{
    public:
        void signup(string PhoneNum,string startTime,string endTime,string seat);
};
#endif