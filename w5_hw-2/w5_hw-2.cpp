#include <iostream>
using namespace  std;

int main()
{
    int layer, k;
    cout << "plz input the hight of ur pyramid:";



    while (cin >> layer)
    {

        for (int i = 1; i <= layer; i++)    //coculate the pyramid layer
        {

            for (int j = 1; j <= layer - i; j++)cout << " ";    //print blank
            for (int j = 1; j <= 2 * i - 1; j++)cout << "x";    //print pyramid layer
            for (int j = 1; j <= layer - i; j++)cout << " ";    //print blank


            cout << endl;   //when time to change line,endl
            if (i == layer)k = -1;
        }
        if (k == -1) break;

    }


    return 0;
}