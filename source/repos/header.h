#include <string>
#include <iostream>
#include <fstream>

#ifndef _HEADER_H
#define _HEADER_H
struct Person{
//PersonDB 내의 각 객체 Person
};

class PersonDB{
//Person 을 저장하는 PersonDB
    public:
    //startpoint는 공백!
        Person* startPoint;
        Person* currentPoint;
    
    private:
        void initLinkedList();
        Person nextPerson();
        bool addPerson(Person target);
        bool deletePerson(string phonenum); 
        Person* searchPerson(string phonenum);
        void showPersonInfo(string phonenum);
        bool readFile();
        bool writeFile();
        bool makeFile();       
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
        string leftTime(string finish); //남은시간 계산
        void showTime(); //시간출력 함수
        bool setTime();
        string getTime();
        string toString();
        string getEndTime();

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