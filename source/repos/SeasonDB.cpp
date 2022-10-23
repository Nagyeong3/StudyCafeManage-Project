#include <iostream>
#include <fstream>
#include <string>

using namespace std;
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

//노드를 연결리스트에 추가하는 함수
void SeasonDB::AddNode(Season _season)
{	
	
	if (cntSize == 0) 
	{
		start->DB_phone_num = _season.DB_phone_num;
		start->DB_arrival_time = _season.DB_arrival_time;
		start->DB_departure_time = _season.DB_departure_time;
		start->DB_expert_date = _season.DB_expert_date;
		start->DB_payment_date = _season.DB_payment_date;
		start->DB_seat_num = _season.DB_seat_num;
		start->next = nullptr;
	}
	else 
	{
		Season* current = new Season();
		current->DB_phone_num = _season.DB_phone_num;
		current->DB_arrival_time = _season.DB_arrival_time;
		current->DB_departure_time = _season.DB_departure_time;
		current->DB_expert_date = _season.DB_expert_date;
		current->DB_payment_date = _season.DB_payment_date;
		current->DB_seat_num = _season.DB_seat_num;
		current->next = nullptr;
		Season* temp = start;
		while (temp->next != nullptr) 
		{
			temp = temp->next;
		}
		temp->next = current;
	}
	++cntSize;
}
void SeasonDB::printData() 
{
	Season* temp = start;
	cout << "printData:\n";
	for (int i = 0; i < cntSize; i++) 
	{
		cout << temp->DB_seat_num << endl;
		temp = temp->next;
	}
}
//노드 삭제 함수
bool SeasonDB::deleteSeason(string phonenum)
{
	Season* temp = start;
	Season* del;
	Season* swap;
	int nodeIndex = 0;
	//searchSeasonDB에서 전화번호로 탐색하여 인덱스값을 반환 받음
	nodeIndex = searchSeasonDB(phonenum)-1;
	cout << nodeIndex;
	if (nodeIndex != 0) {
		for (int i = 0; i < nodeIndex-1; i++) 
		{
			temp = temp->next;
		}
		del = temp->next;
		swap = del->next;
		temp->next = swap;
	}
	else {
		start = temp->next;
		del = temp;
	}
	delete del;
	cntSize--;
	return true;

}

void SeasonDB::ReEntrance()
{
	cout << " 정기권 고객 재입장하였습니다\n";
}

int SeasonDB::searchSeasonDB(string phonenum)
{
	int nodeIndex=1;
	Season* current = start;
	int int_seatnum = 100;
	string string_seatnum;
	//SeatDB seat;
	cout << "searchSeasonDB::" << endl;
	cout << "찾을 전화번호:" << phonenum<<endl;
	while (current !=NULL) 
	{
		cout << "노드속 전화번호:" << current->DB_phone_num<<endl;
		if (current->DB_phone_num == phonenum) {
			//자리 -1이면 자유석임 -> 자리선택해줘 ->  db에 넣기
			if (current->DB_seat_num == "-1") {
				cout << "자리를 선택해주세요\n찬양 함수 호출해서 자리번호100번으로 배정받았다고 침\n";
				//int_seatnum=seat.chooseSeat();
				current->DB_seat_num = to_string(int_seatnum);
			}
			return nodeIndex;
		}
		else {
			current = current->next;
			nodeIndex++;
		}
	}

	return 0;
}


bool SeasonDB::readFile()
{
	string path = "season.txt";
	ifstream file(path);
	Season season;	//Seaon 구조체에 담아갈 변수

	int person_num=0;	//정기권 이용자수
	int data_num=0;	//이용자당 입력할 데이터 수
	string phone_num;	//전화번호
	string payment_date;	//결제일시
	string expert_date;	//만료일시
	string seat_num;	//자리번호
	string arrival_time;	//입실시간
	string departure_time;	//퇴실시간
	string null_remove;	//공백제거

	if (file.is_open())
	{
		cout << "파일 출력 확인\n";
		file >> person_num;
		file >> data_num;
		//cout << person_num << data_num<<endl;
		getline(file, null_remove, '\n');
		for (int i = 0; i < person_num; i++) {
			getline(file, phone_num, '\n');
			getline(file, payment_date, '\n');
			getline(file, expert_date, '\n');
			getline(file, seat_num, '\n');
			getline(file, arrival_time, '\n');
			getline(file, departure_time, '\n');
		
			//노드에 클래스 정보 저장
			AddNode(Season(phone_num, payment_date, expert_date, seat_num, arrival_time, departure_time));
		}
	}
	
	return true;
};
void SeasonDB::signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_time, string departure_time)
{
	Season season;
	AddNode(Season(phone_num, payment_date, expert_date, seat_num, arrival_time, departure_time));
}

bool SeasonDB::writeFile() 
{
	string path = "season.txt";
	int person_num = cntSize;	//정기권 이용자수
	int data_num = 5;	//이용자당 입력할 데이터 수
	string phone_num;	//전화번호
	string payment_date;	//결제일시
	string expert_date;	//만료일시
	string seat_num;	//자리번호
	string arrival_time;	//입실시간
	string departure_time;	//퇴실시간

	ofstream file;
	file.open(path, ios::out);
	Season* temp = start;
	file << person_num << "\n";
	file << data_num << "\n";
	for (int i = 0; i < person_num ; i++) 
	{
		file << temp->DB_phone_num << "\n";
		file << temp->DB_payment_date << "\n";
		file << temp->DB_expert_date << "\n";
		file << temp->DB_seat_num << "\n";
		file << temp->DB_arrival_time << "\n";
		file << temp->DB_departure_time << "\n";
		temp = temp->next;
	}
	file.close();
	return true;
}

//int main() 
//{
//	SeasonDB season;
//	
//	season.readFile();
//	bool tf;
//
//	season.signup("전화번호","결제일시","만료일시","-1","입실시간","퇴실시간");
//	//재입장 관련
//	tf=season.searchSeasonDB("전화번호");
//	if (tf)
//
//		cout << "재입장 가능\n";
//	else
//		cout << "입장 불가\n";
//	//퇴실 관련
//	tf = season.searchSeasonDB("01037937506");
//	season.deleteSeason("01037937506");
//
//	//season.deleteSeason("01012345888");
//	season.writeFile();
//
//}
