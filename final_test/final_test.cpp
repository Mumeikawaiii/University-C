#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

void deride_system(int loop_counter)//嘲諷系統
{
    if (loop_counter % 3 == 0) cout << "How many times do you have to guess?loser!\n";
}

/****************************************************************/

int DigitsSelection()
{




    bool n = 1;
    int digits;
    while (n)
    {
        cout << "請輸入位數:";
        cin >> digits;
        if (digits <= 9 && digits >= 4)
            break;
        cout << "wrong input,input again!!!" << endl;
    }
    return digits;
}

/***************************************/

void RandomNumberSet(int numberset[], int digits)//單人遊玩時的隨機數字
{
    for (int i = 1, temp; i <= digits; i++)//用陣列存數字的"位數" ex: 5032 ->2 0 4 3 0 1 0 0 0 0 0
    {
        temp = rand() % 10;




        if (numberset[temp] == 0)
        {
            numberset[temp] = i;
            cout << temp << endl;
        }
        else
        {
            i = i - 1;        //重複數字 再random一次
        }
    }
}

/****************************************************/

void UserNumberSet(int answer[], string ans)//雙人模式時設答案用
{
    for (int i = 1; i <= ans.size(); i++)
    {
        answer[int(ans[i - 1]) - 48] = i;     //ascii code :"0" -> 48
    }                  //用陣列存數字的"位數" ex: 5032 ->2 0 4 3 0 1 0 0 0 0 0
}

//*******************************************

bool InputCheckNumberLength(string target, int digits)
{
    if (target.size() != digits)
    {
        cout << "wrong input(wrong length)!!!,input again" << endl;
        return 1;
    }return 0;
}

/*********************************************/

bool InputCheckDuplicateNumbers(string answer, int digits)
{
    for (int i = 0; i < digits - 1; i++)
    {
        for (int j = i + 1; j < digits; j++)
        {
            if (answer[i] == answer[j])
            {
                cout << "wrong input(duplicate numbers)!!!,input again" << endl;
                return 1;
            }
        }
    }return 0;
}

//************************************************

int ResultReport(int answer[], string guess, int digits)//回傳A、B的數量
{
    int AB = 0, guess_trans[digits] = { 0 };        //十位數為A的數量 個位數為B的數量 ex: 12 ->1A2B
    for (int i = 0; i < digits; i++)        //1234->arr{1,2,3,4}
    {
        guess_trans[i] = int(guess[i]) - 48;
    }




    if (!InputCheckNumberLength(guess, digits) && !InputCheckDuplicateNumbers(guess, digits))
    {
        for (int i = 0; i < digits; i++)
        {
            if (answer[guess_trans[i]] != 0)
            {
                if (answer[guess_trans[i]] == i + 1)
                {
                    AB += 10;
                }
                else
                {
                    AB++;
                }
            }
        }




        cout << AB / 10 << "A" << AB % 10 << "B" << endl;
    }
    else
    {
        return -1;
    }
    return AB;
}

//************************************************

void ScoreBoard(int counter) //寫記分板
{
    fstream Score;

    Score.open("Score.txt", ios::app);

    Score << "round:" << counter << endl;;
    Score.close();

}

void Check_ScoreBoard() //印出記分板
{
    string line;

    fstream Score;
    Score.open("Score.txt", ios::in);
    while (getline(Score, line))
    {
        cout << line << endl;
    }
    Score.close();
}
void ClearBoard() //清空記分板(須至main內調整)
{
    fstream Score;
    Score.open("Score.txt", ios::out | ios::trunc);
    Score.close();
}

/****************************************/

void SinglePlayerMode()//單人模式
{
    int answer[10] = { 0 };
    int digits = DigitsSelection();
    RandomNumberSet(answer, digits);   //設答案




    string guess;       //字串記一開始的input(輸入時不用輸空白 較方便)




    int loop_counter = 0;
    do
    {
        cout << "guess the number:";
        cin >> guess;
        deride_system(loop_counter);
        loop_counter += 1;
    } while (ResultReport(answer, guess, digits) != digits * 10); //AB=40時->4A0B 遊戲結束
    ScoreBoard(loop_counter);
}

/*****************************************/

