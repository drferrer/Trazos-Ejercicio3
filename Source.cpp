#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);

    Clock clock;

    Texture t;
    t.loadFromFile("textures/1.png");
    Texture t2;
    t2.loadFromFile("textures/2.png");
    Texture t3;
    t3.loadFromFile("textures/3.png");
    Texture t4;
    t4.loadFromFile("textures/4.png");

    World a;
    a.init(100, 20, t);
    World b;
    b.init(300, 20, t2);
    World c;
    c.init(100, 200, t3);
    World d;
    d.init(300, 200, t4);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                auto data = event.key;
                a.onkey(data);
                
            }
        }

        window.clear(Color(10, 10, 100, 255));
        a.form(window);
        b.form(window);
        c.form(window);
        d.form(window);

        float time = clock.restart().asSeconds();
        a.update(time);
        /*b.update(time);
        c.update(time);         
        d.update(time);*/
        window.display();
    }
    return 0;
}