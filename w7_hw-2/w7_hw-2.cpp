#include <iostream>
#include<math.h>
using namespace  std;

long Factorial(int num)
{
    /**********************
    Factorial(int)-> long


    ex:
    Factorial(5)-> 120
    Factorial(3)-> 6
    **********************/
    int temp = 1;
    for (int counter = 1; counter <= num; counter++)
    {
        temp *= counter;
    }
    return temp;
}

int main()
{
    /*********************
    int i;
    cin >> i;
    cout << Factorial(i);  //test
    *********************/
    int n, m, temp;
    cout << "plz input n&m for C(n,m):";
    cin >> n >> m;

    if (n < m)             //ensure n>m
    {
        temp = n;
        n = m;
        m = temp;
    }

    temp = Factorial(n) / (Factorial(m) * Factorial(n - m));  // mian function
    cout << temp;
    return 0;

}