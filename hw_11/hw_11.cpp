#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;



double approxPIsquared_iter(long Times)
{
	double Pisq = 0.;
	long denominator;
	for (int i = 1; i <= Times; i++)
	{
		denominator = pow((2 * i - 1), 2);
		Pisq += 8. / denominator;
	}
	return sqrt(Pisq);
	
}
double approxPIsquared_recur(long Times, double Pisq = 0., long denominator=1,long iteration=1)
{
	if (iteration > Times)
	{
		return sqrt( Pisq);
	}
	else
	{
		Pisq += 8./(pow(denominator, 2));
		denominator += 2;
		return approxPIsquared_recur(Times,Pisq,denominator,iteration+1);
	}
	
}
int main()
{
	long Times;
	cout << "How many numbers are in the series:";
	cin >> Times;
	cout<< "Approximation of Pi (iterative): " << fixed << setprecision(6) <<approxPIsquared_iter(Times)<<endl;
	cout << "Approximation of Pi (recursive): "<< fixed << setprecision(6) <<approxPIsquared_recur(Times);
	return 0;
}