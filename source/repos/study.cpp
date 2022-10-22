#include <iostream>

using namespace std;

int quotient(int first, int second) 
{
	if (second == 0)
		throw 0;
	
	return first / second;

}

int main() 
{
	int num1, num2, result;
	for (int i = 0; i < 5; i++) 
	{
		cout << "Enter in Integer: ";
		cin >> num1;
		cout << "Enter in Integer: ";
		cin >> num2;
	
		cout << "이해나 파이팅!!!!!" << endl;
		/*if (result == -1)

			cout << "The result of division is:" << result << endl;
		else
			cout << "result of division is: " << result << endl;*/
		try 
		{
			
			cout << "result of division is:" << quotient(num1, num2)<<endl;
		}
		catch (int x) 
		{
			cout << "\n" << endl;
		}
	}
	return 0;
}