void Competition_Mode()//雙人模式
{
    int digits = DigitsSelection();
    string P1Ans, P2Ans;
    int P1NumberSet[10] = { 0 }, P2NumberSet[10] = { 0 };


    do {
        cout << "Player1 input your answer:" << endl;
        cin >> P1Ans;
    } while (InputCheckNumberLength(P1Ans, digits) || InputCheckDuplicateNumbers(P1Ans, digits));//兩條件不合時=1,故一個不和時就回重新輸入


    do {
        cout << "Player2 input your answer:" << endl;
        cin >> P2Ans;
    } while (InputCheckNumberLength(P2Ans, digits) || InputCheckDuplicateNumbers(P2Ans, digits));


    UserNumberSet(P1NumberSet, P1Ans);      //用陣列存數字的"位數" ex: 5032 ->2 0 4 3 0 1 0 0 0 0 0
    UserNumberSet(P2NumberSet, P2Ans);


    int loop_counter = 0;
    for (int round = 1; round > 0; round++)
    {
        if (round % 2 == 1)
        {
            string Guess1;
            cout << "Player1 round Please Enter the number:" << endl;
            cin >> Guess1;
            int AB = ResultReport(P2NumberSet, Guess1, digits);


            if (AB == digits * 10)
            {
                cout << "The winner is Player1" << endl;
                break;
            }
            else if (AB == -1)
            {
                round--;
            }
            deride_system(loop_counter);
            loop_counter += 1;
        }
        else
        {
            string Guess2;
            cout << "Player2 round Please Enter the number:" << endl;
            cin >> Guess2;
            int AB = ResultReport(P1NumberSet, Guess2, digits);


            if (AB == digits * 10)
            {
                cout << "The winner is Player2" << endl;
                break;
            }
            else if (AB == -1)
            {
                round--;
            }
            deride_system(loop_counter);
            loop_counter += 1;
        }
    }
}

//*************************************

void W2() {      //三戰兩勝制
    int P1Win = 0, P2Win = 0;

    do {
        int digits = DigitsSelection();
        string P1Ans, P2Ans;
        int P1NumberSet[10] = { 0 }, P2NumberSet[10] = { 0 };


        do {
            cout << "Player1 input your answer:" << endl;
            cin >> P1Ans;
        } 
        while (InputCheckNumberLength(P1Ans, digits) || InputCheckDuplicateNumbers(P1Ans, digits));//兩條件不合時=1,故一個不和時就回重新輸入


        do {
            cout << "Player2 input your answer:" << endl;
            cin >> P2Ans;
        }
        while (InputCheckNumberLength(P2Ans, digits) || InputCheckDuplicateNumbers(P2Ans, digits));


        UserNumberSet(P1NumberSet, P1Ans);      //用陣列存數字的"位數" ex: 5032 ->2 0 4 3 0 1 0 0 0 0 0
        UserNumberSet(P2NumberSet, P2Ans);


        int loop_counter = 0;
        for (int round = 1; round > 0; round++)
        {
            if (round % 2 == 1)
            {
                string Guess1;
                cout << "Player1 round Please Enter the number:" << endl;
                cin >> Guess1;
                int AB = ResultReport(P2NumberSet, Guess1, digits);


                if (AB == digits * 10)
                {
                    cout << "The winner is Player1" << endl;
                    P1Win += 1;
                    break;
                }
                else if (AB == -1)
                {
                    round--;
                }
                deride_system(loop_counter);
                loop_counter += 1;
            }
            else
            {
                string Guess2;
                cout << "Player2 round Please Enter the number:" << endl;
                cin >> Guess2;
                int AB = ResultReport(P1NumberSet, Guess2, digits);


                if (AB == digits * 10)
                {
                    cout << "The winner is Player2" << endl;
                    P2Win += 1;
                    break;
                }
                else if (AB == -1)
                {
                    round--;
                }
                deride_system(loop_counter);
                loop_counter += 1;
            }
        }

        cout << "現在P1:P2=" << P1Win << ":" << P2Win << endl;

    } while (P1Win != 2 && P2Win != 2);


    if (P2Win == 2) {
        cout << "本局三戰兩勝制的贏家是P2" << endl;
    }
    else {
        cout << "本局三戰兩勝制的贏家是P1" << endl;
    }

}

/****************************/

int main()
{
    srand(time(0));
    //ClearBoard();



    int choosing_mode;
    while (1)
    {
        cout << "choose mode" << endl;
        cout << "Single Player Mode(input 1)" << endl;
        cout << "Competition Mode (input 2)" << endl;
        cout << "Check ScoreBoard in Single Mode (input 3)\n";
        cout << "Quit Game     (input 0)" << endl;
        cout << "game mode:";
        cin >> choosing_mode;




        if (choosing_mode == 1)
        {
            SinglePlayerMode();
            cout << "Congratulations!!!" << endl;
        }
        else if (choosing_mode == 2) {
            int mod2;
            cout << "請選擇要一戰定勝負(輸入1) 或 三戰兩勝制(輸入2)" << endl;
            cin >> mod2;
            if (mod2 == 1) {
                Competition_Mode();
            }
            else if (mod2 == 2) {
                W2();
            }
            else {
                cout << "白癡嗎" << endl;
            }
        }

        else if (choosing_mode == 3)
        {
            Check_ScoreBoard();
        }



        else if (choosing_mode == 0)
        {
            cout << "thx for playing";
            break;
        }
        else
            cout << "OK\n";
    }




    return 0;
}







