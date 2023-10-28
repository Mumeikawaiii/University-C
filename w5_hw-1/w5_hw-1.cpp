#include <iostream>
using namespace  std;

int main()
{
    int layer;
    cout << "plz input the hight of ur pyramid:";
    cin >> layer;

    for (int i = 0; i < layer; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "x";
        }
        cout << endl;

    }



    return 0;
}