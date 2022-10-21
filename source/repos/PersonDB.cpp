#include <iostream>
#include <string>
#include <fstream>
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
    };
    Person(){
        Seat=0;
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
        Person* search(string phonenum);
        bool readFile();
        bool writeFile();
        bool makeFile();


        
};
void PersonDB::initLinkedList(){
    currentPoint=startPoint;
};
bool PersonDB::addPerson(Person target){
    currentPoint->next=&target;
    currentPoint=currentPoint->next;
    return true;
};
Person* PersonDB::search(string phonenum){
    Person* current=startPoint;
    while(true){
        if(current->PhoneNum==phonenum){
            break;
        }
        else {
            if(current->next!=NULL){
                current=current->next;
            }else{
                break;
            }
        }
    }
    return NULL;
};
bool PersonDB::deletePerson(string phonenum){
    Person* current=startPoint;
    Person* next=startPoint->next;
    if(current->PhoneNum==phonenum){
        startPoint=next;
        return true;
    }
    while(true){
        if(next->PhoneNum==phonenum){
            return true;
        }
        else {
            current=next;
            if(next->next!=NULL){
            next=next->next;    
            }else break;
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