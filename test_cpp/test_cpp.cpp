#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

unsigned int Euclidean_algorithm(int x, int y)
{
	if (x % y == 0) return y;
	else return Euclidean_algorithm(y, x % y);
}

int main()
{
	int n1, n2;
	cout << "give two integers to find their GCD:\nint1: ";
	cin >> n1;
	cout << "int2: ";
	cin >> n2;
	if (n1 > n2 || n1 == n2) cout<<Euclidean_algorithm(n1, n2);
	else cout<<Euclidean_algorithm(n2, n1);
	return 0;
}