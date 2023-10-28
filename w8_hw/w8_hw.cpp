#include <iostream>
#include<time.h>
using namespace  std;

int main()
{
    unsigned seed;
    seed = time(0);
    srand(seed);
    //cout << rand();
    int ans = rand() % 100;                                       //ans generated with random numbers
    int temp, counter = 1;                                        //temp to store cin,counter to count type times
    //cout << ans;


    cout << "plz type ur ans between 0~100,type -1 to end the game:";
    while (cin >> temp)
    {   
        if (temp == -1)                                           //type to quit the game
        {
            cout << "bye bye!";
            break;
        }
        if (temp > 100 || temp < -1)                              //when wrong input
        {
            cout << "wrong input!";
            counter--;
        }
        if (temp == ans)                                          //when ans correct
        {
            cout << "bingo!,the ans is " << ans << endl;
            cout << "u used " << counter << " times to find the ans.";
            break;
        }
        cout << ((temp > ans) ? ("lower") : ("higher")) << endl;  //hint
        cout << "plz type ur ans again:";
        counter++;
    }
    return 0;
}
