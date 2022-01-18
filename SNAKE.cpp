#include <iostream>
#include <conio.h> // getch()
#include <cstdlib> // ststem("cls")
#include <time.h> // srand(time)(NULL));
#include <windows.h> //sleep()

int width, height, speed;
int up, down, lef, righ;
int snakeXcoord, snakeYcoord;
int foodXcoord, foodYcoord;
int key;
int length=3, history_of_coordX[10000], history_of_coordY[10000];
int ntail=0;
char rd=188, ru=187, lu=201, ld=200, horizontal=205, vertical=186;
char direction='r'; //r - righ, l - lef, u - up, d - down
char board[35][35];
/*  board[0][0], board[1][0], board[2][0], board[3][0], board[4][0], board[5][0].
    board[0][1], board[1][1], board[2][1], board[3][1], board[4][1], board[5][1].
    board[0][2], board[1][2], board[2][2], board[3][2], board[4][2], board[5][2].
    .
    .
    board[0][34],
*/

// x - board is empty, w - snake is on a board, j - food


void notify(int &x)
{
    std::cout << "Come on I said 5 to 35." << std::endl;
    std::cout << "Your last chance" << std::endl;
    std::cin >> x;
    if (x < 5 || x > 35) x = 15;
}

void setup()
{
    std::cout <<"SNAKE GAME" << std::endl <<std::endl;
   std::cout << "Set board width from 5 to 35:" << std::endl;
    std::cin >> width;
    if (width < 5 || width > 35) notify(width);

    std::cout << "Set board height from 5 to 35:" << std::endl;
    std::cin >> height;
    if (height < 5 || height > 35) notify(height);

    std::cout << "Set speed 1 to 10" << std::endl;
    std::cin >> speed;
    if(speed < 1) speed = 1;
    else if(speed > 10) speed = 10;

    std::cout << "Press buttons you want to play" << std::endl;
    std::cout << "up" << std::endl;
    up =  getch();
    if(up==224) up+=getch();
    else if(up==0) up-=getch();

    std::cout << "down" << std::endl;
    down = getch();
    if(down==224) down=down+getch();
    else if(down==0) down-=getch();

    std::cout << "left" << std::endl;
    lef = getch();
    if(lef==224) lef+=getch();
    else if(lef==0) lef-=getch();

    std::cout << "right" << std::endl;
    righ = getch();
    if(righ==224)righ+=getch();
    else if(righ==0)righ-=getch();

}

void logic()
{
    // nadajemy wartosci "p" tab board

    for(int i = 0; i  < height ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            board[j][i]='x';
        }
    }
    srand(time(NULL)); //generator losowania
    //losowanie pola dla weza

    snakeXcoord=rand()%width;
    snakeYcoord=rand()%height;

    board[snakeXcoord][snakeYcoord]='w';

    do{     //wykonuj....
                foodXcoord=rand()%width;
                foodYcoord=rand()%height;
                //...dopóki board wylosowane nie jest puste
            }while(board[foodXcoord][foodYcoord]!='x');

            board[foodXcoord][foodYcoord]='j';


}

void draw()
{
    //rysowanie planszy--------------------------------

    system("cls");// oczyszczanie ekranu
        //gorna ramka
        std::cout << lu;
        for(int i = 0; i < width; i++)
        {
            std::cout << horizontal << horizontal;
        }
        std::cout << ru;

        for(int i = 0; i < height; i++)
        {
            std::cout << std::endl << vertical; // lewa ramka
            for(int j = 0; j < width; j++)
            {
                if(board[j][i]=='x') std::cout << "  ";
                if(board[j][i]=='w') std::cout << " o";
                if(board[j][i]=='j') std::cout << " x";
            }
            std::cout << vertical; // prawa ramka

        }

        std::cout << std::endl;
        //dolna ramka
        std::cout << ld;
        for(int i = 0; i < width; i++)
        {
            std::cout << horizontal << horizontal;
        }
        std::cout << rd;
        Sleep(1000/speed); // czekaj

}
void input(){

        if(kbhit()) //jesli zostanie nacisniety key
        {
            key=getch();
            if(key==224) {key+=getch();}
            else if(key==0) {key-=getch();}

            if(key==up) {direction='u';}
            else if(key==down) {direction='d';}
            else if(key==lef) {direction='l';}
            else {direction='r';}

        }
           }


void moves() {

         if(direction=='d') {snakeYcoord++;}
         else if(direction=='u') {snakeYcoord--;}
         else if(direction=='l') {snakeXcoord--;}
         else {snakeXcoord++;}



        //przechodzenie przez sciany
        if(snakeXcoord==width) {snakeXcoord=0;}
        else if(snakeXcoord==-1) {snakeXcoord=width-1;}
        else if(snakeYcoord==height) {snakeYcoord=0;}
        else if(snakeYcoord==-1) {snakeYcoord=height-1;}

}
void logic2() {
                     // co jesli zje jedzenie
        if(board[snakeXcoord][snakeYcoord]=='j')
        {
            length++;
                    //losowanie pola dla jedzenia
            do{
                foodXcoord=rand()%width;
                foodYcoord=rand()%height;
                //...dopoki board wylosowane nie jest puste
            }while(board[foodXcoord][foodYcoord]!='x');

            board[foodXcoord][foodYcoord]='j';
        }
        else //kasowanie ogona

            board[history_of_coordX[ntail-length]][history_of_coordY[ntail-length]]='x';

            board[snakeXcoord][snakeYcoord]='w';
}


int main()
{
    setup();
    logic();

    //rozpoczecie gry
    for(;;)
    {
        ntail++;
        history_of_coordX[ntail]=snakeXcoord;
        history_of_coordY[ntail]=snakeYcoord;

    draw();
    input();
    moves();
                  //co jesli wpadnie w siebie
        if(board[snakeXcoord][snakeYcoord]=='w')
        {
            std::cout << std::endl << "YOU LOST :(    score: " << length+10;
            break;
        }
    logic2();


    }//koniec petli for(;;)

    getch();
    return 0;
}


