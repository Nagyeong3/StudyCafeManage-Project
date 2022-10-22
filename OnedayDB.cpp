#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct Oneday
{
	string DB_phone_num;
	string DB_payment_date;
	string DB_expert_date;
	string DB_seat_num;
	string DB_arrival_time;
	string DB_departure_time;

	Oneday* next = (Oneday*)malloc(sizeof(Oneday));
	Oneday() {};
	Oneday(string num, string paydate, string expertdate, string seat, string arrivaltime, string departtime)
		:DB_phone_num(num), DB_payment_date(paydate), DB_expert_date(expertdate), DB_seat_num(seat), DB_arrival_time(arrivaltime), DB_departure_time(departtime) {};
}Oneday;
//typedef struct Node
//{
//	Season season;
//	struct Node* pNext;
//}Node;
//
//Node* pHead = NULL;
//Node* pTail = NULL;
class OnedayDB
{
public:
	Oneday* start;
	Oneday* current;

	bool readFile();
	bool writeFile();
	//ȸ������
	void signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_date, string depart_date);
	void initList();
	void AddNode(Oneday _ondeday);	//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
	bool deleteSeason(string phonenum);
	void ReEntrance();
	bool searchSeasonDB(string phonenum);	//���� ������ true

};
void OnedayDB::initList()
{
	start = (Oneday*)malloc(sizeof(Oneday));
	current = start;
}
//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
void OnedayDB::AddNode(Oneday _season)
{
	current->next = &_season;
	current = current->next;
	cout << "current checking\n";
	cout << current->DB_seat_num << endl;
}

bool OnedayDB::deleteSeason(string phonenum)
{
	return false;
}

void OnedayDB::ReEntrance()
{
	cout << " ����� �� �������Ͽ����ϴ�\n";
}

bool OnedayDB::searchSeasonDB(string phonenum)
{

	Oneday* current = start;
	current = current->next;
	while (current != NULL)
	{
		if (current->DB_phone_num == phonenum) {
			cout << current->DB_phone_num;
			return true;
		}
		else {
			current = current->next;
		}
		cout << current->DB_phone_num;
	}
	return false;
}


bool OnedayDB::readFile()
{
	string path = "oneday.txt";
	ifstream file(path);
	Oneday oneday;	//Oneday ����ü�� ��ư� ����

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

			//��忡 ����ü���� ����
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
	string path = "season.txt";
	int person_num = 3;	//����� �̿��ڼ�
	int data_num = 5;	//�̿��ڴ� �Է��� ������ ��
	string phone_num;	//��ȭ��ȣ
	string payment_date;	//�����Ͻ�
	string expert_date;	//�����Ͻ�
	string seat_num;	//�ڸ���ȣ
	string arrival_time;	//�Խǽð�
	string departure_time;	//��ǽð�

	ofstream file;
	file.open(path, ios::out);
	current = start;
	while (current != NULL)
	{
		file << person_num;
		file << data_num;
		file << current->DB_phone_num;
		file << current->DB_payment_date;
		file << current->DB_expert_date;
		file << current->DB_seat_num;
		file << current->DB_arrival_time;
		file << current->DB_departure_time;

		current = current->next;

	}
	file.close();
	return true;
}

//int main()
//{
//	OnedayDB oneday;
//	oneday.initList();
//	oneday.readFile();
//	bool tf;
//	oneday.signup("01000000000", "�����Ͻ�", "����", "�ڸ�", "�Խ�", "���");
//	tf = oneday.searchSeasonDB("01000005000");
//	if (tf)
//		cout << "������ ����";
//	else
//		cout << "���� �Ұ�";
//}