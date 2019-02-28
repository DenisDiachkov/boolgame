#include <iostream>
#include "include/Level.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "View.h"
#include "Entity.h"
#include "map.h"
#include <stdlib.h>
#include <time.h>
#include "control.h"

using namespace std;
using namespace sf;


void play(RenderWindow &win)
{
    unsigned rand_value = 11;
    srand(rand_value);
    Control control;

    ///Камера
    View view({0, 0, win.getSize().x, win.getSize().y});

    ///Карта
    Level _map;
    _map.LoadFromFile("source/map.tmx");
    vector<Sprite> spriteArr;
    vector<Object> obj;
    obj = _map.GetAllObjects();

    ///Звуки
    SoundBuffer h, c;
    h.loadFromFile("source/Mhover.wav");
    c.loadFromFile("source/Mclick.wav");
    Sound mhover(h);
    Sound mclick(c);

    ///Время
    Clock clock;

    ///Объекты
    Entity ent("source/gang.png", {0, 0, 64, 64}, 100, 100);
    //spriteArr.push_back(ent.sprite);

    MapRandom();
    initMap();
    mapSet(win);
    for(int i = 0; i < MAP_HEIGHT; i++)  cout << Map[i];
    while(win.isOpen())
    {
        ///Время
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time/=800;
        Event event;

        ///Координаты мыши
        Vector2f c = win.mapPixelToCoords(Mouse::getPosition(win));
        //system("cls");
        //cout << c.x << ":"<<c.y << endl;
        //cout << obj[0].rect.left << ":"<< obj[0].rect.top << endl;
        while(win.pollEvent(event))
        {

            if(event.type == Event::KeyPressed) if(event.key.code == Keyboard::Escape){  mclick.play() ;game_menu(win, spriteArr, _map); mclick.play(); }
            if(event.type == Event::Closed) win.close();

        }
        control.Update(win, time);
        win.clear();
        mapSet(win);
        win.setView(view);
        mapDraw(win);
        win.draw(control.getActiveSprite());
        win.draw(bg);
        win.draw(control.getBool());
        win.display();
    }
}

int main()
{
    ///Музыка
    Music music;
    music.openFromFile("source/main.ogg");
    music.play();
    unsigned rand_value = 11;
    srand(rand_value);
    RenderWindow win(VideoMode(640, 480), "Name");
    main_menu(win, play);
    return 0;
}
