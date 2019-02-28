#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace sf;
using namespace std;
Texture t[10][3], bgt, backgroundt;
Sprite  sprites[10][3];
Sprite bg, background;
int coins;
bool first = false;
bool goBool = false;
int Count = 0, BCount = 0;
SoundBuffer desBuf;
Sound des;


const int MAP_HEIGHT = 13;
const int MAP_WIDTH = 18;
Sprite spritesgame[MAP_HEIGHT][MAP_WIDTH];
string Map[MAP_HEIGHT] = {
    "999999999999999999",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "900000000000000009",
    "999999999999999999"
};
void initMap()
{
    bgt.loadFromFile("source/bg.png");
    bg.setTexture(bgt);
    bg.setTextureRect(IntRect(0, 0, 640-96-32, 480-96-32));
    backgroundt.loadFromFile("source/background.png");
    background.setTexture(backgroundt);
    background.setTextureRect(IntRect(0, 0, 640, 480));
    background.setPosition(0, 0);
    t[0][0].loadFromFile("source/empty.png");
    t[0][1].loadFromFile("source/HoverEmpty.png");
    t[0][2].loadFromFile("source/follow.png");
    t[1][0].loadFromFile("source/A.png");
    t[1][1].loadFromFile("source/Ahover.png");
    t[1][2].loadFromFile("source/follow.png");
    t[2][0].loadFromFile("source/B.png");
    t[2][1].loadFromFile("source/Bhover.png");
    t[2][2].loadFromFile("source/follow.png");
    t[3][0].loadFromFile("source/Zero.png");
    t[3][1].loadFromFile("source/ZeroHover.png");
    t[3][2].loadFromFile("source/follow.png");
    t[4][0].loadFromFile("source/one.png");
    t[4][1].loadFromFile("source/onehover.png");
    t[4][2].loadFromFile("source/follow.png");
    t[5][0].loadFromFile("source/ask.png");
    t[5][1].loadFromFile("source/askhover.png");
    t[5][2].loadFromFile("source/follow.png");
    t[6][0].loadFromFile("source/bomb.png");
    t[6][1].loadFromFile("source/bombhover.png");
    t[6][2].loadFromFile("source/follow.png");
    t[7][0].loadFromFile("source/kon.png");
    t[7][1].loadFromFile("source/konhover.png");
    t[7][2].loadFromFile("source/follow.png");
    t[8][0].loadFromFile("source/dis.png");
    t[8][1].loadFromFile("source/dishover.png");
    t[8][2].loadFromFile("source/follow.png");
    t[9][0].loadFromFile("source/border.png");
    t[9][1].loadFromFile("source/border.png");
    t[9][2].loadFromFile("source/border.png");
    sprites[0][0].setTexture(t[0][0]);
    sprites[0][1].setTexture(t[0][1]);
    sprites[0][2].setTexture(t[0][2]);
    sprites[1][0].setTexture(t[1][0]);
    sprites[1][1].setTexture(t[1][1]);
    sprites[1][2].setTexture(t[1][2]);
    sprites[2][0].setTexture(t[2][0]);
    sprites[2][1].setTexture(t[2][1]);
    sprites[2][2].setTexture(t[2][2]);
    sprites[3][0].setTexture(t[3][0]);
    sprites[3][1].setTexture(t[3][1]);
    sprites[3][2].setTexture(t[3][2]);
    sprites[4][0].setTexture(t[4][0]);
    sprites[4][1].setTexture(t[4][1]);
    sprites[4][2].setTexture(t[4][2]);
    sprites[5][0].setTexture(t[5][0]);
    sprites[5][1].setTexture(t[5][1]);
    sprites[5][2].setTexture(t[5][2]);
    sprites[6][0].setTexture(t[6][0]);
    sprites[6][1].setTexture(t[6][1]);
    sprites[6][2].setTexture(t[6][2]);
    sprites[7][0].setTexture(t[7][0]);
    sprites[7][1].setTexture(t[7][1]);
    sprites[7][2].setTexture(t[7][2]);
    sprites[8][0].setTexture(t[8][0]);
    sprites[8][1].setTexture(t[8][1]);
    sprites[8][2].setTexture(t[8][2]);
    sprites[9][0].setTexture(t[9][0]);
    sprites[9][1].setTexture(t[9][1]);
    sprites[9][2].setTexture(t[9][2]);
    for(int i = 0; i < MAP_HEIGHT; i++)
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            if(Map[i][j] == '0')
            {
                spritesgame[i][j] = sprites[0][0];
            }
            if(Map[i][j] == '1')
            {
                spritesgame[i][j] = sprites[1][0];
            }
            if(Map[i][j] == '2')
            {
                spritesgame[i][j] = sprites[2][0];
            }
            if(Map[i][j] == '3')
            {
                spritesgame[i][j] = sprites[3][0];
            }
            if(Map[i][j] == '4')
            {
                spritesgame[i][j] = sprites[4][0];
            }
            if(Map[i][j] == '5')
            {
                spritesgame[i][j] = sprites[5][0];
            }
            if(Map[i][j] == '6')
            {
                spritesgame[i][j] = sprites[6][0];
            }
            if(Map[i][j] == '7')
            {
                spritesgame[i][j] = sprites[7][0];
            }
            if(Map[i][j] == '8')
            {
                spritesgame[i][j] = sprites[8][0];
            }
            if(Map[i][j] == '9')
            {
                spritesgame[i][j] = sprites[9][0];
            }

        }


}
void mapSet(RenderWindow &win)
{

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            if(Map[i][j] == '0')
            {

                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '1')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '2')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '3')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '4')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '5')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '6')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '7')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);

            }
            if(Map[i][j] == '8')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);
            }
            if(Map[i][j] == '9')
            {
                spritesgame[i][j].setPosition((j+1)*32, (i+1)*32);
            }
        }
    }
    bg.setPosition(64, 64);
}
void add(){
    srand(time(NULL));
    int r = rand();
    for(int i = 1; i < MAP_HEIGHT-1; i++)
        for(int j = 1; j < MAP_WIDTH-1; j++)
        {
            if(Map[i][j] == '0')
                if(rand() % 100 - 95 > 0)
                {
                    if(r % 3 == 0) Map[i][j] = '7';
                    else if(r % 3 == 1) Map[i][j] = '8';
                    else if (r % 3 == 2) Map[i][j] = '6';
                    r /= 10;
                }
            if(r == 0) r = rand();
        }

}
void mapDraw(RenderWindow &win)
{
    Count =  0;
    BCount = 0;
    for(int i = 0; i < MAP_HEIGHT; i++)
        for(int j = 0; j < MAP_WIDTH; j++)
        {
            win.draw(spritesgame[i][j]);
            if(Map[i][j] == '7' || Map[i][j] == '8')
                Count++;
            if(!(Map[i][j] == '0' || Map[i][j] == '7' || Map[i][j] == '8' || Map[i][j] == '6' || Map[i][j] == '5' || Map[i][j] == '9'))
                BCount++;
        }
    if(Count == 0)
    {
        cout << "YEA";
        add();
    }
}
void MapRandom()
{
    srand(time(NULL));
    for(int i = 1; i < MAP_HEIGHT-1; i++)
        for(int j = 1; j < MAP_WIDTH-1; j++)
        {
            char randchar;
            int it = rand() % 100;
            it = (it*rand()) % 100;
            it = (it*rand()) % 100;


            if(it > 0 && it < 80) it = 0;
            else if(it > 0 && it < 84) it = 1;
            else if(it > 0 && it < 86) it = 2;
            else if(it > 0 && it < 88) it = 3;
            else if(it > 0 && it < 90) it = 4;
            else if(it > 0 && it < 92) it = 5;
            else if(it > 0 && it < 94) it = 6;
            else if(it > 0 && it < 96) it = 7;
            else if(it > 0 && it < 100) it = 8;

            switch(it)
            {
                default: randchar = '0';break;
                case 1: randchar = '1';break;
                case 2: randchar = '2';break;
                case 3: randchar = '3';break;
                case 4: randchar = '4';break;
                case 5: randchar = '5';break;
                case 6: randchar = '6';break;
                case 7: randchar = '7';break;
                case 8: randchar = '8';break;
            }
            cout <<randchar;
            Map[i][j] = randchar;
        }
}
void destroy()
{
    desBuf.loadFromFile("source/des.wav");
    des.setBuffer(desBuf);

    int tcoins = coins;
    for(int i = 0; i < MAP_HEIGHT; i++)
    for(int j = 0; j < MAP_WIDTH; j++){
        ///Конъюкция
        //Y
        if(i!=0 && i!= MAP_HEIGHT-1)
        if((Map[i][j] == '8' && Map[i-1][j] == '3' && Map[i+1][j] != '0' && Map[i+1][j] != '8' && Map[i+1][j] != '7' && Map[i+1][j] != '5' && Map[i+1][j] != '9')
           || ((Map[i][j] == '8' && Map[i+1][j] == '3' && Map[i-1][j] != '0' && Map[i-1][j] != '8' && Map[i-1][j] != '7' && Map[i-1][j] != '5' && Map[i-1][j] != '9')))
        {
            coins+=2;
            des.play();
            Map[i][j] = '3'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[3][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if(Map[i][j] == '8' && Map[i-1][j] == '4' && Map[i+1][j] == '4')
        {
            coins+=2;
            des.play();
            Map[i][j] = '4'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[4][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i-1][j] == '4' &&  Map[i+1][j] == '2')
                ||(Map[i][j] == '8' && Map[i+1][j] == '4' &&  Map[i-1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[2][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i-1][j] == '4' &&  Map[i+1][j] == '1')
                ||(Map[i][j] == '8' && Map[i+1][j] == '4' &&  Map[i-1][j] == '1'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[1][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i-1][j] == '2' && Map[i+1][j] == '1') ||
                (Map[i][j] == '8' && Map[i-1][j] == '1' && Map[i+1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '5'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[5][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i-1][j] == '1' && Map[i+1][j] == '1') ||
                (Map[i][j] == '8' && Map[i-1][j] == '2' && Map[i+1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = Map[i-1][j]; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[(int)(Map[i][j] - '0')][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }


        //X
        if(j!=0 && j!= MAP_WIDTH-1)
        if((Map[i][j] == '8' && Map[i][j-1] == '3' && Map[i][j+1] != '0' && Map[i][j+1] != '8' && Map[i][j+1] != '7' && Map[i][j+1] != '5'  && Map[i][j+1] != '9' )
           || ((Map[i][j] == '8' && Map[i][j+1] == '3' && Map[i][j-1] != '0' && Map[i][j-1] != '8' && Map[i][j-1] != '7' && Map[i][j-1] != '5' && Map[i][j-1] != '9')))
        {
            coins+=2;
            des.play();
            Map[i][j] = '3'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[3][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if(Map[i][j] == '8' && Map[i][j-1] == '4' && Map[i][j+1] == '4')
        {
            coins+=2;
            des.play();
            Map[i][j] = '4'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[4][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i][j-1] == '4' &&  Map[i][j+1] == '2')
                ||(Map[i][j] == '8' && Map[i][j+1] == '4' &&  Map[i][j-1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[2][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i][j-1] == '4' &&  Map[i][j+1] == '1')
                ||(Map[i][j] == '8' && Map[i][j+1] == '4' &&  Map[i][j-1] == '1'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[2][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i][j-1] == '2' && Map[i][j+1] == '1') ||
                (Map[i][j] == '8' && Map[i][j-1] == '1' && Map[i][j+1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '5'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[5][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '8' && Map[i][j-1] == '1' && Map[i][j+1] == '1') ||
                (Map[i][j] == '8' && Map[i][j-1] == '2' && Map[i][j+1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = Map[i][j-1]; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[(int)(Map[i][j] - '0')][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }





        ///Дизъюнкция
        //Y
        if(i!=0 && i!= MAP_HEIGHT-1)
        if((Map[i][j] == '7' && Map[i-1][j] == '4' && Map[i+1][j] != '0' && Map[i+1][j] != '7' && Map[i+1][j] != '8' && Map[i+1][j] != '5' && Map[i+1][j] != '9')
           || ((Map[i][j] == '7' && Map[i+1][j] == '4' && Map[i-1][j] != '0' && Map[i-1][j] != '7' && Map[i-1][j] != '8' && Map[i-1][j] != '5' && Map[i-1][j] != '9')))
        {
            coins+=2;
            des.play();
            Map[i][j] = '4'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[4][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if(Map[i][j] == '7' && Map[i-1][j] == '3' && Map[i+1][j] == '3')
        {
            coins+=2;
            des.play();
            Map[i][j] = '3'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[3][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i-1][j] == '3' &&  Map[i+1][j] == '2')
                ||(Map[i][j] == '7' && Map[i+1][j] == '3' &&  Map[i-1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[2][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i-1][j] == '3' &&  Map[i+1][j] == '1')
                ||(Map[i][j] == '7' && Map[i+1][j] == '3' &&  Map[i-1][j] == '1'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[1][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i-1][j] == '2' && Map[i+1][j] == '1') ||
                (Map[i][j] == '7' && Map[i-1][j] == '1' && Map[i+1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '5'; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[5][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i-1][j] == '1' && Map[i+1][j] == '1') ||
                (Map[i][j] == '7' && Map[i-1][j] == '2' && Map[i+1][j] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = Map[i-1][j]; Map[i-1][j] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[(int)(Map[i][j] - '0')][0];spritesgame[i-1][j] = sprites[0][0];spritesgame[i+1][j] = sprites[0][0];
        }
        //X
        if(j!=0 && j!= MAP_WIDTH-1)
        if((Map[i][j] == '7' && Map[i][j-1] == '4' && Map[i][j+1] != '0' && Map[i][j+1] != '7' && Map[i][j+1] != '8' && Map[i][j+1] != '5'  && Map[i][j+1] != '9' )
           || ((Map[i][j] == '7' && Map[i][j+1] == '4' && Map[i][j-1] != '0' && Map[i][j-1] != '7' && Map[i][j-1] != '8' && Map[i][j-1] != '5' && Map[i][j-1] != '9')))
        {
            coins+=2;
            des.play();
            Map[i][j] = '4'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[4][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if(Map[i][j] == '7' && Map[i][j-1] == '3' && Map[i][j+1] == '3')
        {
            coins+=2;
            des.play();
            Map[i][j] = '3'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[3][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i][j-1] == '3' &&  Map[i][j+1] == '2')
                ||(Map[i][j] == '7' && Map[i][j+1] == '3' &&  Map[i][j-1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '2'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[2][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i][j-1] == '3' &&  Map[i][j+1] == '1')
                ||(Map[i][j] == '7' && Map[i][j+1] == '3' &&  Map[i][j-1] == '1'))
        {
            coins+=2;

            des.play();
            Map[i][j] = '2'; Map[i][j-1] = '0'; Map[i+1][j] = '0';
            spritesgame[i][j] = sprites[1][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i][j-1] == '2' && Map[i][j+1] == '1') ||
                (Map[i][j] == '7' && Map[i][j-1] == '1' && Map[i][j+1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = '5'; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[5][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        else if((Map[i][j] == '7' && Map[i][j-1] == '1' && Map[i][j+1] == '1') ||
                (Map[i][j] == '7' && Map[i][j-1] == '2' && Map[i][j+1] == '2'))
        {
            coins+=2;
            des.play();
            Map[i][j] = Map[i][j-1]; Map[i][j-1] = '0'; Map[i][j+1] = '0';
            spritesgame[i][j] = sprites[(int)(Map[i][j] - '0')][0];spritesgame[i][j-1] = sprites[0][0];spritesgame[i][j+1] = sprites[0][0];
        }
        ///БОМБЫ
        bool exp;
        if(Map[i][j] == '6')
        {
            for(int q = i-1; q <= i+1; q++)
               for(int w = j-1; w<=j+1; w++)
                if(Map[q][w]!='9' && Map[q][w]!='6' && Map[q][w]!='0')
                {
                    coins++;
                    exp = true;
                    Map[q][w] = '0';
                    spritesgame[q][w] = sprites[0][0];
                    if(q == i && w == j && first)
                    {
                        Map[q][w] = '6';
                        spritesgame[q][w] = sprites[6][0];
                    }

                }
                else if(exp && Map[q][w] =='6')
                {
                    coins++;
                    Map[q][w] = '0';
                    spritesgame[q][w] = sprites[0][0];
                }
        }
        ///Знак вопроса
        //if()

    }
    if(!first) coins = 0;
        first = true;

}
#endif // MAP_H
