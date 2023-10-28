#include<iostream>
using namespace std;

int main()
{

    /*****************************************
     int F[100]={0};
     F[0]=0;
     F[1]=1;
     for(int i=0;i<=20;i++)
     {
       F[i+2]=F[i+1]+F[i];
       cout<<'F'<<i<<'='<<F[i]<<endl;
     }
   *******************************************/

    long Fn, n = 2, Fn_1 = 1, Fn_2 = 0;
    while (n < 51)
    {
        Fn = Fn_1 + Fn_2;
        cout << "F" << n << "=" << Fn << endl;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
        n++;
    }





    return 0;
}