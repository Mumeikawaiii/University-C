#include<iostream>
using namespace std;

int main()
{
    int year;

    cout << "plz input four digit A.D. year:";
    cin >> year;

    if (year < 1000 || year>9999)
    {
        cout << "Wrong input!!";
        return 0;
    }

    /*
    if(year%400==0)cout<<"Leap year";
    else if(year%4==0 && year%100!=0)cout<<"Leap year";
    else cout<<"Common year";
    */

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                cout << "Leap year";
            else
                cout << "Common year";
        }
        else
            cout << "Leap year";
    }
    else
        cout << "Common year";
    return 0;
}