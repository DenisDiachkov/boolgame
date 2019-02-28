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
#include <fstream>

using namespace std;
using namespace sf;
void play(RenderWindow &win);
void restart(RenderWindow &win)
{
    first = false;
    win.close();
    RenderWindow win2(VideoMode(640, 480), "Name");
    play(win2);
}
void play(RenderWindow &win)
{
    setlocale(LC_ALL, "Russian");
    char coinsT[30];
    ///Bool
    Texture tBool;
    tBool.loadFromFile("source/Bool.png");
    Sprite Bool;
    Bool.setTextureRect(IntRect(181*6, 0, 181, 187));
    Bool.setTexture(tBool);
    Bool.setOrigin(Bool.getTextureRect().width, Bool.getTextureRect().height);
    Bool.setPosition(640, 480);


    ///Файл с рекордами
    ofstream fout("source/records.txt");
    ifstream fin("source/records.txt");

    ///Text
    Font font;
    font.loadFromFile("source/font.otf");
    Text Tcoins;
    Tcoins.setFont(font);
    sprintf(coinsT, "%d Очков", coins);
    Tcoins.setString(coinsT);
    Tcoins.setColor(Color(201, 46, 46));
    Tcoins.setPosition(320-Tcoins.getGlobalBounds().width/2, 0);

    unsigned rand_value = 11;
    srand(rand_value);
    Control control;

    ///Камера
    Vector2f coordsWin = win.mapPixelToCoords({0, 0});
    View view({0, 0, win.getSize().x, win.getSize().y});

    ///Карта
    Level _map;
    RectangleShape dark;
    dark.setFillColor(Color(0, 0, 0, 0.3));
    dark.setSize({coordsWin.x + win.getSize().x, coordsWin.y + win.getSize().y});
    dark.setPosition(coordsWin.x + win.getSize().x, coordsWin.y + win.getSize().y);
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


    ///Карта
    MapRandom();
    initMap();
    mapSet(win);
    for(int i = 0; i < MAP_HEIGHT; i++)  cout << Map[i];
    while(win.isOpen())
    {
        ///Очки
        int tcoins = coins;
        if(coins >= 10 && coins <= 20) sprintf(coinsT, "%d Очков", coins);
        else
        if(coins % 10 == 5 || coins % 10 == 6 || coins % 10 == 7 || coins % 10 == 8 || coins % 10 == 9 || coins % 10 == 0) sprintf(coinsT, "%d Очков", coins);
        else if(coins % 10 == 1) sprintf(coinsT, "%d Очко", coins);
        else sprintf(coinsT, "%d Очкa", coins);
        Tcoins.setString(coinsT);

        //if(coinsT > fin.read()) fout.write(coinsT);


        //cout <<coinsT;
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
        fout.close();
        fin.close();
        while(win.pollEvent(event))
        {

            if(event.type == Event::KeyPressed) if(event.key.code == Keyboard::Escape){  mclick.play() ;game_menu(win, spriteArr, _map); mclick.play(); }
            if(event.type == Event::Closed) win.close();
            if(event.type == Event::KeyPressed) if(event.key.code == Keyboard::Tab){ for(int i = 0; i <MAP_HEIGHT; i++) cout << endl <<  Map[i] << endl;  cout << BCount;}
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::F10) restart(win);
        }
        initMap();
        destroy();
        control.Update(win, time);

        if(goBool)
        {
            static float animTime = 0;
            static bool to = true;
            if(to) animTime-=time;
            else animTime+=time;
            if(animTime < -600)
            {
                animTime = -600;
                to = false;
            }
            else if(animTime > 0)
            {
                animTime = 0;
                to = true;
                goBool = false;
            }
            Bool.setTextureRect(IntRect(181*(int)(6 + animTime/100), 0, 180, 187));
        }
        else Bool.setTextureRect(IntRect(181*7, 0, 180, 187));

        win.clear();
        win.draw(background);

        mapSet(win);

        win.setView(view);
        mapDraw(win);
        win.draw(bg);
        win.draw(control.getActiveSprite());
        win.draw(Tcoins);
        win.draw(Bool);
        if(BCount == 0) win.draw(dark);
        win.display();
    }
}

int main()
{
    ///Музыка
    music.openFromFile("source/main.ogg");
    music.play();
    music.setVolume(musicVolume);
    music.setLoop(true);
    unsigned rand_value = 11;
    srand(rand_value);
    RenderWindow win(VideoMode(640, 480), "Name");
    main_menu(win, play);
    return 0;
}
