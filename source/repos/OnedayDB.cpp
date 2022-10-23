#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

//노드를 연결리스트에 추가하는 함수
void OnedayDB::AddNode(Oneday _oneday)
{

	if (cntSize == 0)
	{
		start->DB_phone_num = _oneday.DB_phone_num;
		start->DB_arrival_time = _oneday.DB_arrival_time;
		start->DB_departure_time = _oneday.DB_departure_time;
		start->DB_expert_date = _oneday.DB_expert_date;
		start->DB_payment_date = _oneday.DB_payment_date;
		start->DB_seat_num = _oneday.DB_seat_num;
		start->next = nullptr;
	}
	else
	{
		Oneday* current = new Oneday();
		current->DB_phone_num = _oneday.DB_phone_num;
		current->DB_arrival_time = _oneday.DB_arrival_time;
		current->DB_departure_time = _oneday.DB_departure_time;
		current->DB_expert_date = _oneday.DB_expert_date;
		current->DB_payment_date = _oneday.DB_payment_date;
		current->DB_seat_num = _oneday.DB_seat_num;
		current->next = nullptr;
		Oneday* temp = start;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = current;
	}
	++cntSize;
}
void OnedayDB::printData()
{
	Oneday* temp = start;
	cout << "printData:\n";
	for (int i = 0; i < cntSize; i++)
	{
		cout << temp->DB_phone_num << endl;
		cout << temp->DB_seat_num << endl;
		cout << temp->DB_arrival_time << endl;
		cout << temp->DB_departure_time << endl;
		cout << temp->DB_expert_date<< endl;
		cout << temp->DB_payment_date << endl;
		cout << temp->DB_seat_num << endl;
		temp = temp->next;
	}
}
//노드 삭제 함수
bool OnedayDB::deleteOneday(string phonenum)
{
	Oneday* temp = start;
	Oneday* del;
	Oneday* swap;
	int nodeIndex = 0;
	//searchOnedayDB에서 전화번호로 탐색하여 인덱스값을 반환 받음
	nodeIndex = searchOnedayDB(phonenum) - 1;
	cout << nodeIndex;
	if (nodeIndex != 0) {
		for (int i = 0; i < nodeIndex - 1; i++)
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



int OnedayDB::searchOnedayDB(string phonenum)
{
	int nodeIndex = 1;
	Oneday* current = start;
	cout << "searchOnedayDB::" << endl;
	cout << "찾을 전화번호:" << phonenum << endl;
	while (current != NULL)
	{
		cout << "노드속 전화번호:" << current->DB_phone_num << endl;
		if (current->DB_phone_num == phonenum) {
			return nodeIndex;
		}
		else {
			current = current->next;
			nodeIndex++;
		}
	}
	cout << "일치하는 회원정보가 없습니다.\n";
	return 0;
}


bool OnedayDB::readFile()
{
	string path = "oneday.txt";
	ifstream file(path);
	Oneday oneday;	//Seaon 구조체에 담아갈 변수

	int person_num = 0;	//정기권 이용자수
	int data_num = 0;	//이용자당 입력할 데이터 수
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
			AddNode(Oneday(phone_num, payment_date, expert_date, seat_num, arrival_time, departure_time));
		}
	}

	return true;
};
void OnedayDB::signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_time, string departure_time)
{
	Oneday oneday;
	AddNode(Oneday(phone_num, payment_date, expert_date, seat_num, arrival_time, departure_time));
}

bool OnedayDB::writeFile()
{
	string path = "oneday.txt";
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
	Oneday* temp = start;
	file << person_num << "\n";
	file << data_num << "\n";
	for (int i = 0; i < person_num; i++)
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

int main()
{
	OnedayDB oneday;
	oneday.readFile();
	//단일권 회원가입
	oneday.signup("전화번호", "결제일시", "만료일시", "-1", "입실시간", "퇴실시간");
	//전화번호에 해당하는 필드 삭제 
	oneday.deleteOneday("01012345888");
	//파일에 쓰기
	oneday.writeFile();

}
