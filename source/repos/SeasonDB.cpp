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
	//ȸ������
	void signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_date, string depart_date);

	void AddNode(Season _Season);	//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
	void printData();
	bool deleteSeason(string phonenum);
	void ReEntrance();
	int searchSeasonDB(string phonenum);	//���� ������ true
private:
	int cntSize = 0;
};

//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
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
//��� ���� �Լ�
bool SeasonDB::deleteSeason(string phonenum)
{
	Season* temp = start;
	Season* del;
	Season* swap;
	int nodeIndex = 0;
	//searchSeasonDB���� ��ȭ��ȣ�� Ž���Ͽ� �ε������� ��ȯ ����
	nodeIndex = searchSeasonDB(phonenum) - 1;
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

void SeasonDB::ReEntrance()
{
	cout << " ����� �� �������Ͽ����ϴ�\n";
}

int SeasonDB::searchSeasonDB(string phonenum)
{
	int nodeIndex = 1;
	Season* current = start;
	int int_seatnum = 100;
	string string_seatnum;
	//SeatDB seat;
	cout << "searchSeasonDB::" << endl;
	cout << "ã�� ��ȭ��ȣ:" << phonenum << endl;
	while (current != NULL)
	{
		cout << "���� ��ȭ��ȣ:" << current->DB_phone_num << endl;
		if (current->DB_phone_num == phonenum) {
			//�ڸ� -1�̸� �������� -> �ڸ��������� ->  db�� �ֱ�
			if (current->DB_seat_num == "-1") {
				cout << "�ڸ��� �������ּ���\n���� �Լ� ȣ���ؼ� �ڸ���ȣ100������ �����޾Ҵٰ� ħ\n";
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
	Season season;	//Seaon ����ü�� ��ư� ����

	int person_num = 0;	//����� �̿��ڼ�
	int data_num = 0;	//�̿��ڴ� �Է��� ������ ��
	string phone_num;	//��ȭ��ȣ
	string payment_date;	//�����Ͻ�
	string expert_date;	//�����Ͻ�
	string seat_num;	//�ڸ���ȣ
	string arrival_time;	//�Խǽð�
	string departure_time;	//��ǽð�
	string null_remove;	//��������

	if (file.is_open())
	{
		cout << "���� ��� Ȯ��\n";
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

			//��忡 Ŭ���� ���� ����
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
	int person_num = cntSize;	//����� �̿��ڼ�
	int data_num = 5;	//�̿��ڴ� �Է��� ������ ��
	string phone_num;	//��ȭ��ȣ
	string payment_date;	//�����Ͻ�
	string expert_date;	//�����Ͻ�
	string seat_num;	//�ڸ���ȣ
	string arrival_time;	//�Խǽð�
	string departure_time;	//��ǽð�

	ofstream file;
	file.open(path, ios::out);
	Season* temp = start;
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

//int main() 
//{
//	SeasonDB season;
//	
//	season.readFile();
//	bool tf;
//  
//	season.signup("��ȭ��ȣ","�����Ͻ�","�����Ͻ�","-1","�Խǽð�","��ǽð�");
//	//������ ����
//	tf=season.searchSeasonDB("��ȭ��ȣ");
//	if (tf)
//
//		cout << "������ ����\n";
//	else
//		cout << "���� �Ұ�\n";
//	//��� ����
//	tf = season.searchSeasonDB("01037937506");
//	season.deleteSeason("01037937506");
//
//	//season.deleteSeason("01012345888");
//	season.writeFile();
//
//}