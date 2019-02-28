#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"
using namespace std;
using namespace sf;

class Control
{
private:

    SoundBuffer expBuf, getBuf, setBuf, askBuf;
    Sound exp, get, set, ask;

    bool click = false;
    Sprite ActiveSprite;
    void hover(RenderWindow &win)
    {
        if(!click)
        {
            Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
            for(int i = 0; i < MAP_HEIGHT; i++)
            for(int j = 0; j < MAP_WIDTH; j++)
            {
                for(int k = 0; k < 9; k++)
                if(spritesgame[i][j].getTexture() == sprites[k][1].getTexture() || spritesgame[i][j].getTexture() == sprites[k][2].getTexture())
                {
                    spritesgame[i][j] = sprites[k][0];
                    spritesgame[i][j].setPosition(j*32 + 32, i*32+32);
                }
                if(FloatRect(j*32+32, i*32+32, 32, 32).contains(c))
                for(int k = 0; k < 9; k++)
                    if(spritesgame[i][j].getTexture() == sprites[k][0].getTexture())
                    {
                            spritesgame[i][j] = sprites[k][1];
                            spritesgame[i][j].setPosition(j*32 + 32, i*32+32);
                    }
            }
        }
    }
    void move(RenderWindow &win)
    {
        static bool done = false;
        Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
        if(Mouse::isButtonPressed(Mouse::Left))
            click = true;
        else
            click = false;

        if(click)
        {
            //Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
            for(int i = 0; i < MAP_HEIGHT; i++)
            for(int j = 0; j < MAP_WIDTH; j++)
            for(int k = 0; k < 9; k++)
            if((spritesgame[i][j].getTexture() == sprites[k][1].getTexture() || done) && Map[i][j] != '0')
            {

                if(!done)//j
                {
                    get.play();
                    ActiveSprite = spritesgame[i][j];
                    spritesgame[i][j] = sprites[0][0];
                    Map[i][j] = '0';
                }
                done = true;

                ActiveSprite.setOrigin(16, 16);
                if(c.x > 32 && c.x < MAP_WIDTH*32 && c.y > 32 && c.y < MAP_HEIGHT*32)ActiveSprite.setPosition(c);
            }
        }
        else if((int)(c.y/32) - 1 > 0 && (int)(c.y/32) - 1 < MAP_HEIGHT && (int)(c.x/32) - 1 > 0 && (int)(c.x/32) - 1 < MAP_WIDTH)
        if(!click && done && Map[(int)(c.y/32) - 1][(int)(c.x/32) - 1] == '0')
        {
            if(ActiveSprite.getTexture() == sprites[6][1].getTexture()) goBool = true;
            set.play();
            ActiveSprite.setPosition((int)(c.x/32)*32 + 16, (int)(c.y/32)*32 + 16);
            for(int k = 0; k < 9; k++)
                if(sprites[k][1].getTexture() == ActiveSprite.getTexture())
                {
                    spritesgame[(int)(c.y/32) - 1][(int)(c.x/32) - 1] = sprites[k][0];
                    ActiveSprite = sprites[k][0];
                    Map[(int)(c.y/32) - 1][(int)(c.x/32) - 1] = (char)(k + '0');
                    if(Map[(int)(c.y/32) - 1][(int)(c.x/32) - 1] == '6') exp.play();
                }
            done = false;
        }
        else if(!click && done && Map[(int)(c.y/32) - 1][(int)(c.x/32) - 1] != '0' && ActiveSprite.getTexture() == sprites[5][1].getTexture())
        {
            ask.play();
            coins++;
            ActiveSprite.setPosition((int)(c.x/32)*32 + 16, (int)(c.y/32)*32 + 16);
            spritesgame[(int)(c.y/32) - 1][(int)(c.x/32) - 1] = sprites[0][0];
            ActiveSprite = sprites[0][0];
            Map[(int)(c.y/32) - 1][(int)(c.x/32) - 1] = '0';
            done = false;
        }

    }

public:
    Control()
    {
        expBuf.loadFromFile("source/exp.wav");
        getBuf.loadFromFile("source/get.wav");
        setBuf.loadFromFile("source/set.wav");
        askBuf.loadFromFile("source/ask.wav");


        exp.setBuffer(expBuf);
        get.setBuffer(getBuf);
        set.setBuffer(setBuf);
        ask.setBuffer(askBuf);
    }
    Sprite& getActiveSprite()
    {
        return ActiveSprite;
    }
    void Update(RenderWindow &win, float time)
    {
        hover(win);
        move(win);
    }

};
