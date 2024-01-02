#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdio>
using namespace std;

class Tetris
{
private:
    int rank;               //游戲難度等級
    int score;              // 得分
    int id;                 //圖形ID
    int point[2];           //兩基點
    int top;                    //最高點高度
public:
    Tetris();
    void Welocme();         //首界面
    void DrawMap();         //游戲界面
    void SetColor(int);     //控制顏色
    void Draw(int, int, int);       //畫圖形
    void Run();             //運行游戲
    void ReDraw(int, int, int);         //清除圖形
    bool Judge(int, int, int);
    void Turn(int, int);                //旋轉
    void Updata();              // 更新界面
    void Pause();               //游戲暫停
    void Input_score();
};

const int sharp[15][8] =					//組成圖形的各個點的各個坐標，先縱后橫
{
{0,0,1,0,2,0,3,0},
{ 0,0,0,1,0,2,0,3},
{ 0,0,1,0,0,1,1,1},

{ 0,0,1,0,1,1,1,2}, //反l 
{ 0,1,1,1,2,0,2,1},// --,
{ 0,0,0,1,0,2,1,2},//倒l 
{ 0,0,0,1,1,0,2,0},// '--

{ 0,0,1,0,2,0,1,1},// -|-
{ 0,0,0,1,0,2,1,1},// |-
{ 1,0,0,1,1,1,2,1},// -|
{ 0,1,1,0,1,1,1,2},// T


{ 0,0,0,1,1,1,1,2},
{ 0,1,1,0,1,1,2,0},
{ 0,1,0,2,1,0,1,1},
{ 0,0,1,0,1,1,2,1}
};

const int high[15] = { 4, 1, 2, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3 };
int map[28][16];

#define a1  0			//條形
#define a2  1

#define b 2					// 方塊

#define c1 3					//L形
#define c2 4
#define c3 5
#define c4 6

#define d1 7					//T形
#define d2 8 
#define d3 9
#define d4 10 

#define e1 11				//閃電1形
#define e2 12

#define f1 13				//閃電2形
#define f2 14

Tetris::Tetris()				//建構式， 初始化各個值
{
    point[0] = 0;
    point[1] = 5;
    score = 0;
    top = 25;
}

void Tetris::Turn(int num, int r)				//旋轉函式
{
    switch (num)
    {
    case a1: id = a2; break;                    //條形互換
    case a2: id = a1; break;

    case b: id = b; break;                  //方塊無法旋轉

    case c1: if (r == 0) { id = c2; break; }
           else { id = c4; break; }   //各種L形互換
    case c2: if (r == 0) { id = c3; break; }
           else { id = c1; break; }
    case c3: if (r == 0) { id = c4; break; }
           else { id = c2; break; }
    case c4: if (r == 0) { id = c1; break; }
           else { id = c3; break; }

    case d1: if (r == 0) { id = d2; break; }
           else { id = d4; break; }                   //各種T形互換
    case d2: if (r == 0) { id = d3; break; }
           else { id = d1; break; }
    case d3: if (r == 0) { id = d4; break; }
           else { id = d2; break; }
    case d4: if (r == 0) { id = d1; break; }
           else { id = d3; break; }

    case e1: id = e2; break;                    //兩種閃電形互換
    case e2: id = e1; break;

    case f1: id = f2; break;
    case f2: id = f1; break;
    }
}

