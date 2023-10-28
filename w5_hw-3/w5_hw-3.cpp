#include <iostream>
using namespace  std;

int main()
{
    int layer, k;
    cout << "plz input the hight of ur pyramid:";



    while (cin >> layer)
    {

        for (int i = 1; i <= layer; i++)            //coculate the pyramid layer
        {

            for (int j = 0; j < i - 1; j++)
            {
                cout << " ";                       //print blank
            }
            for (int j = layer * 2 - i * 2 + 1; j > 0; j--)
            {
                cout << "x";
            }

            cout << endl;                          //when time to change line,endl
            if (i == layer)k = -1;
        }
        if (k == -1) break;

    }


    return 0;
}