#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	int PointInCircle = 0;
	int point = 5000000;
	for (int i = 0; i < point; i++)
	{
		double x = (double)rand() / RAND_MAX * 2 - 1;//除以randmax(確保在0~1)在乘2->(0,2) 在左移1->(-1,1)
		double y = (double)rand() / RAND_MAX * 2 - 1;

		double d = sqrt(x * x + y * y);

		if (d < 1 || d == 1) PointInCircle++;

	}
	double Pi = ((double)PointInCircle / point) * 4;

	cout << "Pi is:" << fixed << setprecision(6) << Pi;

}