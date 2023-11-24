#include<iostream>
#include<time.h>
using namespace std;


void mySwap(int S[], int i,int  j)//func to swap 
{
	/***************
	{8,6,7,5}
	 i j
	
	****************/
	int temp;
	if (i < j && S[i] > S[j])
	{
		temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}
}
//mian
int main()
{
	srand(time(NULL));
	int my_list[10] = { 0 };
	cout << "Ten    random    numbers:";
	for (int i = 1; i <= 10; i++)//use rand() to make a list in 10 ints,and print the origial list
	{
		my_list[i - 1] = rand() % 1000 + 1;
		cout << my_list[i-1]<<" ";
	}
	cout << endl<<"Sorted by bubble sorting:";

	
	for (int j = 9; j >=0; j--)//use for loop to bubble sorting
	{
		for (int i = 0; i < j; i++)
		{
			mySwap(my_list, i, i+1);
		}

	}
	
	
	for (int i = 1; i <= 10; i++)
	{
		cout << my_list[i - 1] << " ";//print the list which is sorted
	}
	return 0;
}