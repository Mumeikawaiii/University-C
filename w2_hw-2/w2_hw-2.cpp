#include<iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Input the first integer:";
    cin >> num1;
    cout << "Input the second integer:";
    cin >> num2;



    if (num1 > num2)
    {
        cout << "After " << num1 << " is devided by " << num2 << ",the remainder is:" << num1 % num2 << endl;
    }
    else
    {
        cout << "After " << num2 << " is devided by " << num1 << ",the remainder is:" << num2 % num1 << endl;
    }


    /*  cout<<"num1="<<num1<<endl;    //test line
      cout<<"num2="<<num2<<endl;
      cout<<"num1+num2="<<num1+num2; */


    return 0;
}