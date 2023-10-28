#include <iostream>
using namespace std;


int main()
{
	char abc[30];
	cout << "plz input a alphabet:";
	cin >> abc;


	for (int i = 0; abc[i]; i++)
	{
		if (abc[i] >= 'a' && abc[i] <= 'z') abc[i] -= 32;
		else if (abc[i] >= 'A' && abc[i] <= 'Z') abc[i] += 32;
	}
	cout << "after converting:";
	cout << abc;
	return 0;
}