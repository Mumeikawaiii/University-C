#include <iostream>
using namespace  std;

int main()
{
    long long num;
    cout << "plz input a positive integer:";
    cin >> num;                                 //put cin into num
    cout << "factors:";

    for (int i = 2; i <= num; i++)              //find factors
    {
        if (num % i == 0)cout << i << " ";

    }

    return 0;
}