#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"
using namespace std;
using namespace sf;

class Control
{
private:
    Texture bt;

    Sprite sprite;



    bool goBool = false;;
    Sprite ActiveSprite;
    void hover(RenderWindow &win)
    {
        if(!Mouse::isButtonPressed(Mouse::Left))
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
        if(Mouse::isButtonPressed(Mouse::Left))
        {

            Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
            for(int i = 0; i < MAP_HEIGHT; i++)
            for(int j = 0; j < MAP_WIDTH; j++)
            for(int k = 0; k < 9; k++)
            if(spritesgame[i][j].getTexture() == sprites[k][1].getTexture())
            {
                done = true;
                ActiveSprite = spritesgame[i][j];
                ActiveSprite.setPosition(c);
            }
        }
        else if(done)
        {
            Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
            ActiveSprite.setPosition((int)(c.x/32)*32, (int)(c.y/32)*32);
            cout << endl << (int)(c.x/32) - 2 << ":" << (int)(c.y/32) - 2;
            for(int k = 0; k < 9; k++)
                if(sprites[k][1].getTexture() == ActiveSprite.getTexture())
                {
                    Map[(int)(c.y/32) - 2][(int)(c.x/32) - 2] = (char)(k+'0');
                    cout << endl <<(char)(k+'0');
                }
            done = false;
            goBool = true;
        }
    }

    void Bool(RenderWindow& win, float time)
    {
        if(goBool)
        {
            static bool sp = false;
            static bool to = false;
            static bool from = false;
            bt.loadFromFile("source/bool.png");
            if(!sp)
            {
                sprite.setTextureRect(IntRect(181*6, 0, 0, 187));
                sp = true;
            }

            sprite.setTexture(bt);
            static float animTime = 0;
            if(!to) animTime-=time;
            if(animTime < -7) { animTime+=7; to = true;}
            if(to) animTime += time;
            if(animTime > 7) { animTime -= 7; from = true; goBool = false;}
            sprite.setTextureRect(IntRect(181*(int)(animTime), 0, 0, 187));
        }
    }
public:
    Sprite& getBool()
    {
        return sprite;
    }
    Sprite& getActiveSprite()
    {
        return ActiveSprite;
    }
    void Update(RenderWindow &win, float time)
    {
        hover(win);
        move(win);
        Bool(win, time);
    }

};
