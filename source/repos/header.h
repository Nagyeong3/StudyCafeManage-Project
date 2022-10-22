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
class Time{
    public:
        bool setTime();
        string getTime();
        string toString();
        string getEndTime();

};
class Seat{

    public:
        bool chooseSeat();
};
class Account{
    public:
        string payTicket(string ticket);
};

#endif