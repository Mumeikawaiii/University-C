#include <iostream>
#include<math.h>
using namespace  std;

bool is_prime(int num)
{
    /*******************
    is_prime(int)->boll

    ex:
    is_prime(2)-> true
    is_prime(97)->true
    is_prime(10)->false
    ********************/

    int temp;
    if (num == 2) return true;
    for (int counter = 2; counter < sqrt(num) + 1; counter++)
    {
        temp = (num % counter == 0) ? 1 : 0;
        if (temp == 1) return false;
    }
    if (num > 1) return true;
}

int main()
{
    long long num;
    cout << "plz input a positive integer:";
    cin >> num;                                 //put cin into num
    cout << "prime factors:";

    for (int i = 2; i <= num; i++)              //find factors
    {
        if (num % i == 0)
        {
            if (is_prime(i)) cout << i << " ";
        }

    }

    return 0;
}