#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void viewmove(View &view, float time)
{
    float viewmoveSpeed;
    viewmoveSpeed = 1*view.getSize().x/1000;

    if(Keyboard::isKeyPressed(Keyboard::A)) view.move(-viewmoveSpeed*time, 0);
    if(Keyboard::isKeyPressed(Keyboard::D)) view.move(viewmoveSpeed*time, 0);
    if(Keyboard::isKeyPressed(Keyboard::W)) view.move(0, -viewmoveSpeed*time);
    if(Keyboard::isKeyPressed(Keyboard::S)) view.move(0, viewmoveSpeed*time);
}
void viewzoom(View &view, float time)
{
    if(view.getSize().x > 100)
        if(Keyboard::isKeyPressed(Keyboard::Equal)) view.zoom(0.99f);

    if(view.getSize().x < 2048)
        if(Keyboard::isKeyPressed(Keyboard::Dash)) view.zoom(1.01f);
}
void viewcontrol(View &view, float time)
{
    viewmove(view, time);
    viewzoom(view, time);
}
