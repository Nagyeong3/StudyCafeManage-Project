#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;


struct Person{
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
        bool makeFile();      
        
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
        string output;
        string currentTime;
        string leftTime;
        // Seat seat=new Seat(rtn->Seat);
        // output=seat.tostring(); 
        //Time time=new Time();
        //time.setTime();
        //currentTime=time.getTime();
        //leftTime=time.getleftTime(rtn->endDate);
        //2022-09-28 16:15:54 ] 구본무 고객님 / 단일권 2시간 34분 남았습니다.
      
        cout<<currentTime<<"]"<<rtn->Name<<"고객님/"<<output<<" "<<leftTime<<"남았습니다."<<endl;

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
bool PersonDB::signup(){
    //회원가입

    //checkPhoneNum();
};
bool PersonDB::signup(string PhoneNum){

};
bool PersonDB::checkPhoneNum(string PhoneNum){

};
bool PersonDB::checkName(string Name){

};
bool PersonDB::checkSeat(string Seat){

};
bool PersonDB::checkDate(string Date){

};
string PersonDB::inputPhoneNum(){
    string PhoneNum;
    do{
        cout<<"회원의 전화번호를 입력하세요(-없이):"<<endl;
        cin>>PhoneNum;
    }while(!checkPhoneNum(PhoneNum));
    return PhoneNum;
};
string PersonDB::inputName(){
    string Name;
    do{
        cout<<"회원의 이름을 입력하세요(최대5자):"<<endl;
        cin>>Name;
    }while(!checkPhoneNum(Name));
    return Name;
};
string PersonDB::inputSeat(){
string Seat;
    do{
        cout<<"회원권 종류를 입력하세요:"<<endl;
        cin>>Seat;
    }while(!checkPhoneNum(Seat));
    return Seat;
};
// string PersonDB::inputDate(){
// string Date;
//     do{
//         cout<<"회원의 전화번호를 입력하세요(-없이):"<<endl;
//         cin>>Date;
//     }while(!checkPhoneNum(Date));
//     return Date;
// };