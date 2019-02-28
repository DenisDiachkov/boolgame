#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <random>
using namespace std;
using namespace sf;
class Entity
{
private:
    Texture tex;
    Sprite sprite;
public:

    Entity(String src, IntRect spriteRect, int x, int y)
    {
        tex.loadFromFile(src);
        sprite.setTexture(tex);
        sprite.setTextureRect(spriteRect);
        sprite.setPosition(x, y);
    }
    Sprite &getSprite() {return sprite;}
};

#endif // ENTITY_H
