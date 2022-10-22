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
	Oneday* start = new Oneday();	//���۳��

	bool readFile();	//oneday.txt �д� �Լ�
	bool writeFile();	//oneday.txt ���� �Լ�
	//ȸ������
	void signup(string phone_num, string payment_date, string expert_date, string seat_num, string arrival_date, string depart_date);

	void AddNode(Oneday _oneday);	//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
	void printData();
	bool deleteOneday(string phonenum);
	int searchOnedayDB(string phonenum);	//���� ������ ����ε���+1 ��ȯ
private:
	int cntSize = 0;
};

//��带 ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
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
		cout << temp->DB_seat_num << endl;
		temp = temp->next;
	}
}
//��� ���� �Լ�
bool OnedayDB::deleteOneday(string phonenum)
{
	Oneday* temp = start;
	Oneday* del;
	Oneday* swap;
	int nodeIndex = 0;
	//searchOnedayDB���� ��ȭ��ȣ�� Ž���Ͽ� �ε������� ��ȯ ����
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
	cout << "ã�� ��ȭ��ȣ:" << phonenum << endl;
	while (current != NULL)
	{
		cout << "���� ��ȭ��ȣ:" << current->DB_phone_num << endl;
		if (current->DB_phone_num == phonenum) {
			return nodeIndex;
		}
		else {
			current = current->next;
			nodeIndex++;
		}
	}
	cout << "��ġ�ϴ� ȸ�������� �����ϴ�.\n";
	return 0;
}


bool OnedayDB::readFile()
{
	string path = "oneday.txt";
	ifstream file(path);
	Oneday oneday;	//Seaon ����ü�� ��ư� ����

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
	return true;}

int main()
{
	OnedayDB oneday;
	oneday.readFile();
	//��ȭ��ȣ�� �ش��ϴ� �ʵ� ���� 
	oneday.deleteOneday("01012345888");
	//���Ͽ� ����
	oneday.writeFile();

}
