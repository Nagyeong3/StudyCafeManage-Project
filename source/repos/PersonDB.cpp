#include "header.h"
using namespace std;

PersonDB::PersonDB(SeasonDB Season,OnedayDB Oneday,SeatDB Seat,Time time){
    initLinkedList();
    seasonDB=Season;
    onedayDB=Oneday;
    seatDB=Seat;
    time=time;
}
void PersonDB::initLinkedList(){
    //초기화
    size=0;
};
bool PersonDB::addPerson(Person target){
    //linkedlist에 
    if (size == 0) 
	{
		startPoint->PhoneNum=target.PhoneNum;
        startPoint->Name=target.Name;
        startPoint->Seat=target.Seat;
        startPoint->startDate=target.startDate;
        startPoint->endDate=target.endDate;
        startPoint->next=nullptr;
	}
	else 
	{
        Person* currentPoint=new Person();
		currentPoint->PhoneNum=target.PhoneNum;
        currentPoint->Name=target.Name;
        currentPoint->Seat=target.Seat;
        currentPoint->startDate=target.startDate;
        currentPoint->endDate=target.endDate;
        currentPoint->next=nullptr;
		Person* temp = startPoint;
		while (temp->next != nullptr) 
		{
			temp = temp->next;
		}
		temp->next = currentPoint;
	}
	++size;
    return true;
};
Person* PersonDB::searchPerson(string phonenum){
    
    int currentIndex=1;
    Person* current=startPoint;
    // while(currentIndex!=size){
    while(current!=nullptr){
        if(current->PhoneNum.compare(phonenum)){
            return current;
        }
        else {
            current=current->next;
            currentIndex++;
        }
    }
    return NULL;
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
        leftTime=time.leftTime(seatNum,rtn->endDate);
        //2022-09-28 16:15:54 ] 구본무 고객님 / 단일권 2시간 34분 남았습니다.
        time.showTime();
        cout<<"]"<<rtn->Name<<"고객님/"<<output<<" "<<leftTime<<"남았습니다."<<endl;
    }
};
bool PersonDB::deletePerson(string phonenum){
    Person* current=startPoint->next;
    Person* prev=startPoint;
    if(prev!=NULL&&prev->PhoneNum==phonenum){
        startPoint=prev->next;
        free(prev);
    }
    else if(current)
    cout<<"존재하지 않는 회원입니다."<<endl;
    return false;
};
bool PersonDB::readFile(){
    string path="ticket.txt";
    ifstream file(path);
    string inputPhoneNum;
    string inputName;
    string inputSeat;
    string inputStarttime;
    string inputendtime;
    string line;
    while(file.is_open()){
        getline(file,inputPhoneNum,'\n');
        getline(file,inputName,'\n');
        getline(file,inputSeat,'\n');
        getline(file,inputStarttime,'\n');
        getline(file,inputendtime,'\n');
        // Person newperson(inputPhoneNum,inputName,inputSeat,inputStarttime,inputendtime);
        addPerson(Person(inputPhoneNum,inputName,inputSeat,inputStarttime,inputendtime));
        if(!getline(file,line)){
            file.close();
        }
    }
};
bool PersonDB::writeFile(){
    string path="ticket.txt";
    char* enter="\n";
    try{
        ofstream file;
        file.open(path,ios::out);
        //WRITE
        Person* target=startPoint;
        while(target!=NULL){
            file<<target->PhoneNum<<enter;
            file<<target->Name<<enter;
            file<<target->Seat<<enter;
            file<<target->startDate<<enter;
            file<<target->endDate<<enter;
            file<<enter;
            target=target->next;
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
    seasonDB.signup(PhoneNum,currentTime,endTime,inseat);
    cout<<"회원가입이 완료되었습니다."<<endl;
};
bool PersonDB::signup(string PhoneNum){
    string Name=inputName();
    string inseat=inputSeat();
    int seatInt;
    string seatNum;
    if(inseat.compare("1")){
        seatInt=seatDB.chooseSeat();
        seatNum=to_string(seatInt);   
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
    if(inseat.compare("1")){
        //정기권 지정석
        onedayDB.signup(PhoneNum,currentTime,endTime,seatNum);    
    }
    else{
        //지금 자리없고 이따 필요할때
        seasonDB.signup(PhoneNum,currentTime,endTime,"0");    
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