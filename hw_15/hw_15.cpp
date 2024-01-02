#include<iostream>
#include<ctime>
using namespace std;



int Dinter_Probability()
{
	int counter = 0;
	for (int i = 0; i < 471; ++i) //E is approximately equal to 47.1
	{
		if (rand() % 10 == 0)
		{
			counter += 1;
		}
	}
	return counter;

}

int main()
{
	srand(time(NULL));
	//cout << Dinter_Probability();
	int n = 1000;
	int SSR = 0, SR = 0, R = 0, N = 0, others = 0;
	/**********
	SSR for <11
	SR for <20
	R for <30
	N for <40
	**********/
	for (int i = 0; i < n; i++)
	{
		int temp = Dinter_Probability();
		if (temp <= 11) SSR += 1;
		else if (temp <= 20) SR += 1;
		else if (temp <= 30) R += 1;
		else if (temp <= 40) N += 1;
		else others += 1;
	}
	//cout << others << "\t" << N << "\t" << R << "\t" << SR << "\t" << SSR << "\n\n";
	cout << "The estimated prob. of winning>40 items: " << (double)others / n;
	cout << "\nThe estimated prob. of winning<=40 items: " << (double)N / n;
	cout << "\nThe estimated prob. of winning<=30 items: " << (double)R / n;
	cout << "\nThe estimated prob. of winning<=20 items: " << (double)SR / n;
	cout << "\nThe estimated prob. of being unlucky as Dinter(<=11 items): " << (double)SSR / n;
	return 0;
}