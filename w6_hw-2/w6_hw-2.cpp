#include<iostream>
#include<math.h>                                //for sqrt
using namespace  std;

int main()
{
    long long num;
    cout << "plz input a positive integer:";

    while (cin >> num)
    {
        long long r;                            //remainder
        cout << num << "=";
        for (int i = 2; i <= sqrt(num); i++)    //find prime factor
        {

            r = num % i;
            while (r == 0)
            {
                num /= i;
                cout << i;
                r = num % i;
                if (num == 1)break;             //void print too more "*"
                cout << "*";
            }
        }
        if (num != 1)cout << num;               //number "1" is not prime factor

    }



    return 0;
}