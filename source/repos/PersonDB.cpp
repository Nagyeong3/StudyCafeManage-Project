#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;


typedef struct Person{
//PersonDB 내의 각 객체 Person
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
void PersonDB::initLinkedList(){
    //초기화
    currentPoint=startPoint;
};
bool PersonDB::addPerson(Person target){
    //linkedlist에 
    currentPoint->next=&target;
    currentPoint=&target;
    return true;
};
Person* PersonDB::searchPerson(string phonenum){
    Person* current=startPoint->next;
    while(true){
        if(current->PhoneNum==phonenum){
            return current;
        }
        else {
            if(current->next!=NULL){
                current=current->next;
            }else{
                return NULL;
            }
        }
    }
};
void PersonDB::showPersonInfo(string phonenum){
    Person* rtn=searchPerson(phonenum);
    if(rtn==NULL){
        cout<<"존재하지 않는 회원입니다.";
    }
    else{
        cout<<
    }
};
bool PersonDB::deletePerson(string phonenum){
    Person* current=startPoint->next;
    Person* prev=startPoint;
    while(current!=NULL){
        if(current->PhoneNum==phonenum){
            prev->next=current->next;
            free(current);
            return true;
        }
    }
    return false;
};

bool PersonDB::readFile(){
    string path="ticket.txt";
    ifstream file(path);
    this->currentPoint=this->startPoint;
    string inputPhoneNum;
    string inputName;
    string inputSeat;
    string inputStarttime;
    string inputendtime;
    while(file.is_open()){
        getline(file,inputPhoneNum,'\n');
        getline(file,inputName,'\n');
        getline(file,inputSeat,'\n');
        getline(file,inputStarttime,'\n');
        getline(file,inputendtime,'\n');
        this->addPerson(Person(inputPhoneNum,inputName,inputSeat,inputStarttime,inputendtime));
        currentPoint=currentPoint->next;
    }
};
bool PersonDB::writeFile(){
    string path="ticket.txt";
    char* enter="\n";
    try{
        ofstream file;
        file.open(path,ios::out);
        //WRITE
        this->currentPoint=this->startPoint;
        while(currentPoint!=NULL){
            file<<currentPoint->PhoneNum;
            file<<currentPoint->Name;
            file<<currentPoint->Seat;
            file<<currentPoint->startDate;
            file<<currentPoint->endDate;
            currentPoint=currentPoint->next;
        }
        file.close();
        return true;
    }catch(exception &e){
        return false;
    }
};