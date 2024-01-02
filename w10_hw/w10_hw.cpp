#include <iostream>
#include <time.h>

using namespace std;

// Function to simulate the Monty Hall Problem with a given strategy
bool simulateMontyHall(bool switchDoor)
{
    int doors[3] = { 0, 0, 1 };// Initialize doors: 0 for goat, 1 for car

    // set the door in random
    for (int i = 2; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(doors[i], doors[j]);
    }


    int playerChoice = rand() % 3;
    int hostOpen;

    do
    {
        hostOpen = rand() % 3;
    } while (hostOpen == playerChoice || doors[hostOpen] == 1);//host can't open the door which has a car and pleyer choose

    // Player switches or not based on the strategy
    if (switchDoor)
    {
        // Player switches to the other unopened door
        for (int i = 0; i < 3; ++i)
        {
            if (i != playerChoice && i != hostOpen)
            {
                playerChoice = i;
                break;
            }
        }
    }

    // Player wins if the chosen door has a car
    return doors[playerChoice] == 1;
}



int main()
{
    srand(time(0));
    const int simulations = 5000;

    // Counters for wins with each strategy
    int winsSwitch = 0;
    int winsNoSwitch = 0;

    //simulation 5000 times
    for (int i = 0; i < simulations; ++i)
    {
        // Always switch
        if (simulateMontyHall(true))
        {
            winsSwitch++;
        }

        //Never switch
        if (simulateMontyHall(false))
        {
            winsNoSwitch++;
        }
    }
    double NS_rate = winsNoSwitch / 5000.;
    double S_rate = winsSwitch / 5000.;

    cout << "If u don't switch, the prob.of winning is:" << NS_rate << endl;//it should be approach 1/3
    cout << "If u switch,the prob.of winning is:" << S_rate << endl;//it should be approach 2/3

    return 0;
}
