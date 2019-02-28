#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>


Texture t[10][3], bgt;
Sprite  sprites[10][3];
Sprite bg;

using namespace sf;
using namespace std;
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
    bg.setPosition(32, 32);
}
void mapDraw(RenderWindow &win)
{
     for(int i = 0; i < MAP_HEIGHT; i++)
        for(int j = 0; j < MAP_WIDTH; j++)
            win.draw(spritesgame[i][j]);
}
void MapRandom()
{
    srand(time(NULL));
    for(int i = 1; i < MAP_HEIGHT-1; i++)
        for(int j = 1; j < MAP_WIDTH-1; j++)
        {
            char randchar;
            int it = rand() % 10;
            it = (it*rand()) % 10;

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
#endif // MAP_H