void SetPos(int i, int j)			//控制游標位置， 列， 行
{
    COORD pos = { i, j };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetris::Pause()				// 暫停函式
{
    SetPos(32, 10);
    cout << "游戲暫停!" << endl;
    SetPos(30, 11);
    cout << "你的分數為 " << score;
    char temp;
    while (1)
    {
        while (1)
        {
            if (_kbhit())
            {
                temp = _getch();
                break;
            }
        }
        if (temp == 27)
            break;
    }
    SetPos(32, 10);                 // 清除暫停時顯示的資訊
    cout << "         ";
    SetPos(30, 11);
    cout << "              ";
}

void Tetris::Updata()					//更新函式
{
    int i, flag;
    int nx, ny;
    for (i = 0; i < 4; i++)
    {
        nx = point[0] + sharp[id][i * 2];
        ny = point[1] + sharp[id][i * 2 + 1];
        SetPos((ny + 1) * 2, nx + 1);
        SetColor(0);
        cout << "■";
        map[nx][ny] = 1;                    //界面各個點是否為空的更新
    }

    if (point[0] < top)
        top = point[0];                 //最高點的更新

    for (i = point[0]; i < point[0] + high[id]; i++)            //消除行
    {
        flag = 1;
        for (int j = 0; j < 13; j++)                    //判定某一行是否滿， 用flag來標記gai
            if (map[i][j] == 0)
                flag = 0;
        if (flag == 1)
        {
            for (int k = i; k >= top; k--)
            {
                for (int p = 0; p < 13; p++)//gai
                {
                    map[k][p] = map[k - 1][p];
                    SetPos((p + 1) * 2, k + 1);
                    if (map[k][p] == 1)
                        cout << "■";
                    else cout << "  ";

                }
            }
            score += 100;
            Input_score();
        }
    }
}

void Tetris::Input_score()
{
    SetColor(3);
    SetPos(30, 19);
    cout << "得分: " << score;
}

void Tetris::Welocme()			//歡迎界面
{
    SetColor(1);
    char x;
    while (1)
    {
        system("cls");
        cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
        cout << "		俄羅斯方塊		" << endl;
        cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
        cout << "		操作方式：" << endl;
        cout << "		Z - 逆轉" << endl;
        cout << "                X - 順轉" << endl;
        cout << "		↓ - 加速下移" << endl;
        cout << "		← - 左移" << endl;
        cout << "		→ - 右移" << endl;
        cout << "		sapce - 順降" << endl;
        cout << "		esc - 暫停" << endl;
        //cout << "     author: YouYang_Wang\n";
        cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
        cout << "■ 按1—5選擇難度■" << endl;
        SetPos(20, 12);
        x = getchar();
        if (x <= '9' && x >= '0')
        {
            rank = x - '0';
            break;
        }
    }
}

void Tetris::SetColor(int color_num)			//設定顏色
{
    int n = 0x0f;
    switch (color_num)
    {
    case 0: n = 0x03; break;

    case 1: n = 0x0F; break;
    case 2: n = 0x09; break;
    case 3: n = 0x0B; break;
    case 4: n = 0x0A; break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

void Tetris::DrawMap()				//畫游戲時界面
{
    int i;
    SetColor(0);

    for (i = 0; i < 24; i++)        //寬24格
    {
        SetPos(i * 2, 0);
        cout << "■";
        SetPos(i * 2, 26);
        cout << "■";
    }

    for (i = 0; i < 26; i++)        //高26格
    {
        SetPos(0, i);
        cout << "■";
        SetPos(28, i);
        cout << "■";
        SetPos(46, i);
        cout << "■";
    }

    for (i = 14; i < 24; i++)
    {
        SetPos(i * 2, 16);
        cout << "■";
    }

    SetColor(2);
    Input_score();
    SetPos(30, 21);
    cout << "難度等級: " << rank;
    SetPos(32, 2);
    cout << "下一圖形";
}

void Tetris::Draw(int x, int y, int num)				//畫圖形
{
    int nx, ny;

    for (int i = 0; i < 4; i++)
    {
        nx = x + sharp[num][2 * i];
        ny = y + sharp[num][2 * i + 1];
        SetPos((ny + 1) * 2, nx + 1);
        SetColor(i + 1);
        cout << "■";
    }
}

void Tetris::ReDraw(int x, int y, int num)				//為更新圖形的位置清除圖形
{
    int nx, ny;

    for (int i = 0; i < 4; i++)
    {
        nx = x + sharp[num][2 * i];
        ny = y + sharp[num][2 * i + 1];
        SetPos((ny + 1) * 2, nx + 1);
        cout << "  ";
    }
}

bool Tetris::Judge(int x, int y, int num)				//判定在x, y 所指位置是否可畫編號為
{                                                                           //num 的圖形， 若不可畫則反回true
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + sharp[num][2 * i];
        ny = y + sharp[num][2 * i + 1];
        if (!(nx < 25 && nx >= 0 && ny < 13 && ny >= 0 && !map[nx][ny]))
            return true;
    }
    return false;
}

void Tetris::Run()					//運行游戲
{
    int next_id;
    srand((int)time(0));

    id = rand() % 15;
    next_id = rand() % 15;

    Draw(point[0], point[1], id);
    Draw(5, 16, next_id);

    int count;
    if (rank == 1)
    {
        count = 150;
    }
    else if (rank == 2)
    {
        count = 100;
    }
    else if (rank == 3)
    {
        count = 50;
    }
    else if (rank == 4)
    {
        count = 25;
    }
    else if (rank == 5)
    {
        count = 10;
    }
    else
        count = 5;
    int i = 0;  //不同等級對應不同count

    while (1)
    {
        if (!(i < count))               //i 與 count 用于控制時間
        {
            i = 0;
            if (Judge(point[0] + 1, point[1], id))          //在某一位置不能下落的話
            {
                Updata();
                id = next_id;

                ReDraw(5, 16, next_id);
                next_id = rand() % 15;

                point[0] = 0; point[1] = 5;
                Draw(point[0], point[1], id);
                Draw(5, 16, next_id);

                if (Judge(point[0], point[1], id))
                {
                    system("cls");
                    SetPos(20, 10);
                    cout << "游戲結束！" << endl;
                    SetPos(20, 11);
                    cout << "你的分數為 " << score << endl;
                    system("pause");
                    exit(1);
                }
            }
            else                    //繼續下落awa
            {
                ReDraw(point[0], point[1], id);
                point[0]++;
                Draw(point[0], point[1], id);
            }
        }

        if (_kbhit())               //鍵盤輸入值時 
        {
            int key, key2;
            key = _getch();

            if (key == 32) //按空白鍵 
            {
                int temp = id;
                while (!Judge(point[0] + 3, point[1], id))
                {
                    ReDraw(point[0], point[1], id);
                    point[0] += 2;
                    Draw(point[0], point[1], id);
                }
            }



            if (key == 90)          //按z鍵時
            {
                int temp = id;
                Turn(id, 1);
                if (Judge(point[0], point[1], id))
                    id = temp;
                ReDraw(point[0], point[1], temp);
                Draw(point[0], point[1], id);
            }
            if (key == 88)          //按x鍵時
            {
                int temp = id;
                Turn(id, 0);
                if (Judge(point[0], point[1], id))
                    id = temp;
                ReDraw(point[0], point[1], temp);
                Draw(point[0], point[1], id);
            }
            if (key == 224)
            {
                key2 = _getch();


                if (key2 == 80)             //按向下方向鍵時
                {
                    if (!Judge(point[0] + 2, point[1], id))
                    {
                        ReDraw(point[0], point[1], id);
                        point[0] += 2;
                        Draw(point[0], point[1], id);
                    }
                }
                else if (key2 == 75)                //按向左方向鍵時
                {
                    if (!Judge(point[0], point[1] - 1, id))
                    {
                        ReDraw(point[0], point[1], id);
                        point[1]--;
                        Draw(point[0], point[1], id);
                    }
                }
                else if (key2 == 77)                    //按向右方向鍵時
                {
                    if (!Judge(point[0], point[1] + 1, id))
                    {
                        ReDraw(point[0], point[1], id);
                        point[1]++;
                        Draw(point[0], point[1], id);
                    }
                }
            }
            else if (key == 27)                 // 按下空格暫停
                Pause();
        }

        Sleep(1);       //等待1毫秒
        i++;                //控制下落間隔
    }
}

int main()
{
    Tetris game;
    game.Welocme();
    system("cls");              //清除歡迎界面
    game.DrawMap();
    game.Run();
    system("pause");
}