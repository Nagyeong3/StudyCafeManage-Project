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
    private:
    //startpoint는 공백!
        Person* startPoint;
        Person* currentPoint;
        SeasonDB seasonDB;
        OnedayDB onedayDB;
        SeatDB seatDB;
        static PersonDB personDB;
    
    public:
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
PersonDB::PersonDB(SeasonDB Season,OnedayDB Oneday,SeatDB Seat){
    initLinkedList();
    seasonDB=Season;
    onedayDB=Oneday;
    seatDB=Seat;
}
void PersonDB::initLinkedList(){
    //초기화
    Person* startPoint=(Person*)malloc(sizeof(Person*));
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
        string seatNum=rtn->Seat;
        string output;
        if(seatNum.compare("1")){
            output="정기권(지정석)";
        }else if(seatNum.compare("2")){
            output="정기권(자유석)";
        }else {
            output="단일권";
        }
        Time time;
        time.insertTime();
        leftTime=time.leftTime(rtn->endDate);
        //2022-09-28 16:15:54 ] 구본무 고객님 / 단일권 2시간 34분 남았습니다.
        time.showTime();
        cout<<"]"<<rtn->Name<<"고객님/"<<output<<" "<<leftTime<<"남았습니다."<<endl;
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
            file<<enter;
            file<<currentPoint->Name;
            file<<enter;          
            file<<currentPoint->Seat;
            file<<enter;
            file<<currentPoint->startDate;
            file<<enter;
            file<<currentPoint->endDate;
            file<<enter;
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
    string PhoneNum=inputPhoneNum();    
    string Name=inputName();
    string inseat=inputSeat();
    if(inseat.compare("1")){
        inseat=seatDB.chooseSeat();    
    }
    cout<<"결제로 이동합니다."<<endl;
    Account acc;
    string endTime=acc.payTicket(inseat);
    Time temp;
    temp.setTime();
    string currentTime=temp.toString();
    cout<<"저장중...."<<endl;
    bool addrnt;
    do{
        addrnt=this->addPerson(Person(PhoneNum,Name,inseat,currentTime,endTime));
    }while(addrnt==false);
    currentPoint=currentPoint->next;
    seasonDB.signup(PhoneNum,currentTime,endTime,inseat);
    cout<<"회원가입이 완료되었습니다."<<endl;
};
bool PersonDB::signup(string PhoneNum){
    string Name=inputName();
    string inseat=inputSeat();
    string seatNum;
    if(inseat.compare("1")){
        seatNum=seatDB.chooseSeat();    
    }
    cout<<"결제로 이동합니다."<<endl;
    Account acc;
    string endTime=acc.payTicket(inseat);
    Time temp;
    temp.setTime();
    string currentTime=temp.toString();
    cout<<"저장중...."<<endl;
    bool addrnt;
    do{
        addrnt=this->addPerson(Person(PhoneNum,Name,inseat,currentTime,endTime));
    }while(addrnt==false);
    currentPoint=currentPoint->next;
    if(inseat.compare("3")){
        //단일권
        onedayDB.signup(PhoneNum,currentTime,endTime,seatNum);    
    }
    else{
        seasonDB.signup(PhoneNum,currentTime,endTime,seatNum);    
    }
    cout<<"회원가입이 완료되었습니다."<<endl;
};
bool PersonDB::checkPhoneNum(string PhoneNum){
    //올바른 입력 : 01012341234
    // 010 011 지원 이외는 안지원!
    // 7자 or 8자
    // 
    if(PhoneNum.length()>11){
        cout<<"전화번호는 11자 이하여야 합니다."<<endl;
        return false;
    }else if(PhoneNum.length()<10){
        cout<<"전화번호는 10자 이상이여야 합니다."<<endl;
        return false;
    }

    const char* varify=PhoneNum.c_str();
    string start=PhoneNum.substr(0,3);
    string cmp1="010";
    string cmp2="011";
    if(start.compare(cmp1)!=0&&start.compare(cmp2)!=0){
        cout<<"전화번호는 010 또는 011로 시작하여야 합니다."<<endl;
        return false;
    }
    if(PhoneNum.length()==11||PhoneNum.length()==10){
        for(int j=3;j<11;j++){
            if(varify[j]<'0'||varify[j]>'9'){
                cout<<"전화번호는 숫자를 입력하여야합니다."<<endl;
                return false;
            }
        }
        return true;    
    }else return false;
};
bool PersonDB::checkName(string Name){
    // 올바른 입력 : 구본무 구본 구 ㄱ ㅡ 다 ok
    // 5글자 이하면 다 ok. 
    if(Name.length()>5){
        cout<<"이름은 5자 이하여야 합니다."<<endl;
        return false;
    }
    const char* varify=Name.c_str();
    for(int i=0;i<Name.length();i++){
        //한글 아님
        if(varify[i]&0x80!=1){
            cout<<"이름은 한글이여 합니다."<<endl;
            return false;
        }
    }
    return true;
};
bool PersonDB::checkSeat(string Seat){
    if(Seat.compare("3")||Seat.compare("2")||Seat.compare("1")||Seat.compare("0")){
        return true;
    }
    cout<<"좌석을 다시 입력하세요"<<endl;
    return false;
};
bool PersonDB::checkDate(string Date){
    double date;
    // Time temp;
    // return temp.checkdate(Date);
};
string PersonDB::inputPhoneNum(){
    string PhoneNum;
    do{
        cout<<"회원의 전화번호를 입력하세요(-없이):"<<endl;
        cout<<">>";
        cin>>PhoneNum;
    }while(!checkPhoneNum(PhoneNum));
    cin.clear();
    return PhoneNum;
};
string PersonDB::inputName(){
    string Name;
    do{
        cout<<"회원의 이름을 입력하세요(최대5자):"<<endl;
        cout<<">>";
        cin>>Name;
    }while(!checkName(Name));
    cin.clear();    
    return Name;
};
string PersonDB::inputSeat(){
string Seat;
    do{
        cout<<"스터디카페 회원권 종류를 입력하세요 :"<<endl;
        cout<<"1. 정기권 - 지정석"<<endl;
        cout<<"2. 정기권 - 자유석"<<endl;
        cout<<"3. 단일권 - 자유석"<<endl;
        cout<<">>";
        cin>>Seat;
    }while(!checkSeat(Seat));
    cin.clear();
    return Seat;
};
string PersonDB::inputDate(){
string Date;
    do{
        cout<<"회원의 전화번호를 입력하세요(-없이):"<<endl;
        cin>>Date;
    }while(!checkDate(Date));    
    cin.clear();
    return Date;
};