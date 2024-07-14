#include "Game.h"

using namespace sf;

int main()
{
    // create the window
    RenderWindow window(VideoMode(800, 600), "First project", Style::Default);
    CircleShape shape(100.f);
    //shape.setFillColor(Color::Green);

    Game game(&window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();


        }

        

        game.Update();
        game.Draw();

        //// clear the window with black color
        //window.clear(Color::Black);
        //window.draw(shape);

        //// end the current frame
        //window.display();
    }

    return 0;
}